// Not covered in class
// very useful

#include <iostream>
using namespace std;

const int ROWS = 2;
const int COLS = 5;

// pass local array
// data in stack
// either int literal or int constant in the bracket
// first dimension can be omitted
void matrixEleMultiply1(double matrix[2][5], int rows, int cols, double factor);
void matrixEleMultiply2(double matrix[][5], int rows, int cols, double factor);
void matrixEleMultiply3(double matrix[ROWS][COLS], int rows, int cols, double factor);
void matrixEleMultiply4(double matrix[][COLS], int rows, int cols, double factor);
void ThreeDimEleMultiply5(double ThreeDimArray[][5][10], int rows, int cols, double factor);

// dynamic array
// harder to initialize values
// must remember to 'delete'
void DynMatrixEleMultiply(double **matrix, int rows, int cols, double factor);

void printMatrix(double mat[][COLS], int ROWS, int COLS);
void printMatrix(double ** dynMat, int ROWS, int COLS); // function overloading

int main(int argc, char const *argv[])
{
  double mat[ROWS][COLS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "Local array version\n";
  matrixEleMultiply1(mat, ROWS, COLS, 2);
  printMatrix(mat, ROWS, COLS);

  cout << "Dynamic array version\n";
  double ** dynMat;
  dynMat = new double *[ROWS];  // array of pointers
  for (int i = 0; i < ROWS; i++)
    dynMat[i] = new double [COLS];  // each element is an array of double

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      dynMat[i][j] = i * COLS + j + 1;  // 1 to 10

  DynMatrixEleMultiply(dynMat, ROWS, COLS, 2);
  printMatrix(dynMat, ROWS, COLS);

  for (int i = 0; i < ROWS; i++)
    delete [] dynMat[i];
  delete [] dynMat;

  return 0;
}

void matrixEleMultiply1(double matrix[2][5], int rows, int cols, double factor) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      matrix[i][j] *= factor;
}

void DynMatrixEleMultiply(double **matrix, int rows, int cols, double factor) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      matrix[i][j] *= factor;
}

void printMatrix(double mat[][COLS], int ROWS, int COLS) {
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      cout << mat[i][j];
      if (j < COLS - 1)
        cout << " ";
    }
    cout << endl;
  }
}

void printMatrix(double **dynMat, int ROWS, int COLS) {
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      cout << dynMat[i][j];
      if (j < COLS - 1)
        cout << " ";
    }
    cout << endl;
  }
}
