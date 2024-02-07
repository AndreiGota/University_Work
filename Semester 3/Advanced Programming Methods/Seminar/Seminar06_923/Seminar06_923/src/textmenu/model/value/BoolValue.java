package textmenu.model.value;

public class BoolValue implements Value {
    boolean val;

    public BoolValue(boolean v){
        val=v;
    }

    @Override
    public String toString() {
        return ""+ val;
    }
}

