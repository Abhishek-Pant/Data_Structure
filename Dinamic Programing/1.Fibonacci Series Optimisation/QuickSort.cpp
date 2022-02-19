#include<bits/stdc++.h>
using namespace std;

#define en '\n'

void qs(int a[],int l,int h)
{
    if(h-l==1||l==h)
    {
        if(a[l]>a[h])
            swap(a[l],a[h]);
        return;
    }
    if(l>h)
        return;
    int i=l,j=h;
    cout<<l<<" "<<h<<en<<en;
    while(i<j)
    {
        while(a[i]<=a[l])
        {
            i++;
        }
        while(a[j]>=a[l])
        {
            j--;
        }
        cout<<i<<" "<<j<<en;
        if(j>i)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[j]);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<en;
    if(l<h&&j>=0)
    {
        qs(a,l,j-1);
        qs(a,j+1,h);
    }
    return;
}

int main()
{
    int a[]={10,80,30,90,40,50,70,INT_MAX};
    int n=sizeof(a)/sizeof(a[0]);
    qs(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
