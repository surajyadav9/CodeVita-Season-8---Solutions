// Min Combinations
// BASED ON EXTENDED EUCLIDEAN ALGORITHM
#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int , int>
#define vi vector<int>
#define ll long long
#define INF 1000000005
#define endl '\n'

int main()
{
    fast_io;

    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;

        cout<<__gcd(a,b)<<endl;
    }

    return 0;
}



















// End
