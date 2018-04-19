#include<stdio.h>

int S=0;
int T[5];


int main(){
    int i;
    int *p = &T[0];

    for(i=0; i<5; i++){
        S=S+i;
        *p++ = S;
        printf("P = %d\n",p);
        printf("S = %d \n", S);
    }
     
}
