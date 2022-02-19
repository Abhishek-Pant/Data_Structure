#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define llu long long unsigned int
#define ld long double
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back
#define sz size
#define en '\n'

#define repi(i,n) for(ll i=0;i<n;i++)
#define repn(i,a,n) for(ll i=a;i<n;i++)
#define repan(i,a,n) for(ll i=0;i<=n;i++)


ll inf = 1e18;
ll mod = 1e9 + 7 ;

// Binary Search on Answer Concept
// Bitonic array is a array which is monotonic in nature i.e first it is in strickly increasing order and then strickly decreasing order
int searchpeekelement(int a[],int n)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid-1]<a[mid]&&a[mid+1]<a[mid])
            return mid;
        else if(a[mid-1]>a[mid+1])
            e=mid-1;
        else if(a[mid-1]<a[mid+1])
            s=mid+1;
    }
    return -1;
}

int searchelementac(int a[],int s,int e,int key)
{
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            e=mid-1;
        else if(a[mid]<key)
            s=mid+1;
    }
    return -1;
}

int searchelementdec(int a[],int s,int e,int key)
{
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            s=mid+1;
        else if(a[mid]<key)
            e=mid-1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[]={1,3,8,9,11,12,10,7,6,4,2};// Unsorted Array
    int n=sizeof(a)/sizeof(a[0]);
    int key=10;
    int val=searchpeekelement(a,n);
    cout<<searchelementac(a,0,val,key)<<en;
    cout<<searchelementdec(a,val+1,n-1,key);
    return 0;
}
