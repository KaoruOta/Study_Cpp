#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int f(int n);
// n>=0 に対して 
// n番目のフィボナッチ数を計算して返す

static int c_cnt;
int main(int argc, char *argv[]){

  int n, n1, n2;

  //  if( argc==1 ) return 0;

  if( (argc < 2) || (argc > 3) ){ 
    printf("1〜2引数が必要\n"); exit(-1);
  }

  if( argc == 3 ){
    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);
  }else{
    n1 = atoi(argv[1]);
    n2 = atoi(argv[1]);
  }

  //input check
  //  printf("(n,m1,m2) = (%d,%d,%d)\n", n, m1, m2);
  if((n1 < 0) || (n2 < 0)){
    //printf("引数は非負整数\n");
    exit(-1);
  }else if ( n1 > n2){
    //printf("m1 <= m2\n");
    exit(-1);
  }


  //  int n= atoi(argv[1]);

  n = n1;

  long int fib;
  clock_t t1, t2;
  while (n <= n2){
    c_cnt = 0;
    t1= clock();
    fib= f(n);
    t2= clock();
    printf("f(%d)= %ld [%d times]\n", n,fib, c_cnt);
    //    printf("%.3fs\n",(double)(t2-t1)/CLOCKS_PER_SEC);
    n++;
  }

  return 0;
}

#define none (-1)
long int f_(int n, long int F[]);
// メモ F を使った計算

long int f(int n){
  int i; long int r;
  long int F[n+1];
  for(i= 0; i!=n+1; i++) 
    F[i]= none;
  r= f_(n,F);
  return r;
}

long int f_(int n, long int F[]){
  c_cnt++;
  if( F[n]!=none ) return F[n];
  if( n<=1 ) return F[n]= n;
  return F[n]= f_(n-1,F)+f_(n-2,F);
}
