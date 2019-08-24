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

  map<ll,ll> L,R;
  char c;
  ll in;
  map<ll,char> map;
  ll l=0,r=0;
  FOR(i,0,n){
    cin>>c>>in;
    if(c=='L'){
      L[in]=l;
      l++;
      map[in]=c;
    }
    if(c=='R'){
      R[in]=r;
      r++;
      map[in]=c;
    }
    if(c=='?'){
      if(map[in]=='R'){
        cout<<min(r-R[in]-1,R[in]+l)<<endl;
      }
      if(map[in]=='L'){
        cout<<min(l-L[in]-1,L[in]+r)<<endl;
      }
    }
  }
}
