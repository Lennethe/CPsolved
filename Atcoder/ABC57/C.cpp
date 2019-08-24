#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

ll F(ll A, ll B){
  return max(to_string(A).size(), to_string(B).size());
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x;
    cin>>x;
    ll ans=1e9;
    FOR(i,1,sqrt(x)+3){
      if(x%i==0){
        ans = min(ans, F(i, x/i));
      }
    }
    cout<<ans<<endl;
}
