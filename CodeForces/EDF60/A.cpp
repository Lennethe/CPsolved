#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
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
    vector<ll> v(n);
    cinv(v,0,n);
    ll max_n=0;
    FOR(i,0,n){
      max_n = max(max_n, v[i]);
    }

    ll res = 0;
    ll tmp_res =0;
    FOR(i,0,n){
      if(max_n == v[i]){
        tmp_res++;
      }
      else{
        res = max(res, tmp_res);
        tmp_res = 0;
      }
    }
    res = max(res, tmp_res);
    cout<<res<<endl;
}
