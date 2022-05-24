#include<iostream>
using namespace std;

void maxheap(int A[], int n)   //for maximum marks
{
    int temp, i=n;
    temp=A[n];
    
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void minheap(int A[], int n)     // for minimum marks 
{
    int temp, i=n;
    temp=A[n];
    
    while(i>1 && temp<A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int main()
{
    int size;
     int i;
    cout<<"enter no of subjects : ";
    cin>>size;

    int A[size];
    for(i=1; i<=size; i++)
    {
        cout<<"enter subject "<<i<<" marks: ";
        cin>>A[i];
    }
    for( i=2; i<=size; i++)
    {
        maxheap(A,i);   //for maximum marks
        //minheap(A,i);   //for minimum marks
    }

    cout<<"given max heap tree is in follwing sequence: "<<endl;
    for( i=1; i<=size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\nmaximum marks obtain by student: "<<A[1]<<endl;

    return 0;
}
