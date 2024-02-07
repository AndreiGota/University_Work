package repository;

import exceptions.UtilsException;
import model.ProgramState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository {
    private List<ProgramState> programStates;
    private final String logFilePath;

    public Repository(ProgramState programState, String logFilePath) throws IOException {
        this.logFilePath = logFilePath;
        this.programStates = new ArrayList<>();
        this.addProgram(programState);
        this.emptyLogFile();
    }

    @Override
    public void addProgram(ProgramState programState) {
        programStates.add(programState);
    }

    @Override
    public List<ProgramState> getProgramStates() {
        return this.programStates;
    }

    @Override
    public void setProgramStates(List<ProgramState> programStates) {
        this.programStates = programStates;
    }

    @Override
    public void logPrgStateExec(ProgramState programState) throws UtilsException, IOException {
        //writes the current state of the program to the log file (logFilePath) and closes the file after writing is done
        PrintWriter logFile = new PrintWriter((new BufferedWriter(new FileWriter(this.logFilePath, true))));
        logFile.println(programState.programStateToString());
        logFile.close();
    }

    @Override
    public void emptyLogFile() throws IOException {
        //opens the log file and closes it immediately, thus emptying it
        PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, false)));
        logFile.close();
    }
}
