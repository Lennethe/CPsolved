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
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<end
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll n,m,d;
  cin>>n>>m>>d;
  vector<ll> v(n);
  cinv(v,0,n);

  vector<ll> res(n);
  FOR(i,0,n){
    res[i]=v[i]%(d+1);
    if(res[i]==0)res[i]=d+1;
  }

  ll z=0;
  FOR(i,0,n){
    if(v[i]==res[i])z++;
  }
  vector<P> key(n);
  FOR(i,0,n){
    key[i]=P(res[i],i+1);
  }
  sortAl(key);
  ll divi=key[0].first-1;
  if(divi!=0){
    ll x=0;
    while(key[x].first==divi+1){
      key[x].first=1;
      x++;
    }
    divi=0;
  }
  //FOR(i,0,n){
  //  cout<<key[i].first<<" ";
  //}
  //cout<<endl;
  FOR(i,1,n){
    if(key[i].first-key[i-1].first>1) divi+=key[i].first-key[i-1].first-1;
    key[i].first-=divi;
  }

  ll swap=0;
  FOR(i,0,n){
    swap=key[i].first;
    key[i].first=key[i].second;
    key[i].second=swap;
  }

  cout<<key[n-1].second<<endl;
  sortAl(key);

  FOR(i,0,n){
    cout<<key[i].second<<" ";
  }
  cout<<endl;
}
