#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(long long arr[], int n)
{
    int j;
    long long key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int n;
    printf("Enter total number of phone numbers: ");
    scanf("%d", &n);
   
    long long *phoneNumbers = (long long *)malloc(n * sizeof(long long));

   
    srand(time(0)); 
    for (int i = 0; i < n; i++)
    {
        phoneNumbers[i] = rand() % 9000000000 + 1000000000;
    }

    clock_t time_taken = clock();

    insertionSort(phoneNumbers, n);

    time_taken = clock() - time_taken;

    double runtime = (double)time_taken / CLOCKS_PER_SEC;

    printf("Sorted phone numbers:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%lld\n", phoneNumbers[i]);
    }

    printf("Total time taken : %lf seconds\n", runtime);

    free(phoneNumbers); 

    return 0;
}
