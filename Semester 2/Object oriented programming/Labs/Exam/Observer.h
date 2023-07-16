#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

class Subject
{
private:
    vector<Observer*> observers;

public:
    void addObserver(Observer* o);
    void removeObserver(Observer* o);
    void notify();
};