package model.type;

import model.value.RefValue;
import model.value.Value;

public class RefType implements Type {
    private final Type inner; //inner type is the type of the value that the reference points to

    public RefType(Type inner) {
        this.inner = inner;
    }

    public Type getInner() {
        return this.inner;
    }

    @Override
    public boolean equals(Type another) {
        //two reference types are equal if their inner types are equal
        if (another instanceof RefType)
            return inner.equals(((RefType) another).getInner());
        return false;
    }

    @Override
    public String toString() {
        return String.format("Ref(%s)", inner);
    }

    @Override
    public Value defaultValue() {
        return new RefValue(0, inner);
    }
}
