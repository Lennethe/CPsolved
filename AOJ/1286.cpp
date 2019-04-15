#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
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

  ll n,m,k;
  cin>>n>>m>>k;
  while(n!=0){
    vector<ll> dp((n+1)*(m+1));
    FOR(i,0,m){
      dp[i] = 1;
    }

    FOR(i,1,n){
      FORr(j,i*m-1,i-1){
        FOR(x,1,m+1){
          dp[j+x] += dp[j];
        }
        dp[j] = 0;
      }
    }
    ll sum = 0;
    FOR(i,0,n*m){
      ll mx = max((ll)0, i-k);
      sum += (mx+1)*(dp[i]);
    }
    ld div = pow(m,n);
    ld res = sum/div;
    cout(10)<<res<<endl;

    cin>>n>>m>>k;
  }
}
