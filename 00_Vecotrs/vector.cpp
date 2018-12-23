
#include <vector>
#include <iostream>

using namespace std;

int main() {
  int vector_size;
  int i;
  vector<float> vector1(4);
  vector1[0] = 4.5;
  vector1[1] = 2.1;
  vector1[2] = 8.54;
  vector1[3] = 9.0;

  vector<float> vector(4, 3.5);

  vector_size = vector1.size();
  cout <<"vector size:" << vector_size <<endl; 
    
  for (i = 0; i<vector_size; i++){
    cout << vector1[i]<<endl;
  }

  return 0;
}

