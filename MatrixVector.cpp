// MatrixVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int *getVector(int col_count)
{
	int *myVector = new int [col_count];
	for (int i = 0; i < col_count; i++)
	{
		cin >> myVector[i];
	}
	return myVector;
	delete []myVector;
}

int **getMatrix(int row_count, int col_count)
{
	int **myMatrix = new int *[row_count];
	for (int k = 0; k < row_count; k++)
		myMatrix[k] = new int[col_count];

	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			cin >> myMatrix[i][j];
		}
	}
	return myMatrix;
	for (int l = 0; l < row_count; l++)
		delete []myMatrix[l];
}

int *multiplyMatrixByVector(int **matrix, int *vector, int row_count, int col_count)
{
	int *matrixVector = new int [row_count];
	matrixVector[0] = 0;
	for (int i = 0; i < row_count; i++)
	{
		matrixVector[i] = 0;
		for (int j = 0; j < col_count; j++)
		{
			matrixVector[i] += matrix[i][j] * vector[j];
		}
	}
	return matrixVector;
	delete []matrixVector;
}

void showMatrix(int **matrix, int row_count, int col_count)
{
	cout << "the matrix: \n";
	for (int i = 0; i < row_count; i++)
	{
		for (int j = 0; j < col_count; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void showVector(int *vector, int col_count)
{
	cout << "the vector: \n";
	for (int i = 0; i < col_count; i++)
	{
		cout << vector[i] << "\n";
	}
}

void showResult(int *vector, int row_count)
{
	cout << "the result of matrix-vector multiplication: \n";
	for (int i = 0; i < row_count; i++)
	{
		cout << vector[i] << "\n";
	}
}

int main()
{
	int row_count;
	int col_count;
	cout << "enter row count: ";
	cin >> row_count;
	cout << "enter column count: ";
	cin >> col_count;
	cout << "enter a matrix: \n";
	int **matrix = getMatrix(row_count, col_count);
	cout << "enter a vetor: \n";
	int *vector = getVector(col_count);
	int *result = multiplyMatrixByVector(matrix, vector, row_count, col_count);
	showMatrix(matrix, row_count, col_count);
	showVector(vector, col_count);
	showResult(result, row_count);
	return 0;
}
