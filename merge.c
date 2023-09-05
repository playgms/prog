#include<stdio.h>
#include<time.h>

void merge(int arr[],int left[],int l_size,int right[],int r_size){
    int i,j,k;
    i=j=k=0;
    while(i<l_size && r<r_size){
        if(left[i] <= right[j]){
        arr[k]=left[i];
        i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;

    }
    while (i<l_size){
        arr[k]=left[i];
        i++;
        k++;
    }
    while (j<r_size){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int size){
    if (size<2){
        return;
    }
    int mid=size/2;
    int left[mid],right[size-mid];
    for(int i=0;i<mid;i++){
        left[i]=arr[i];
    }
    for (int i=mid;i<size;i++){
        right[i-mid]=arr[i];
    }
    merge_sort(left,mid);
    merge_sort(right,size-mid);
    merge(arr,left,mid,right,size-mid);
}
