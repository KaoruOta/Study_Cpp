#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector < vector <int>> vec);

vector < vector <int>> sum_matrix(vector < vector <int>> matrix_01, vector < vector <int>> matrix_02);

int main(){

  vector < vector <int> > matrix_01 (5, vector <int> (3,2));
  vector < vector <int> > matrix_02 (5, vector <int> (3,5));
  vector < vector <int> > matrix_03 (5, vector <int> (3,0));
  

  matrix_03 = sum_matrix(matrix_01, matrix_02);
  print_vector(matrix_03);

  return 0;

}

void print_vector(vector < vector <int>> vec){
  int row;
  int column;

  for (row = 0; row < vec.size(); row++){
    for(column = 0; column < vec[0].size(); column++){
      cout << vec[row][column] << " ";
    }
    cout << endl;
  }
}

vector < vector <int>> sum_matrix(vector < vector <int>> matrix_01, vector < vector <int>> matrix_02){
  int row;
  int column;
  int row_size;
  int column_size;

  row_size = matrix_01.size();
  column_size = matrix_01[0].size();

  vector < vector <int>> sum_mtrx_result(row_size, vector <int> (column_size,0));

  for (row = 0; row < row_size; row++){
    for(column = 0; column < column_size; column++){
      sum_mtrx_result[row][column] = matrix_01[row][column] - matrix_02[row][column];
    }
  }

  return sum_mtrx_result;
}
