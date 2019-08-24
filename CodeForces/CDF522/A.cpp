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
    ll n,k;
    cin>>n>>k;
    map<ll,ll> mp;
    FOR(i,0,n){
      ll in;
      cin>>in;
      mp[in]++;
    }
    ll mpx=0;
    FORm(i,mp){
      mpx=max(mpx,i->second);
    }
    ll res = mpx + (k - mpx%k);
    if(mpx%k==0)res=mpx;
    ll ans=0;
    FORm(i,mp){
      ans+=res - (i->second);
    }
    //cout<<res<<endl;
    cout<<ans<<endl;
}
