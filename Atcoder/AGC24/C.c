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
  vector<ll> vec(N);
  cinv(vec,0,N);

  FOR(i,1,N){
    if(vec[i]-vec[i-1]>1) vec[0]=1;
  }
  ll pre=0;
  ll res=0;
  if(vec[0]!=0) res=-1;
  else{
    FOR(i,1,N){
      if(vec[i]-pre<1){
        res=res+pre;
      }
      pre=vec[i];
    }
    res=res+pre;
  }

  cout<<res<<endl;
}
