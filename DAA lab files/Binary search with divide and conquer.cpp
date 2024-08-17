#include <stdio.h>

// Function to perform binary search using divide and conquer
int binarySearch(int array[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        // If the element is found at the middle
        if (array[mid] == key)
            return mid;

        // If the element is smaller than mid, it can only be in the left subarray
        if (array[mid] > key)
            return binarySearch(array, low, mid - 1, key);

        // Otherwise, the element can only be in the right subarray
        return binarySearch(array, mid + 1, high, key);
    }

    // If the element is not present in the array
    return -1;
}

int main() {
    int n, key, result;

    // Asking for the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int array[n];

    // Asking for the elements of the array
    printf("Enter %d integers in sorted order: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Asking for the value to find
    printf("Enter value to find: ");
    scanf("%d", &key);

    // Calling the binarySearch function
    result = binarySearch(array, 0, n - 1, key);

    // Output the result
    if (result != -1)
        printf("%d found at location %d.\n", key, result + 1);
    else
        printf("Not found! %d isn't present in the list.\n", key);

    return 0;
}

