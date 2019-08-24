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
  ll N,K;
  cin>>N>>K;
  ll left=0,center=0,right=0;
  ll li=0,ri=N-1;
  vector<ll> v(N);
  cinv(v,0,N);

  FOR(i,0,N){
    if(v[i]<0) left++;
    else if(v[i]==0) center++;
    else right++;

    if(v[i]<0) li=i;
  }
  FORr(i,N-1,-1){
    if(v[i]>0) ri=i;
  }

  ll res=1e9;
  ll lef=0;
  FOR(i,li,ri+K){
    lef=i-K+1;
    if(0<=lef && i<N){
      if(v[i]*v[lef]<0){
        if(res>2*v[i]-v[lef]) res=2*v[i]-v[lef];
        if(res>v[i]-2*v[lef]) res=v[i]-2*v[lef];
      }
      else if(v[i]*v[lef]>0){
        if(i==li && res>-v[lef]) res=-v[lef];
        if(i!=li && res>v[i]) res=v[i];
      }
      else if(v[i]==0){
        if(res>-v[lef]) res=-v[lef];
      }
      else if(v[lef]==0){
        if(res>v[i]) res=v[i];
      }
    }
  }
  if(K==0) cout<<0<<endl;
  else cout<<res<<endl;

  //cout<<center<<K<<endl;


}
