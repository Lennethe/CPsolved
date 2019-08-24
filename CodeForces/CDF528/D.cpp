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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    ld s;
    cin>>n>>s;
    vector<ll> v(n);
    FOR(i,0,n-1){
      ll a,b;
      cin>>a>>b;
      v[a-1]++;
      v[b-1]++;
    }
    

    sortAlr(v);
    ld div=v[0];
    FOR(i,1,n){
      if(v[i]<=2){
        break;
      }
      div+=v[i]-2;
    }
    ld ans = s/div*2;
    if(n==2) ans/=2;
    cout(10)<<ans<<endl;
}
