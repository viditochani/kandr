#include<stdio.h>
int binsearch(int x, int v[], int n);
int main() {
  int arr[] = {1,2,2,5,7};
  int arr1[] = {1};

  printf("Searching for 7, found at %d \n", binsearch(7, arr, 5));
  printf("Searching for 2, found at %d \n", binsearch(2, arr, 5));
  printf("Searching for 2 in single length array, found at %d \n", binsearch(2, arr1, 1));
  printf("Searching for 1 in single length array, found at %d \n", binsearch(1, arr1, 1));
  return 0;
}
int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = -1;
  high = n;
  while (high-low > 1) {
    //This can cause integer overflow, if low and high are too high. It can be fixed by mid=(low+(high-low)/2.
    mid = (low+high)/2; 
    if (x < v[mid])
      high=mid;
    else 
      low=mid;
  }
  if (low!=-1 && v[low]==x)
    return low;
  return -1;
}
