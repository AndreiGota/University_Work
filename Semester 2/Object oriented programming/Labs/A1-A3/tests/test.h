#pragma once

#include <stdio.h>
#include <crtdbg.h>
#include <assert.h>

#include "../domain/country.h"
#include "../utils/DynamicVector.h"
#include "../repository/CountryRepo.h"

void testAll();
int testCountry();
int testDynamicVector();
int testCountryRepo();