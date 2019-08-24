//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<ll> b(n);
    vector<ll> g(m);
    FOR(i,0,n)cin>>b[i];
    FOR(i,0,m)cin>>g[i];
    sortAlr(b);
    sortAl(g);
    if(b[0]>g[0]) cout<<-1<<endl;
    else{
      ll sum = 0;
      FOR(i,0,m)sum+=g[i];
      FOR(i,1,n)sum+=b[i]*m;
      if(b[0]<g[0]) sum+=b[0]-b[1];
      cout<<sum<<endl;
    }
}
