#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin>>n;
  while(n>0){
    vector<ll> dp(1<<n,1e9);
    VEC2(v,n,n+1);
    FOR(i,0,n){
      FOR(j,0,n+1){
        cin>>v[i][j];
      }
    }
    dp[0]=0;
    for(ll i=0;i<1<<n;i++){
      FOR(j,0,n){
        if(i&1<<j)continue;
        ll m=v[j][0];
        FOR(k,1,n+1){
          if(i&1<<(k-1))m=min(v[j][k],m);
          //cout<<i<<" "<<j<<" "<<k<<endl;
        }
        dp[i|1<<j]=min(dp[i|1<<j],dp[i]+m);
      }
    }
    cout<<dp[(1<<n)-1]<<endl;
    cin>>n;
  }
}
