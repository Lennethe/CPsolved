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
  vector<P> vec(N);
  ll x;
  FOR(i,0,N){
    cin>>x;
    vec[i]=make_pair(x,i);
  }
  sort(vec.begin(),vec.end());
  ll res=0;
  ll pre=0;
  ll max=0;
  FOR(i,0,N){
    if(pre<=vec[i].second){
      res++;
    }
    else{
      if(max<=res){
        max=res;
      }
      res=1;
    }
    pre=vec[i].second;
  }
  if(max<=res)max=res;
  cout<<N-max<<endl;
}
