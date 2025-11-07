/*
1.(A)Write a program to accept ‘n’ numbers into an array and then calculate the sum of numbers
present in odd positions and even positions respectively.
    */
#include <stdio.h>
int main() {
    int n, i;
    int arr[100];
    int sum_even = 0;
    int sum_odd = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++) {
        if((i + 1) % 2 == 0){  
            sum_even += arr[i];
        }
        else{                   
            sum_odd += arr[i];
        }
    }
    printf("\nSum of elements at odd positions = %d", sum_odd);
    printf("\nSum of elements at even positions = %d", sum_even);

    return 0;
}


