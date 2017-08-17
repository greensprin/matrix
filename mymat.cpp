#include <iostream>
#include <cstdlib>
#include "mymat.h"

using namespace std;

MyMat::MyMat(int in_col, int in_row)
{
  col = in_col;
  row = in_row;
  val = new double[row * col];
}

MyMat::~MyMat()
{
}

void MyMat::set_val(int y, int x, double in_value)
{
  val[y * row + x] = in_value;
}

double MyMat::out_val(int y, int x)
{
  return val[y * row + x];
}

MyMat MyMat::transpose()
{
  MyMat tmp_mat(row, col);

  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      tmp_mat.set_val(x, y, out_val(y, x));
    }
  }

  return tmp_mat;
}

MyMat MyMat::dot(MyMat mat1, MyMat mat2)
{
  if (mat1.col_read() != mat2.row_read()) {
    cout << "error: matlix scale is not correct at MyMat::dot" << endl;
    cout << "exit" << endl;
    exit(1);
  }

  MyMat tmp_mat(mat1.col_read(), mat2.row_read());

  for (int y = 0; y < tmp_mat.col_read(); y++) {
    for (int x = 0; x < tmp_mat.row_read(); x++) {
      tmp_mat.set_val(y, x, calc_dot_element(mat1, mat2, x, y));
    }
  }

  return tmp_mat;
}

double MyMat::calc_dot_element(MyMat mat1, MyMat mat2, int x, int y)
{
  double sum = 0;
  for (int i = 0; i < mat1.row_read(); i++) {
    sum += mat1.out_val(y, i) * mat2.out_val(i, x);
  }
  return sum;
}

MyMat MyMat::operator+(MyMat &mat2)
{
  if (col != mat2.col || row != mat2.row) {
    cout << "error: mat size is not match..." << endl;
    cout << "exit" << endl;
    exit(1);
  }

  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) + mat2.out_val(y, x));
    }
  }
  return temp;
}

MyMat MyMat::operator-(MyMat &mat2)
{
  if (col != mat2.col || row != mat2.row) {
    cout << "error: mat size is not match..." << endl;
    cout << "exit" << endl;
    exit(1);
  }

  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) - mat2.out_val(y, x));
    }
  }
  return temp;
}

MyMat MyMat::operator*(MyMat &mat2)
{
  if (col != mat2.col || row != mat2.row) {
    cout << "error: mat size is not match..." << endl;
    cout << "exit" << endl;
    exit(1);
  }

  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) * mat2.out_val(y, x));
    }
  }
  return temp;
}

MyMat MyMat::operator/(MyMat &mat2)
{
  if (col != mat2.col || row != mat2.row) {
    cout << "error: mat size is not match..." << endl;
    cout << "exit" << endl;
    exit(1);
  }

  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) / mat2.out_val(y, x));
    }
  }
  return temp;
}

MyMat MyMat::operator+(double value)
{
  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) + value);
    }
  }
  return temp;
}

MyMat MyMat::operator-(double value)
{
  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) - value);
    }
  }
  return temp;
}

MyMat MyMat::operator*(double value)
{
  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) * value);
    }
  }
  return temp;
}

MyMat MyMat::operator/(double value)
{
  MyMat temp(col, row);
  for (int y = 0; y < col; y++) {
    for (int x = 0; x < row; x++) {
      temp.set_val(y, x, out_val(y, x) / value);
    }
  }
  return temp;
}
