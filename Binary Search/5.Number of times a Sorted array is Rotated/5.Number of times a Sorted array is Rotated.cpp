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
    int e=n-1,s=0;

    while(s<=e)
    {
        if(a[s]<=a[e]) return s;// case 1
        //cout<<s<<" "<<e<<en;
        int mid=s+(e-s)/2;
        //cout<<mid<<en;
        int b=(mid+n-1)%n,f=(mid+1)%n;
        //cout<<b<<" "<<f<<en;
        if(a[mid]<=a[b]&&a[mid]<=a[f]) return mid;// case 2

        else if(a[s]<=a[mid]) s=mid+1;// case 3

        else if(a[mid]<=a[e]) e=mid-1;// case 4
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[6]= {2,5,6,8,11,12};// duplicate element should not be used
    int n=sizeof(a)/sizeof(a[0]);
    cout<<numberofrotation(a,n);
    return 0;
}
