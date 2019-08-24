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
  string s,t;
  cin>>s>>t;
  sortAl(s);
  sortAlr(t);
  ll x=std::min(s.size(),t.size());
  string res="Yes";
  int a=0;
  FOR(i,0,x){
    if(s[i]>t[i]){
      res="No";
      break;
    }
    if(s[i]<t[i]) break;
    a=i;
  }
  if(a==x-1 && s.size()>=t.size()){
    res="No";
  }
  cout<<res<<endl;
}
