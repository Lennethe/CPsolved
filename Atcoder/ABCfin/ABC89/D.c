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
  ll H,W,D;
  cin>>H>>W>>D;
  vector<P> v;
  ll x;
  FOR(i,0,H*W){
    cin>>x;
    v[x]=make_pair(i/W+1,i%W+1);
  }

  ll Q;
  cin>>Q;
  ll a,b,res=0;
  FOR(i,0,Q){
    cin>>a>>b;
    res=0;
    FOR(j,1,(b-a)/D){
      res += abs(v[j].first-v[j-1].first) + abs(v[j].second-v[j-1].second)  ;
    }
    cout<<res<<endl;
  }
}
