#include <stdio.h>

//returns the partition position the the quick sort
int partition(int a[],int low,int high){
  int left,right,pivot_value=a[low];
  int temp;
  left=low;
  right=high;
  while(left<right){
    while(a[left]<=pivot_value)
    left++;
    while(a[right]>pivot_value)
    right++;
    //swaps the left and right value
    if(left<right){
      temp=a[left];
      a[left]=a[right];
      a[right]=temp;
    }
  }
  //swaps the pivot to the partition position
  a[low]=a[right];
  a[right]=pivot_value;
  return (right);
}

//quick sort algorithm for sorting array of integers
void quickSort(int a[], int low , int high ){
  int pivot;
  if(low<high){
    pivot=partition(a,low,high);//finds the partition position in the array
    quickSort(a,low,pivot-1);
    quickSort(a,pivot+1,high);
  }
  //prints the sorted list
  for(int i=0;i<high;i++)
  printf("%d\t",a[i]);
}


void main(){
    int a[]={5,8,7,6,764,5,10};
    int n=sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
}
