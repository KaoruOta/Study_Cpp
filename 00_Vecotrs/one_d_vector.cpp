#include <iostream>
#include <vector>

using namespace std;

vector<int> sub_vector(vector<int> vec_01, vector<int> vec_02);

void print_vector(vector<int> vec);

int main() {
  int i;
  vector<int> vec_01 (3);
  vector<int> vec_02 (3);
  vector<int> sub_vec (3);
  
  vec_01[0] = 5;
  vec_01[1] = 10;
  vec_01[2] = 27;

  vec_02[0] = 3;
  vec_02[1] = 17;
  vec_02[2] = 12;

  sub_vec = sub_vector(vec_01,vec_02);

  print_vector(sub_vec);
}

vector<int> sub_vector(vector<int> vec_01, vector<int> vec_02){
  vector<int> dif_vec(vec_01.size());
  int i;

  for (i=0; i<dif_vec.size(); i++){
    dif_vec[i] = vec_01[i] - vec_02[i];
  }

  return dif_vec;
}

void print_vector(vector<int> vec){
  int i;
  for (i=0; i<vec.size(); i++){
    cout << vec[i]<<" ";
  }
  cout << endl;

}
