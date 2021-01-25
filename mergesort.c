#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void merge(int a[],int low ,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int c[MAX];
    while(i<=mid&&i<=high)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        c[k++]=a[i++];
    }
    while(j<=high)
    {
        c[k++]=a[j++];
    }
    for(i=low;i<=high;i++)
    {
        a[i]=c[i];
    }
}
void merge_sort(int a[],int low,int high)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void main()
{
    int n1,n2,i,a[9000];
    double t1,t2;
    clock_t b1,e1,b2,e2;
    printf("Enter the size of first Input : ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    a[i]=rand()%100;
    b1=clock();
    merge_sort(a,0,n1-1);
    printf("\nSorted Elements are : \n");
    for(i=0;i<n1;i++)
    printf("%d\t",a[i]);
    e1=clock();
    printf("Enter the size of second Input : ");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    a[i]=rand()%100;
    b2=clock();
    merge_sort(a,0,n2-1);
    printf("\nSorted Elements are : \n");
    for(i=0;i<n2;i++)
    printf("%d\t",a[i]);
    e2=clock();
    t1=(double)(e1-b1)/CLOCKS_PER_SEC;
    t2=(double)(e2-b2)/CLOCKS_PER_SEC;
    printf("\nTime to sort %d elements is %f",n1,t1);
    printf("\nTime to sort %d elements is %f",n2,t2);
}