#include<stdio.h>

int binary_hamming_dis(unsigned x, unsigned y){
    int distance = 0;

    unsigned flag = x ^ y; // will be combined as a binary number and be converted to decimal

    while(flag != 0){
        distance = distance + flag & 1;
        /**The reason use distance & 1 to count the number of distance
         * is that when flag = 0, no difference between bits
         * so we can use the property of and operator, which is 1 & 1 = 1, otherwise 0  */ 

        flag = flag >> 1;
        /*By shifting right a bit, we can always remove
        the last bit*/
    }

    return distance;
}

int main(){
    unsigned n1, n2;
    scanf("%u %u", &n1, &n2);

    printf("%d\n", binary_hamming_dis(n1, n2));

    return 0;
}
