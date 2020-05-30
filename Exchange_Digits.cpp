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

    int a, b;
    cin>>a>>b;

    vi ar;
    while(a>0) {
        ar.pb(a%10);
        a /= 10;
    }

    int y = b, b_len=0;
    while(y>0) {
        b_len++;
        y /= 10;
    }

    // if len(a) < len(b)
    if(ar.size() < b_len) {
        cout<<-1<<endl;
        return 0;
    }

    // sort the array to get the Least number in lexicographically pattern
    sort(ar.begin(), ar.end());

    // if len(a) > len(b)
    if(ar.size() > b_len) {
        int sum=0;
        for(int i=0; i<ar.size(); i++) {
            sum += ar[ar.size()-i-1]*pow(10,i);
        }
        cout<<sum<<endl;
        return 0;
    }

    // if len(a) == len(b)
    // Generate all permutations
    int ans = -1;
     do {
        int sum=0;
        for(int i=0; i<ar.size(); i++) {
            sum += ar[ar.size()-i-1]*pow(10,i);
        }

        if(sum>b) {
            ans = sum;
            break;
        }

    }  while(next_permutation(ar.begin(), ar.end()));

    cout<<ans<<endl;

    return 0;
}



















// End
