#include <stdio.h>

void shellSort(int a[],int size)
{
  int i,j,h=1,key;
  while (h<size/3)
  h=3*h+1;
  for (;h>0;h=(h-1)/3)
  {
    for (i=h;i<size;i++)
    {
        key=a[i];
        j=i;
        while(a[j-h]>key && j>h-1)
        {
          a[j]=a[j-h];
          j-=h;
        }
        a[j]=key;
    }
  }
  for(int k=0;k<size;k++)
  printf("%d\t",a[k]);
}


void main()
{
  int a[]={10,9,8,7,6,5,764};
  int n=sizeof(a)/sizeof(a[0]);
  shellSort(a,n);
}
