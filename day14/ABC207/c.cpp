#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


bool check(int t1,int t2,int l1,int l2,int r1,int r2){
    if((l2>r1 && r2>l1) || (l1>r2 && r1>l2))
    return false;
    else if(r1==l2){
        if(!((t1==1 || t1==3)&& (t2==1 || t2==2)))
        return false;
    }
    else if(r2==l1){
        if(!((t2==1 || t2==3) && (t1==1 || t1==2)))
        return false;
    }
    

    return true;
}
void solve()
{
    int n;
    cin>>n;
    int t[n],l[n],r[n];
    for(int i=0;i<n;i++)
    cin>>t[i]>>l[i]>>r[i];
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(check(t[i],t[j],l[i],l[j],r[i],r[j]))
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
