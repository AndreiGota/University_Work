package model.value;

import model.type.IntType;
import model.type.Type;

public class IntValue implements Value{
    private final int val;

    public IntValue(int val) {
        this.val = val;
    }

    public int getVal() {
        return this.val;
    }

    @Override
    public String toString() {
        return String.format("%d", this.val);
        //String.format("%d", 5) -> "5"
    }

    public boolean equals(Value another) {
        if (another instanceof IntValue anotherInt) {
            return this.val == anotherInt.getVal();
        }
        return false;
    }

    @Override
    public Type getType() {
        return new IntType();
    }
}
