package repository;

import exceptions.UtilsException;
import model.ProgramState;

import java.io.IOException;
import java.util.List;

public interface IRepository {
    List<ProgramState> getProgramStates();

    void setProgramStates(List<ProgramState> programStates);

    void addProgram(ProgramState programState);

    void logPrgStateExec(ProgramState programState) throws UtilsException, IOException;

    void emptyLogFile() throws IOException;
}
