#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll N;
  cin>>N;
  vector<ll> v(N);
  cinv(v,0,N);
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());

  ll Al=0,Bo=0;
  FOR(i,0,N){
    if(i%2==0) Al+=v[i];
    else Bo+=v[i];
  }
  cout<<Al-Bo<<endl;
}
