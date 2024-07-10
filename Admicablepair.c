#include <stdio.h>

int sumOfProperDivisors(int n) {
    int sum = 1; 

    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;  
            if (i * i != n) {  
                sum += n / i;
            }
        }
    }

    return sum;
}

int isAmicablePair(int num1, int num2) {
    return (sumOfProperDivisors(num1) == num2 && sumOfProperDivisors(num2) == num1);
}

int main() {
    int k, num;

    printf("Enter the value of k: ");
    scanf("%d", &k);

    
    if (k <= 0) {
        printf("Invalid input: k must be a positive integer.\n");
        return 1;
    }

    
    num = k * k + 1;

    int amicablePair = sumOfProperDivisors(num);

    if (isAmicablePair(num, amicablePair)) {
        printf("%d is part of an amicable pair.\n", num);
    } else {
        printf("%d is not part of an amicable pair.\n", num);
    }

    return 0;
}
