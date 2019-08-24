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
  int N;
  cin>>N;
  map<string,int> m;

  string in;
  FOR(i,0,N){
    cin>>in;
    m[in]++;
  }
  int M;
  cin>>M;
  FOR(i,0,M){
    cin>>in;
    m[in]--;
  }
  int max=0;
  for(auto i=m.begin();i!=m.end();i++){
    max=std::max(max,i->second);
  }
  cout<<max<<endl;

}
