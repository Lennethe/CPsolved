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

vector<P> makev(){
  ll m;
  cin>>m;
  vector<P> v(m);
  FOR(i,0,m){
    cin>>v[i].first>>v[i].second;
  }
  return v;
}

vector<P> rotate(vector<P> v){
  FOR(i,0,v.size()){
    ll x=v[i].first;
    ll y=v[i].second;
    v[i]=P(y,-x);
  }
  return v;
}

P difp(P a, P b){
  return P(a.first-b.first,a.second-b.second);
}

bool cmp(vector<P> a, vector<P> b){
  if(a.size()!=b.size()) return false;
  vector<P> b1,b2,b3;
  b1=rotate(b);
  b2=rotate(b1);
  b3=rotate(b2);
  ll f1=1,f2=1,f3=1,f4=1;
  FOR(i,1,a.size()){
    if(difp(a[i],a[i-1])!=difp(b[i],b[i-1]))f1=0;
    if(difp(a[i],a[i-1])!=difp(b1[i],b1[i-1]))f2=0;
    if(difp(a[i],a[i-1])!=difp(b2[i],b2[i-1]))f3=0;
    if(difp(a[i],a[i-1])!=difp(b3[i],b3[i-1]))f4=0;

  }
  if(f1+f2+f3+f4>=1)return true;
  else return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin>>n;
  while(n!=0){
    vector<P> v;
    v=makev();
    FOR(i,0,n){
      vector<P> v0,v1;
      v0=makev();
      v1=v0;
      reverse(v1.begin(),v1.end());
      if(cmp(v,v0)||cmp(v,v1))cout<<i+1<<endl;

    }
    cout<<"+++++"<<endl;
    cin>>n;
  }
}
