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

bool compare(int n, int *pt) {
    for(int i=1; i<=n; i++) {
        if(pt[i] != i) return false;
    }
    return true;
}

int main()
{
    fast_io;

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int pt[n+1];
        int mk[n+1];

        for(int i=1; i<=n; i++) cin>>pt[i], mk[i]=i;

        // false
        int t=0;
        if(compare(n, pt)) {
            cout<<t<<endl;
            continue;
        }

        while(true)
        {
            int tm[n+1];
            for(int i=1; i<=n ;i++) {
                tm[pt[i]] = mk[i];
            }

            for(int i=1; i<=n; i++) mk[i] = tm[i];

            ++t;
            if(compare(n, mk)) break;
        }

        cout<<t<<endl;

    }

    return 0;
}



















// End
