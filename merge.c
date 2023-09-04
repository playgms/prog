#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int l, int mid, int r)
{
    
    int an = mid - l + 1;
    int bn = r - mid;
    
    int a[an];
    int b[bn];
    for (int i = 0; i < an; i++)
    {
        a[i] = arr[l + i];
    }
    for (int j = 0; j < bn; j++)
    {
        b[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l; 
    while (i < an && j < bn)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
    
    while (i < an)
    {
        arr[k++] = a[i++];
    }
    while (j < bn)
    {
        arr[k++] = b[j++];
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int n;
    printf("Enter the total number of Employee: ");
    scanf("%d", &n);
    int emp_id[n];
    
    for (int i = 0; i < n; i++)
    {
        emp_id[i] = rand() % 1000 + 1;
    }
    clock_t time_taken = clock();
    merge_sort(emp_id, 0, n - 1);
    time_taken = clock() - time_taken;
    double runtime = (double)time_taken / CLOCKS_PER_SEC;
    
    printf("\nEmployee Id in Sorted order: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", emp_id[i]);
    }
    printf("\nThe runtime is %lf", runtime);
    return 0;
}
