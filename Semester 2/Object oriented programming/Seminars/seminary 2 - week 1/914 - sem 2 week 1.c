// 914 - sem 2 week 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "DynamicArray.h"
#include <crtdbg.h>

int main()
{
    testDynamicArray();

    Planet* p1 = createPlanet("mars", "red", 23.4);
    Planet* p2 = createPlanet("venus", "blue", 223.4);

    DynamicArray* da1 = createDynamicArray(4, destroyPlanet);
    add(da1, p1);
    DynamicArray* da2 = createDynamicArray(4, destroyPlanet);
    add(da2, p2);

    DynamicArray* da3 = createDynamicArray(4, destroyDynamicArray);
    add(da3, da1);
    add(da3, da2);

    destroyDynamicArray(da3);

    _CrtDumpMemoryLeaks();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
