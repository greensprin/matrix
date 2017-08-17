#include <iostream>
#include <cstdlib>
#include "mymat.h"

using namespace std;

void input_mat(MyMat mat)
{
  for (int y = 0; y < mat.col_read(); y++) {
    for (int x = 0; x < mat.row_read(); x++) {
      int val;
      cout << "input mat val" << y << ' ' << x << endl;
      cin >> val;
      mat.set_val(y, x, val);
    }
  }
}

void output_mat(MyMat mat)
{
  for (int y = 0; y < mat.col_read(); y++) {
    for (int x = 0; x < mat.row_read(); x++) {
      cout << mat.out_val(y, x) << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, char **argv)
{
  if (argc < 5) {
    cout << "input command line argument" << endl;
    exit(1);
  }

  int col = atoi(argv[1]);
  int row = atoi(argv[2]);
  int col2 = atoi(argv[3]);
  int row2 = atoi(argv[4]);
  
  MyMat mat1(col, row);
  MyMat mat2(col2, row2);

  input_mat(mat1);
  input_mat(mat2);

  MyMat mat3;

  mat3 = mat3.dot(mat1, mat2);

  output_mat(mat1);
  output_mat(mat2);
  output_mat(mat3);

  output_mat(mat1.transpose());
  output_mat(mat2.transpose());
  output_mat(mat3.transpose());

  cout << "commit github" << endl;

  return 0;
}
