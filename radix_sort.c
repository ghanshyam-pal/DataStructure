#include<stdio.h>
 
int getMax(int arr[], int n) {
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = { 0 };
 

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);
 
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
void print(int arr[], int n) {
    int i;
printf("sorted array is :- ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
 
int main() {
    int i,a,arr[10] ;
    printf("Enter the no of elements : ");
    scanf("%d",&a);
    printf("Enter the elements :- "); 
    for(i=0;i<a;i++)
    {
    scanf("%d",&arr[i]);
    }
    int n = a;
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
