//Question 2 sorting a given string using merge sort
#include <stdio.h>
#include<string.h>

//merge the sub arrays while sorting
void merge(char *a[],char *temp[],int left,int mid,int right)
{
  int i,left_end,size,temp_pos;
  left_end=mid-1;
  temp_pos=left;
  size=right-left+1;
  //sorting the values in temporary array
  while((left<=left_end)&&(mid<=right))
  {
    if(!strcmp(a[left],a[mid]))//compares the string and return -1 if small
    {
      temp[temp_pos]=a[left];
      temp_pos+=1;left+=1;
    }
    else{
      temp[temp_pos]=a[mid];
      temp_pos+=1;mid+=1;
    }
  }
  while (left<=left_end){
    temp[temp_pos]=a[left];
    temp_pos+=1;left+=1;
  }
  while(mid<=right){
    temp[temp_pos]=a[mid];
    temp_pos+=1;mid+=1;
  }
  //assigning the sorted subarray to original array
  for (i=0;i<=size;i++){
    a[right]=temp[right];
    right-=1;
  }
}

//breaking the array into half using recursion
void mergeSort(char *a[],char *temp[],int left, int right)
{
  int mid;
  if(right>left){
    mid=(left+right)/2;
    mergeSort(a,temp,left,mid);
    mergeSort(a,temp,mid+1,right);
    merge(a,temp,left,mid+1,right);
  }
}


void main()
{
  char *a[2];
  a[0]="Testcase";
  a[1]="Polynomial";
  int n=2;
  char *temp[n];
  mergeSort(a,temp,0,n-1);
  //prints the sorted array
  for(int i=0;i<n;i++)
  printf("%s\t",a[i]);
}
