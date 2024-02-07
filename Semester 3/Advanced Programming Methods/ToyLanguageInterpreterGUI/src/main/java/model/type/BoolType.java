package model.type;

import model.value.BoolValue;
import model.value.Value;

public class BoolType implements Type{
    @Override
    public boolean equals(Type another) {
        return another instanceof BoolType;
    }

    @Override
    public String toString() {
        return "boolean";
    }

    @Override
    public Value defaultValue() {
        return new BoolValue(false);
    }
}
