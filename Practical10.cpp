#include<iostream>
using namespace std;
void merge(int l[],int r[],int a[],int n1 )
{
    int nl=n1/2;
    int nr=n1-nl;
    int i=0,j=0,k=0;
    while(i<nl&&j<nr)
    {
        if(l[i]<r[j])
        {
            a[k++]=l[i];
            i++;
        }
        else
        {
            a[k++]=r[j];
            j++;
        }
    }
    while(i<nl)
    {
        a[k++]=l[i];
        i++;
    }
    while(j<nr)
    {
        a[k++]=r[j];
        j++;
    }

}
void mergesort(int a[],int n1)
{
    if(n1<2)
        return;
    int m=n1/2;
    int l[m];
    int r[n1-m];
    for(int i=0;i<m;i++)
        l[i]=a[i];
    for(int i=m;i<n1;i++)
        r[i-m]=a[i];
    mergesort(l,m);
    mergesort(r,n1-m);
    merge(l,r,a,n1);

}
void printarray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int n1=sizeof(a)/sizeof(a[0]);
    cout<<"Size is "<<n1<<endl;
    mergesort(a,n1);
    printarray(a,n);
}
