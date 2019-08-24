#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll N;
  cin>>N;
  vector<ll> vec(N+1,0);

  ll x=0;
  FOR(i,1,N+1){
    cin>>x;
    vec[i]=vec[i-1]+x;
  }
  sort(vec.begin(),vec.end());

  ll res=0;
  x=1;
  FOR(i,1,N+1){
    if(vec[i]==vec[i-1]){
      x++;
    }
    else{
      res=res+x*(x-1)/2;
      x=1;
    }

  }
  res=res+x*(x-1)/2;
  //coutv(vec,0,N+1);
  cout<<res<<endl;
}
