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

// Nearly Sorted array is an array where a element can be at i-1,i,i+1 position

int binarysearchonnearlysortedarray(int a[],int key,int n)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(mid-1>=s&&a[mid-1]==key)
            return mid-1;
        else if(a[mid]==key)
            return mid;
        else if (mid+1<=e&&a[mid+1]==key)
            return mid+1;
        if(a[mid+1]<key&&a[mid]<key&&a[mid-1]<key)
            s=mid+2;
        else if(a[mid+1]>key&&a[mid]>key&&a[mid-1]>key)
            e=mid-2;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[]= {2,1,4,3,6,5,8,7,10,9};// duplicate element should not be used
    int n=sizeof(a)/sizeof(a[0]);
    cout<<binarysearchonnearlysortedarray(a,8,n);
    return 0;
}
