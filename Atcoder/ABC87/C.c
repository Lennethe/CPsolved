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
  vector<ll> a(N);
  vector<ll> b(N);
  cinv(a,0,N);
  cinv(b,0,N);
  ll res=0;
  FOR(i,0,N){
    res+=b[i];
  }
  res+=a[0];
  ll inst = res;
  FOR(i,0,N-1){
    inst+= a[i+1]-b[i];
    if(res<inst) res=inst;
  }
  cout<<res<<endl;
}
