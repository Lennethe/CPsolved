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

  ll n,k;
  cin>>n>>k;
  vector<ll> v(n);
  cinv(v,0,n);
  VEC2(dp,n+1,n);

  FOR(i,0,n){
    FOR(j,0,n){
      if(abs(i-j)<k)dp[i][j]=v[j];
    }
  }
  ll flag=0;
  FOR(i,0,n){
    flag=0;
    FOR(j,0,n){
      if(dp[i][j]==1)flag=1;
    }
    if(flag==0) break;
  }

  ll res=0;
  if(flag==0) cout<<-1<<endl;
  else{
    FOR(i,0,n){
      FORr(j,n-1,-1){
        if(dp[i][j]==1){
          while(dp[i+1][j]==1){
          //  cout<<i<<", "<<j<<endl;
            i++;
          }
          res++;
          break;
        }
      }
      if(i==n-1)break;

    }
    cout<<res<<endl;
  }
}
