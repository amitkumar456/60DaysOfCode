#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    if(n==1){
    cout<<0<<endl;
    return;
    }
    unordered_map<int,int> m;
    int i=0,j=n-1,result=0;
    while(i<j){
    if(!m.count(arr[i])){
      if(arr[i]!=arr[j] && !m.count(arr[j])){
      m[arr[i]]=arr[j];
      result++;
      }
      else if(m.count(arr[j]) && m[arr[j]]!=arr[i]){
          m[arr[i]]=m[arr[j]];
          result++;
      }
    }
    else{
        if(m[arr[i]]!=arr[j] && !m.count(arr[j])){
            m[arr[j]]=arr[i];
            result++;
        }
    }
    i++;
    j--;
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
