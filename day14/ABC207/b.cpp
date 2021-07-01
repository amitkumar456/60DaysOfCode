#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll result=0;
    if(b>=c*d){
        result=-1;
    }
    else{
        int r=0;
        while(a>r*d){
            a+=b;
            r+=c;
            result++;
        }
    }
    cout<<result<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
