#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target);

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element found at index %d using binary search.\n", result);
    } else {
        printf("Element not found using binary search.\n");
    }

    return 0;
}

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        } else {
            return binarySearch(arr, mid + 1, right, target);
        }
    }

    return -1;
}
