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

ll gcd(ll a, ll b){
  ll x;
	while(a!=b){
    if(b==0)break;
    a=a%b;
    x=b;
    b=a;
    a=x;
  }
  return a;
}


int comb(ll n, ll r){
	ll res = 1;
  ll z = 998244353;
  for(ll i=0; i<r; i++){
		res = res*(n-i)%z;
	}
  for(ll i=0; i<r; i++){
		res = (res*invmod((i+1),z))%z;
	}

	return res;
}

int main(){
  ll N,A,B,K;
  cin>>N>>A>>B>>K;
  ll z = 998244353;
  //ll res=0,lcm=a*b/(gcd(a,b));
  ll b=0,c=0;
  vector<ll> vec(N+1,1);
  FOR(i,1,N+1){
    vec[i]=(((vec[i-1]%z)*(N-i+1))%z*(invmod(i,z)))%z;
  }

  FOR(i,0,N+1){
    if((K-A*i)%B==0 ){
      b=(K-A*i)/B;
      if(0<=b && b<=N){
        c=((vec[i]*vec[b])%z+c)%z;
      //  cout<<"a="<<i<<" b="<<b<<" c="<<c<<endl;
      //  cout<<comb(N,i)<<" "<<comb(N,b)<<endl;
        c=c%z;
      }
    }
  }
  //coutv(vec,0,N+1);
  cout<<c<<endl;
}
