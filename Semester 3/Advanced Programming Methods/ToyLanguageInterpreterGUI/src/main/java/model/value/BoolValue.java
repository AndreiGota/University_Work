package model.value;

import model.type.BoolType;
import model.type.Type;

public class BoolValue implements Value {
    private final boolean val;

    public BoolValue(boolean val) {
        this.val = val;
    }

    public boolean getVal() {
        return this.val;
    }

    @Override
    public String toString() {
        return this.val ? "true" : "false";
    }

    public boolean equals(Value another) {
        if (another instanceof BoolValue anotherBool) {
            return this.val == anotherBool.getVal();
        }
        return false;
    }

    @Override
    public Type getType() {
        return new BoolType();
    }
}
