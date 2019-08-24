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
  ll N,M,Q;
  cin>>N>>M>>Q;
  vector<P> v(M);
  vector<P> q(Q);
  ll a,b;
  FOR(i,0,M){
    cin>>a>>b;
    v[i]=make_pair(a,b);
  }
  FOR(i,0,Q){
    cin>>a>>b;
    q[i]=make_pair(a,b);
  }
  sort(v.begin(),v.end());
  ll lmin=v[0].first;
  ll lmax=v[M-1].first;
  ll rmin=v[0].second;
  ll rmax=v[M-1].second;

  vector<ll> L(N+1,0),R(N+1,0);

  FOR(i,0,M){
    R[v[i].second]=i;
  }
  FOR(i,rmin+1,rmax){
    if(R[i]==0) R[i]=R[i-1];
  }
  FORr(i,M-1,-1){
    L[v[i].first]=i;
  }
  FORr(i,lmax-1,lmin){
    if(L[i]==0) L[i]=L[i+1];
  }

  FOR(i,0,N+1){
    cout<<"L"<<i<<"="<<L[i]<<" R"<<i<<"="<<R[i]<<endl;
  }

  FOR(i,0,Q){
    a=q[i].first;
    b=q[i].second;
    if(a<lmin)a=lmin;
    if(rmax<b)b=rmax;
    if(lmax<a||b<rmin)cout<<0<<endl;
    else{
      cout<<R[b]-L[a]+1<<endl;
    }
  }
}
