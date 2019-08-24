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
  int N,X;
  cin>>N>>X;
  vector<int> v(N);
  cinv(v,0,N);
  ll res=N;
  ll min=X;
  ll rest=X;
  FOR(i,0,N){
    rest-=v[i];
    if(min>v[i]) min=v[i];
  }
  while(min<=rest){
    rest-=min;
    res++;
  }
  cout<<res<<endl;
}
