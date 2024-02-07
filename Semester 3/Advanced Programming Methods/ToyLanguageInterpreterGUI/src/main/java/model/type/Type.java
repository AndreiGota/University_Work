package model.type;

import model.value.Value;

public interface Type {
    boolean equals(Type another);

    String toString();

    Value defaultValue();
}
