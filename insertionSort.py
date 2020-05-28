import random

def insertionSort(a,n):
    for i in range(1,n):
        key=a[i];
        j=i
        while (a[j-1]>key and j>=1):
            a[j]=a[j-1];
            j-=1;
        a[j]=key;
    for k in range(n):
      print(a[k],end="\t")


x=list(random.randint(1,50) for i in range(100))
n=len(x);
insertionSort(x,n);
