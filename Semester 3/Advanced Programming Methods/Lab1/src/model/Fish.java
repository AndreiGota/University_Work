package model;

import java.util.Objects;

public class Fish implements Animal{
    int year;
    Fish(){}
    public Fish(int year) {
        this.year = year;
    }
    @Override
    public int getYear() {
        return this.year;
    }
    @Override
    public String toString() {
        return "Fish years old: " + this.year;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Fish)) return false;
        Fish fish = (Fish) o;
        return year == fish.year;
    }
}
