package controller;

import exceptions.ExpEvalException;
import exceptions.StmtExeException;
import exceptions.UtilsException;
import model.ProgramState;
import model.statement.IStatement;
import model.utils.IList;
import model.utils.IStack;
import model.value.RefValue;
import model.value.Value;
import repository.IRepository;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Controller {
    IRepository repo;
    boolean displayFlag = false;
    ExecutorService executorService;

    public Controller(IRepository repo) {
        this.repo = repo;
    }

    public void setDisplayFlag(boolean displayFlag) {
        // displayFlag is a boolean that indicates if the program should display the steps
        this.displayFlag = displayFlag;
    }

    public void oneStepForAllPrograms(List<ProgramState> programStates) throws InterruptedException {
        /* before the execution, print the PrgState List into the log file:
        - get the list of callables (each callable is a program state); map each program state to a callable; collect the list of callables
        - run concurrently the callables; get the list of new created program states; get the program state
        - remove the null program states; collect the list of new program states
        - add the new program states to the list of existing program states */

        programStates.forEach(programState -> {
            try {
                repo.logPrgStateExec(programState);
                display(programState);
            } catch (IOException | UtilsException e) {
                System.out.println(e.getMessage());
            }
        });

        List<Callable<ProgramState>> callList = programStates.stream()
                .map((ProgramState p) -> (Callable<ProgramState>) (p::oneStep))
                .collect(Collectors.toList());

        List<ProgramState> newProgramList = executorService.invokeAll(callList).stream()
                .map(future -> {
                    try {
                        return future.get();
                    } catch (ExecutionException | InterruptedException e) {
                        System.out.println(e.getMessage());
                    }
                    return null;
                })
                .filter(Objects::nonNull)
                .collect(Collectors.toList());

        programStates.addAll(newProgramList);
        //conservativeGarbageCollector(programStates);
        //System.out.println(newProgramList);1

        programStates.forEach(programState -> {
            try {
                repo.logPrgStateExec(programState);
                display(programState);
            } catch (IOException | UtilsException e) {
                System.out.println(e.getMessage());
            }
        });

        repo.setProgramStates(programStates);
    }

    public List<Integer> getAddrFromSymTable(Collection<Value> symTableValues) {
        return symTableValues.stream().filter(v -> v instanceof RefValue).map(v -> {
            RefValue v1 = (RefValue) v;
            return v1.getAddress();
        }).collect(Collectors.toList());
    }

    public List<Integer> getAddrFromHeap(Collection<Value> heapValues) {
        return heapValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {
                    RefValue v1 = (RefValue) v;
                    return v1.getAddress();
                }).collect(Collectors.toList());
    }

    public Map<Integer, Value> safeGarbageCollector(List<Integer> symTableAddr, List<Integer> heapAddr, Map<Integer, Value> heap) {
        return heap.entrySet().stream()
                .filter(e -> (symTableAddr.contains(e.getKey()) || heapAddr.contains(e.getKey())))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public List<ProgramState> removeCompletedPrograms(List<ProgramState> inPrgList) {
        return inPrgList.stream().filter(p -> !p.isNotCompleted()).collect(Collectors.toList());
    }

    public void conservativeGarbageCollector(List<ProgramState> programStates) {
        /* removes the unused values from the heap:
        - get the list of symbol table addresses; get the list of addresses from the symbol table values
        - map each list of addresses to a stream; concatenate the streams; collect the list of addresses
        - get the list of heap addresses; update the heap */

        List<Integer> symTableAddresses = Objects.requireNonNull(programStates.stream()
                        .map(p -> getAddrFromSymTable(p.getSymTable().values()))
                        .map(Collection::stream)
                        .reduce(Stream::concat).orElse(null))
                .collect(Collectors.toList());

        programStates.forEach(p -> {
            p.getHeap().setContent((HashMap<Integer, Value>) safeGarbageCollector(symTableAddresses, getAddrFromHeap(p.getHeap().getContent().values()), p.getHeap().getContent()));
        });
    }

    public void allSteps() throws InterruptedException {
         /* executes all the steps and displays the current state of the program:
        - create a new executor service with 2 threads; get the list of program states from the repository
        - while there are program states in the list; execute one step for all the program states
        - get the list of program states from the repository; shutdown the executor service */

        executorService = Executors.newFixedThreadPool(2);
        List<ProgramState> programStatesList = removeCompletedPrograms(repo.getProgramStates());

        while (!programStatesList.isEmpty()) {
            oneStepForAllPrograms(programStatesList);
            conservativeGarbageCollector(programStatesList);
            programStatesList = removeCompletedPrograms(repo.getProgramStates());
        }

        executorService.shutdownNow();
        repo.setProgramStates(programStatesList);
    }

    public void oneStep() throws  InterruptedException {
        executorService = Executors.newFixedThreadPool(2);
        List<ProgramState> programStates = removeCompletedPrograms(repo.getProgramStates());
        oneStepForAllPrograms(programStates);
        conservativeGarbageCollector(programStates);
        //programStates = removeCompletedPrg(repository.getProgramList());
        executorService.shutdownNow();
        //repository.setProgramStates(programStates);
    }

    private void display(ProgramState programState) {
        // displays the current state of the program if the displayFlag is true
        if (displayFlag) {
            System.out.println(programState.toString());
        }
    }

    public void setProgramStates(List<ProgramState> programStates) {
        this.repo.setProgramStates(programStates);
    }

    public List<ProgramState> getProgramStates() {
        return this.repo.getProgramStates();
    }

    public IRepository getRepo() {
        return this.repo;
    }
}
