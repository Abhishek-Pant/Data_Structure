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

int numberofrotation(int a[],int n)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        if(a[s]<a[e]) return s;// case 1
        int mid=s+(e-s)/2;
        int b=(mid-1+n)%n,f=(mid+1)%n;
        if(a[mid]<a[b]&&a[mid]<a[f]) return mid;// case 2
        if(a[mid]<a[e]) e=mid-1;
        if(a[mid]>a[s]) s=mid+1;
    }
    return -1;
}

int binarysearch(int a[],int s,int e,int key)
{
    while(s<e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==key) return mid;
        else if(a[mid]>key) e=mid-1;
        else if(a[mid]<key) s=mid+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[]= {12,15,18,2,5,6,8,11};// duplicate element should not be used
    int n=sizeof(a)/sizeof(a[0]);
    int val=numberofrotation(a,n);
    //cout<<val<<en;
    int key=8;
    cout<<max(binarysearch(a,0,val-1,key),binarysearch(a,val,n-1,key));
    return 0;
}
