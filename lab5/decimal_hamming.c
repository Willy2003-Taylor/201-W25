#include<stdio.h>

int decimal_hamming_dis(unsigned x, unsigned y){
    int distance = 0;

    while(x != 0){

        if(x % 10 != y % 10) distance++;

        x /= 10; 
        y /= 10;
    }
    return distance;
}

int main(){
    unsigned n1, n2;
    scanf("%u %u", &n1, &n2);

    printf("%d\n", decimal_hamming_dis(n1, n2));

    return 0;
}
