#include <stdio.h>
#include "tests/test.h"
#include "domain/country.h"
#include "utils/DynamicVector.h"
#include "repository/CountryRepo.h"
#include "ui/UI.h"

int main()
{
    printf("Compilation successful!\n");
    testAll();

    CountryRepo* countryRepo = createCountryRepo();
    CountryRepoController controller = createCountryRepoController(countryRepo);
    UI* ui = createUI(&controller);

    startUI(ui);


    destroyUI(&ui);
    destroyCountryRepo(&countryRepo);
    //_CrtDumpMemoryLeaks();
    return 0;
}