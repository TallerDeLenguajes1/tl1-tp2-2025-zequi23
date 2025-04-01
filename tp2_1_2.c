#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20 

int main(){

    // codigo a completar 

int i; 
double vt[N]; 


for(i = 0;i<N; i++) 
{  
vt[i]=1+rand()%100;
 
} 

double *pr;

pr = vt;
for ( i = 0; i < N; i++)
{
    printf("%.2f\n", *(pr + i));
}


    return 0;
}