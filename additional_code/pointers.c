#include <stdlib.h>
#include <stdio.h>

void freeMatrix(int **matrix, size_t rows)
{
    for (size_t r = 0; r < rows; ++r)
        free(matrix[r]);
    free(matrix);
}

int allocMatrix(int ***matrix, size_t rows, size_t cols)
{
    int** indexArray = (int**)malloc(rows * sizeof(int*));
    if (!indexArray) return 0;

    for (size_t r = 0; r < rows; ++r){
        indexArray[r] = (int*)malloc(cols * sizeof(int));
        if (!indexArray[r]) {
            freeMatrix(indexArray, r);
            return 0;
        }
    }

    *matrix = indexArray;
    return 1;
}

void freeMatrixBlock(int **matrix, size_t rows)
{
    free(matrix);
}

int allocMatrixBlock(int ***matrix, size_t rows, size_t cols)
{
    size_t blockSize = rows*cols * sizeof(int); // data
    blockSize += rows * sizeof(int*); // index array

    int ** array = malloc(blockSize);
    if (!array) return 0;

    int* firstRowPtr = (int*)(array+rows);
    for (size_t r = 0; r < rows; ++r){
        array[r] = firstRowPtr;
        firstRowPtr += cols;
    }
    *matrix = array;
}


void printMatrix(int **matrix, size_t rows, size_t cols)
{
    for (size_t r = 0; r < rows; ++r){
        for (size_t c = 0; c < cols; ++c){
            printf("%d ", matrix[r][c]);
        }
        puts("");
    }
}

void setMatrix(int **matrix, size_t rows, size_t cols)
{
    for (size_t r = 0; r < rows; ++r){
        for (size_t c = 0; c < cols; ++c){
            matrix[r][c] = rand() % 10;
        }
    }
}

int main()
{
    int ** matrix;
    int r = 10, c = 10;

    if (allocMatrixBlock(&matrix, r, c)) {
        setMatrix(matrix, r, c);
        printMatrix(matrix, r, c);
        freeMatrixBlock(matrix, r);
    }
    else {
        puts("No mem :(!");
    }
    return 0;
}