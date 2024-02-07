package textmenu.model.value;

public class IntValue implements Value {
    int val;

    public IntValue(int v){
        val=v;
    }

    @Override
    public String toString() {
        return ""+val;
    }
}