#include <stdio.h>

void findLargestSmallest(int arr[], int n, int k) {
    int largest = arr[0], smallest = arr[0];

    
    if (k >= n) {
        printf("Invalid k value: k cannot be greater than or equal to the array size.\n");
        return;
    }

    
    for (int i = 1; i < k; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    
    for (int i = k; i < n; i++) {
       
        if (arr[i] >= largest) {
            smallest = largest;  
            largest = arr[i];     
        } else if (arr[i] < smallest) {
            smallest = arr[i];  
        }
    }

    printf("Largest number: %d\nSmallest number: %d\n", largest, smallest);
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    findLargestSmallest(arr, n, k);

    return 0;
}
