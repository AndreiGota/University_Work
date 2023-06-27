#pragma once
#include <iostream>
//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

typedef struct Information
{
	int row;
	int col;
	TElem value;
};

typedef struct BTNode
{
	BTNode* left;
	BTNode* right;
	BTNode* parent;
	Information info;
};
class Matrix {

private:
	BTNode* root;
	int rows;
	int cols;

public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);


	TElem add(int i, int j, TElem e);

	BTNode* initNode(int i, int j, TElem e);

	TElem remove(int i, int j);

	void setParentChildLink(BTNode* node, BTNode* newChild);

	BTNode* getMaximumNode(BTNode* start);

	void setMainDiagonal(TElem elem);
};