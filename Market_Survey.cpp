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

    int n,m;
    cin>>n>>m;

    int def[n];
    forn(i, n) cin>>def[i]; 

    int count[4][n];
    memset(count, 0, sizeof(count));

    forn(i, n) {
        int c = def[i]; 
        // Set count
        count[c-1][i] = 1;
    }


    int mat[m][n];
    forn(i, m) {
        forn(j, n) cin>>mat[i][j];
    }

    // Logic
    forn(i, m) {
        int sc=0;
        forn(j, n) {
            int ans = mat[i][j];
            count[ans-1][j]++;
            if(mat[i][j]==def[j]) sc++;
        }
        cout<<sc<<endl;
        for(int j=0; j<n; j++) {
            int mx=0, ans=0;
            for(int k=0; k<4; k++) {
                if(mx < count[k][j]) {
                    mx = count[k][j];
                    ans = k+1;
                }
            }
            def[j] = ans;
        }
    }

    cout<<"final key: ";
    forn(i, n) cout<<def[i]<<" ";
    cout<<endl;


    // according to latest key
    int mx=0, id=0;
    forn(i, m) {
        int sc=0;
        forn(j, n){
            if(mat[i][j]==def[j]) sc++;
        }

        if(mx < sc) {
            id = i+1;
            mx = sc;
        }
    }

    cout<<id<<" "<<mx<<endl;

    

    return 0;
}



















// End 
