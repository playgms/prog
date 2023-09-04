#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoare_partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l - 1;
    int j = r + 1;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(&arr[i], &arr[j]);
    }
}

void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = hoare_partition(arr, l, r);
        quick_sort(arr, l, p);
        quick_sort(arr, p + 1, r);
    }
}

int main()
{
    int n;
    printf("Enter the total number of students:");
    scanf("%d", &n);
    int usn[n];

    
    for (int i = 0; i < n; i++)
    {
        usn[i] = rand() % 1000 + 1;
    }

    
    clock_t time_taken = clock();
    quick_sort(usn, 0, n - 1);
    time_taken = clock() - time_taken;
    double runtime = (double)time_taken / CLOCKS_PER_SEC;

    
    printf("\nUsn in sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d   ", usn[i]);
    }

    printf("\nThe runtime is %lf", runtime);
    return 0;
}
