#include <stdio.h>

int main()
{
    // Declare variables
    int num1,num2,sum;

    

    printf("Enter two integers: ");

    scanf("%d %d", &num1, &num2);



    // calculate the sum of two numbers

    sum = num1 + num2;      

    

    // Print the result

    printf("%d + %d = %d", num1, num2, sum);
    return 0;
}