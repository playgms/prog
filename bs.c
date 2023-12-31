#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}

int main()
{
    int n;
    printf("Enter the total number of Products: ");
    scanf("%d", &n);

    int arr[n];     
    srand(time(0)); 
    printf("product IDs are :\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n); 
    int key;
    printf("Enter the product ID to be search: ");
    scanf("%d", &key);

    clock_t time;
    double runtime;
    time = clock();
    int result = binarySearch(arr, n - 1, key);
    time = clock() - time;
    runtime = (double)time / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Product is in stock.\n");
    else
        printf("Product is not in stock.\n");

    printf("Time taken: %f seconds\n", runtime);

    return 0;
}
