#include <stdio.h>
#include "isort.h"
#define sizeofarray 5

void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);

int main(){
    int arr[sizeofarray];
    for (size_t i = 0; i < sizeofarray; i++)
    {
        scanf("%d",&*(arr+i));
    }
    insertion_sort(arr,sizeofarray);
    for (int i = 0; i < sizeofarray; i++)
    {
        if (i!=sizeofarray-1)
        {
           printf("%d,",*(arr+i));
        }else{
            printf("%d",*(arr+i));
        }
    }
    return 0;
}

void shift_element(int* arr, int i){
    if (i!=0)
    {
        int prev=*arr;
        *arr=0;
        for (size_t j = 0; j < i; j++)
        {
            int temp=*(arr+j+1);
            *(arr+j+1)=prev;
            prev=temp;
        }
    }
}

void insertion_sort(int* arr , int len){
    for (size_t i = 0; i < len-1; i++)
    {
        if (*(arr+i)>*(arr+i+1))
        {
            int j=i,count=0;
            while (*(arr+i+1)<*(arr+j)&&j-->=0)
            {
                count++;
            }
            int temp=*(arr+i+1);
            shift_element(arr+j+1,count);
            *(arr+j+1)=temp;
        }
    }
}
