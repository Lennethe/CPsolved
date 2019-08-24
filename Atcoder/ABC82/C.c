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
  ll N;
  cin>>N;
  vector<ll> v(N,0);
  cinv(v,0,N);
  sortAl(v);
  ll num=0,amo=0,res=0;
  FOR(i,0,N){
    if(v[i]==num){
      amo++;
      //cout<<"a";
    }
    else{
      if(amo>num) res+=amo-num;
      else if(amo<num) res+=amo;
      num=v[i];
      amo=1;
      //cout<<"w";
    }
  }
  if(amo>num) res+=amo-num;
  else if(amo<num) res+=amo;

  cout<<res<<endl;

}
