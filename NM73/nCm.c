#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int C(int n, int m);
// 二項係数 nCm を計算して返す

static int c_cnt;

int main(int argc, char *argv[]){

  int n, m, m1, m2;
  //number of input check
  if( (argc < 3) || (argc > 4) ){ 
    printf("２〜3引数が必要\n"); exit(-1);
  }
  /*  
  if( argc!=3 ){ 
    printf("２引数が必要\n"); exit(-1);
    }*/

  //  int      n= atoi(argv[1]), m=atoi(argv[2]);

  //temporary
  n = atoi(argv[1]);
  m = atoi(argv[2]);

  if( argc == 4 ){
    n  = atoi(argv[1]);
    m1 = atoi(argv[2]);
    m2 = atoi(argv[3]);
  }else{
    n  = atoi(argv[1]);
    m1 = atoi(argv[2]);
    m2 = atoi(argv[2]);
  }
  
  //input check
  //  printf("(n,m1,m2) = (%d,%d,%d)\n", n, m1, m2);
  if((n < 0) || (m1 < 0) || (m2 < 0)){
    //printf("引数は非負整数\n");
    exit(-1);
  }else if ( (n < m1) || (n < m2)){
    //printf("n >= m1, m2\n");
    exit(-1);
  }else if ( m1 > m2){
    //printf("m1 <= m2\n");
    exit(-1);
  }

  m = m1;

  long int nCm;
  clock_t  t1, t2;

  while (m <= m2){
    //    printf("m:%d\n",m);
    c_cnt = 0;
    t1= clock();
    nCm= C(n,m);
    t2= clock();

    printf("%dC%d = %ld [%d times]\n", n,m,nCm, c_cnt);
    //    printf("%.3fs\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    m++;
  }


  return 0;
}

#define none (-1)
long int C_(int n, int m, long int *c[]);
// メモリcを使って二項係数を計算する

long int C(int n, int m){

  long int *c[n+1];
  int i, j;

  for(i= 0; i!=n+1; i++){
    c[i]= calloc(i+1,sizeof(long int));
    for(j= 0; j!=i+1; j++)
      c[i][j]= none;
  }

  long int r= C_(n,m,c);

  for(i= 0; i!=n+1; i++) free(c[i]);
  
  return r;
}

long int C_(int n, int m,long int *c[]){
  if( c[n][m]!=none ) return c[n][m];
  if( m==0 ) return c[n][m]= 1;
  if( m==n ) return c[n][m]= 1;
  c_cnt++;

  return c[n][m]= C_(n-1,m,c)+C_(n-1,m-1,c);
}
