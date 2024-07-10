#include <stdio.h>

int is_friendly(int num) {
    int sum_of_divisors = 1;  
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum_of_divisors += i;
            if (i * i != num) {
                sum_of_divisors += num / i;
            }
        }
    }
    return (sum_of_divisors == num);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (is_friendly(num)) {
        printf("%d is a friendly number.\n", num);
    } else {
        printf("%d is not a friendly number.\n", num);
    }

    return 0;
}
