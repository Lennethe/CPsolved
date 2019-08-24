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
  vector<char> q(n);
  vector<ll> v(n);
  FOR(i,0,n){
    cin>>q[i]>>v[i];
  }

  map<ll,ll> R,L;
  map<ll,char> mp;
  ll x=0,y=0;
  FOR(i,0,n){
    if(q[i]=='R') {
      R[v[i]]=x;
      x++;
      mp[v[i]]='R';
      cout<<"w"<<endl;
      cout<<R[v[i]]<<endl;
      cout<<v[i]<<endl;
    }
    if(q[i]=='L'){
      L[v[i]]=y;
      y++;
      mp[v[i]]='L';
    }
  }
  L[100]=78;
  cout<<L[100]<<endl;
  cout<<R[3]<<endl;
  /*
  map<ll,ll> mp;
  FOR(i,0,L.size()){
    mp[L[i]]=i;
  }
  */
  vector<ll> key(n+1);
  FORr(i,n-1,-1){
    if(q[i]=='L')key[i]++;
  }
  FORr(i,n-2,-1){
    key[i]+=key[i+1];
  }
  coutv(key,0,n);
  FOR(i,0,n){
    if(q[i]=='?'){
      if(mp[v[i]]=='R'){
        cout<<x-R[v[i]]<<endl;
      }
      else{
        cout<<L[v[i]]<<endl;
      }
    }
  }
}
