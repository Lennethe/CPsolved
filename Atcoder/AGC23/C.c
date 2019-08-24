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

ll ext_gcd(ll a, ll b, ll&x, ll&y){
  if(b==0){
    x=1;y=0;return a;
  }
  ll q=a/b;
  ll g=ext_gcd(b,a-q*b,x,y);
  ll z=x-q*y;
  x=y;y=z;
  return g;
}

ll invmod(ll a, ll m){
  ll x,y;
  ext_gcd(a,m,x,y);
  x%=m;
  if(x<0)x+=m;
  return x;
}


int main(){
  int N;
  cin>>N;

  vector<ll> comb(N,1);
  vector<ll> perm(N,1);

  ll z=1000000007;
  FOR(i,1,N){
    perm[i]=perm[i-1]*i%z;
  }
  FOR(i,0,N){
    if(2*i-N<0) comb[i]=0;
    else if(2*i-N==1)comb[i]=i-1;
    else if(2*i-N==0)comb[i]=1;
    else comb[i]=perm[i-1]*invmod(perm[N-i-1],z)%z*invmod(perm[2*i-N],z)%z;
  }

//  coutv(comb,0,N);
  ll res=0;
  FOR(i,1,N){
//    cout<<res<<endl;
    res += (comb[i]*perm[i]%z*perm[N-1-i]%z-comb[i-1]*perm[i-1]%z*perm[N-i]%z+z)%z*i%z;

  // cout<<comb[i]*perm[i]%z*perm[N-i-1]%z<<endl;
    //cout<<comb[i-1]*perm[i-1]%z*perm[N-i]%z<<endl;
    //cout<<i<<endl;
  }
  cout<<res%z<<endl;
}
