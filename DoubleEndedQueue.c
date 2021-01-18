/* Program to perform Insert and Delete Elemetns in a double Ended Queue
Source was last updated on 11-01-2020(Might be broken report any issues)
compiled with mingw gcc 4.8.1 32-bit release
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define QS 10
void ir(int i,int *r,int q[])
{
    if(*r==QS-1)
    {
        printf("\nQueue OVERFLOW !!!!");
        return;
    }
    q[++(*r)]=i;
    printf("\nItem inserted successfully");
}
void df(int q[],int *f,int *r)
{
    if(*f>*r)
    {
        printf("\nQueue EMPTY !!!!!");
        return;
    }
    printf("\nThe element deleted is %d",q[(*f)++]);
    if(*f>*r)
    {
        *f=0;
        *r=-1;
    }
}
void i_f(int i,int *r,int *f,int q[])
{
    if(*f==0&&*r==-1)
    {
        q[++(*r)]=i;
        printf("\nItem inserted successfully");
        return;
    }
    if(*f!=0)
    {
        q[--(*f)]=i;
        printf("\nItem inserted successfully");
        return;
    }
    printf("\nFront insertion is not POSSIBLE !!!!");
}
void dr(int q[],int *f,int *r)
{
    if(*f>*r)
    {
        printf("\nQueue EMPTY !!!!!");
        return;
    }
    printf("\nThe element deleted is %d",q[(*r)--]);
    if(*f>*r)
    {
        *f=0;
        *r=-1;
    }
}
void display(int q[],int *f,int *r)
{
    int i;
    if(*f>*r)
    {
        printf("\nQueue EMPTY !!!!!");
        return;
    }
    printf("\nContents of the Queue\n");
    for(i=*f;i<=*r;i++)
    {
        printf("%d\t",q[i]);
    }
}
void main()
{
    int c,i,f,r,q[QS];
    f=0;
    r=-1;
    while(1)
    {
        system("CLS");
        printf("\n1. Insert from rear\n2. Delete from front\n3. Insert from front\n4. Delete from rear\n5. Display\n6. Display\n7. Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: system("CLS");
                    printf("Enter the element to be inserted :  ");
                    scanf("%d",i);
                    ir(i,&r,q);
                    break;
            case 2: system("CLS");
                    df(q,&f,&r);
                    break;
            case 3: system("CLS");
                    printf("Enter the element to be inserted :  ");
                    scanf("%d",i);
                    i_f(i,&r,&f,q);
                    break;
            case 4: system("CLS");
                    dr(q,&f,&r);
                    break; 
            case 5: system("CLS");
                    display(q,&f,&r);
                    break;
            case 6: system("CLS");
                    printf("\n Exiting program......");
                    getch();
                    exit(0);
            default:printf("\nInvalid Choice");
                    break;

        }
    }
}
