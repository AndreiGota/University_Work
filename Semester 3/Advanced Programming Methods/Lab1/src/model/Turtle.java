package model;

import java.util.Objects;

public class Turtle implements Animal{
    int year;
    public Turtle(int year) {
        this.year = year;
    }
    @Override
    public int getYear() {
        return this.year;
    }

    @Override
    public String toString() {
        return "Turtle years old: " + this.year;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Turtle)) return false;
        Turtle turtle = (Turtle) o;
        return year == turtle.year;
    }
}
