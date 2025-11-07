/*
1B.Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter 
and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
 implement the following algorithm: 
• Examine the value in the middle of the current array and print it. 
• If the midpoint value is the value that we are looking for, return true 
• If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
• if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
• Continue until you find the value, or until the start reaches the end, 
*/
#include <stdio.h>
int main() {
    int arr[100], n, key;
    int start, end, mid;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);
    start = 0;
    end = n - 1;

    while (start <= end) {
        mid = (start + end) / 2;

        printf("\nCurrent list: ");
        for (int i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nMiddle element: %d (Index %d)\n", arr[mid], mid);

        if (arr[mid] == key) {
            printf(" Element %d found at index %d\n", key, mid);
            found = 1;
            break;
        } 
        else if (key > arr[mid]) {
            printf(" Key %d is greater than %d, searching right half\n", key, arr[mid]);
            start = mid + 1;
        } 
        else {
            printf(" Key %d is smaller than %d, searching left half\n", key, arr[mid]);
            end = mid - 1;
        }
    }
    if (!found) {
        printf("\nElement not found.\nResult: NULL\n");
    }
    return 0;
}

