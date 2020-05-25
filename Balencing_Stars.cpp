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
        int n;
        string s;
        cin>>s;
        n = s.size();

        string fn;
        forn(i, n) if(s[i]<'a' || s[i]>'z') fn.pb(s[i]);
        n = fn.size();

        // cout<<fn<<endl;

        // {({*[]**})}
        // pair<char, index>
        stack<pair<char, int>> stk;
        int cnt=0, valid_bracks=0;
        forn(i , n) {
            if(!stk.empty()) {
                pair<char, int> tp = stk.top();
                if((tp.ff=='(' && fn[i]==')') || (tp.ff=='[' && fn[i]==']') || (tp.ff=='{' && fn[i]=='}')) {
                    valid_bracks++;
                    stk.pop();
                    // check for stars
                    int l = tp.ss+1, r = i-1, k=0;
                    while(l<r) {
                        if(fn[l]!='*' && fn[r]!='*') break;
                        if(fn[l]=='*') k++, l++;
                        if(fn[r]=='*') k++, r--;
                    }
                    if(k>=2) cnt++;
                }
                else if(fn[i]!='*') stk.push({fn[i], i});
            }
            else if(fn[i]!='*') stk.push({fn[i], i});
        }
        if(stk.empty() && valid_bracks==cnt) cout<<"Yes "<<cnt<<endl;
        else cout<<"No "<<cnt<<endl;
    }

    return 0;
}



















// End
