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
  ll n;
  cin>>n;
  vector<ll> a(n),b(n);
  cinv(a,0,n);
  cinv(b,0,n);
  vector<ll> key(n+1,0);
  FOR(i,0,n-1){
    key[0]=key[0]+a[i]*a[i+1]+b[i]*b[i+1];
  }
  key[0]=key[0]+a[n-1]*b[n-1];

  FOR(i,1,n){
    if(i%2==1) {
      key[i]=key[i-1]-(a[i]*a[i-1])+(a[i-1]*b[i-1]);
    }
    else{
      key[i]=key[i-1]-(b[i]*b[i-1])+(a[i-1]*b[i-1]);
    }
  }
  ll res=key[0];
  FOR(i,0,n){
    if(res>key[i]) res=key[i];
  }
  cout<<res<<endl;
  coutv(key,0,n);
}
