#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H

class MyMat
{
  public:
   MyMat(int in_col = 0, int in_row = 0);
   ~MyMat();

   int col_read() { return col; };
   int row_read() { return row; };

   //input output matrix value
   void set_val(int y, int x, double in_value);
   double out_val(int y, int x);

   MyMat transpose();

   MyMat dot(MyMat mat1, MyMat mat2);

   //operator
   //MyMat
   MyMat operator+(MyMat &mat2);
   MyMat operator-(MyMat &mat2);
   MyMat operator*(MyMat &mat2);
   MyMat operator/(MyMat &mat2);
   //double
   MyMat operator+(double value);
   MyMat operator-(double value);
   MyMat operator*(double value);
   MyMat operator/(double value);

  private:
   int col;
   int row;
   double *val;

   double calc_dot_element(MyMat mat1, MyMat mat2, int x, int y);
};

#endif
