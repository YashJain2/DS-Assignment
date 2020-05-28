import random

def shellSort(a,n):
    h=1
    while (h>int(n/3)):
        h=3*h+1
    while(h>0):
        for i in range(h,n):
            v=a[i];j=i
            while(a[j-h]>v and j>h-1):
                a[j]=a[j-h]
                j-=h
            a[j]=v
        h=int((h-1)/3)
    for i in range(n):
        print(a[i],end="\t")


x=list(random.randint(1,100) for i in range(10))
n=len(x)
shellSort(x,n)
