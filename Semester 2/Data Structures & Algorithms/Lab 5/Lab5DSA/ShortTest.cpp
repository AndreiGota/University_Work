#include <assert.h>
#include "Matrix.h"
#include "ShortTest.h"

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);
}

void testSetMainDiagonal()
{
    Matrix matrix(3, 3);
    matrix.setMainDiagonal(1);
    for (int i = 0; i < matrix.nrLines(); i++)
    {
        for (int j = 0; j < matrix.nrColumns(); j++)
        {
            if (i == j)
            {
                assert(matrix.element(i, j) == 1);
            }
        }
    }
    cout << "test set main diagonal";
}

