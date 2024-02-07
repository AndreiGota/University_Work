package model.value;

import model.type.RefType;
import model.type.Type;


public class RefValue implements Value {
    private final int address; //address of the value that the reference points to
    private final Type locationType; //type of the value that the reference points to

    public RefValue(int address, Type locationType) {
        this.address = address;
        this.locationType = locationType;
    }

    public int getAddress() {
        return this.address;
    }

    public Type getLocationType() {
        return this.locationType;
    }

    @Override
    public String toString() {
        return String.format("(%d, %s)", address, locationType);
    }

    @Override
    public Type getType() {
        //the type of reference is RefType(innerType) because it points to a value of type innerType
        return new RefType(locationType);
    }
}
