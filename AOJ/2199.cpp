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

  ll n,m;
  cin>>n>>m;
  while(n!=0){
    //dp初期化
    VEC2(dp,n+1,256);
    FOR(i,0,n+1) FOR(j,0,256) dp[i][j] = 1e12;
    dp[0][128] = 0;

    vector<ll> code(m);
    vector<ll> pls(n);
    cinv(code,0,m);
    cinv(pls,0,n);
    FOR(i,0,n){
      FOR(j,0,256){
        FOR(k,0,code.size()){
          ll pos = j + code[k];
          if(pos<0) pos=0;
          if(pos>255) pos=255;
          ll x = dp[i][j] + ( pls[i] - pos )*( pls[i] - pos );
          dp[i+1][pos] = min(dp[i+1][pos], x);

        }
      //cout<<"i = "<< i <<"j = "<<j-255 <<" " <<dp[i][j]<<endl;
      }
    }
    ll res = 1e15;
    FOR(i,0,256){
      res = min(dp[n][i], res);
    }
    cout<<res<<endl;
    cin>>n>>m;
  }

}
