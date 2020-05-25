// BASED ON Distribute Books

#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define endl '\n'

const int maxx = 1000000;
int arr[maxx+1];

int main()
{
    fast_io;

    arr[0] = 1;
    arr[1] =0;
    for(int i=2; i<=maxx; i++) {
        arr[i] = (i-1)*(arr[i-1]+arr[i-2]);
    }

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<arr[n]<<endl;
    }

    return 0;
}



















// End
