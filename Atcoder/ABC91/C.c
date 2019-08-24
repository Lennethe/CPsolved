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
  ll N;
  cin>>N;
  vector<P> a(N);
  vector<P> b(N);
  ll ina,inb;
  FOR(i,0,N){
    cin>>ina>>inb;
    a[i]=make_pair(ina,inb);
  }
  FOR(i,0,N){
    cin>>ina>>inb;
    b[i]=make_pair(ina,inb);
  }

  sort(a.begin(),a.begin());
  sort(b.begin(),b.begin());

  ll i=0,j=0;
  ll res=0;
  while(i<N&&j<N){
    if(a[i].first<b[j].first && a[i].second<b[j].second){
      res++;
      i++;
      j++;
    }
    else if(a[i].first>=b[j].first ){
      j++;
    }
    else i++;
  }

  cout<<res<<endl;
}
