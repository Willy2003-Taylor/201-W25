#include<stdio.h>

void rotate(int num){
    if(num == 0){
        printf("0\n");
        return;
    }

    int count = 0; // To count the number of digits to keep from overflowing

    int temp = num; 
    /*To use a temporary variable to separately store the input for rotating
    so that the input can keep clean for multiple rotations */

    while(temp != 0){
        count++;
        temp /= 10;
    }

    int output = num;

     int power = 1;
        
    for(int j = 1; j < count; j++)
        power *= 10;

    for(int i = 1; i <= count; ++i){
        printf("%d\n", output);

        int last_digit = output % 10;
        output /= 10; //Remove the last digit since it is moved to the most significant bit

       output = last_digit * power + output;
    }
}

int main(){
    int input;
    scanf("%d", &input);
    rotate(input);

    return 0;
}
