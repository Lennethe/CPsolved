#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  int N,M,X;
  cin>>N>>M>>X;
  vector<int> key(M);
  cinv(key,0,M);
  sort(key.begin(),key.end());
  int res=0;
  FOR(i,0,M){
    if(key[i]<X) res++;
  }
  if(res<=M/2){
    cout<<res<<endl;
  }
  else cout<<M-res<<endl;
}
