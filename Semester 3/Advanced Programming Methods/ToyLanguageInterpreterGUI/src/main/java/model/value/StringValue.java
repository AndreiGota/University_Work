package model.value;

import model.type.StringType;
import model.type.Type;

public class StringValue implements Value{
    private final String val;

    public StringValue(String val) {
        this.val = val;
    }

    public String getVal() {
        return this.val;
    }

    public boolean equals(Value another) {
        if (another instanceof StringValue anotherStringValue) {
            return this.val.equals(anotherStringValue.val);
        }
        return false;
    }

    @Override
    public Type getType() {
        return new StringType();
    }

    @Override
    public String toString() {
        return "\"" + this.val + "\"";
    }
}
