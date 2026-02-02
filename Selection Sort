#include <stdio.h>

void selectionSort(int arr[], int n) {
   
     int maxIndex, temp;

    for (int i = 0; i < n - 1; i++) {
        maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }

}

int main() {
    int n;

    // Input number of elements in the array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in descending order using selection sort
    selectionSort(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
