//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)


long long MOD = 1e9 + 7;
std::vector<long long> func(2e5+2);
void build_func(){
  func[0] = 1;
  func[1] = 1;
  for(int i=2;i<2e5+2;i++)func[i] = func[i-1]*i%MOD;
}

template <typename T>
T ext_gcd(T a, T b, T&x, T&y){
  if(b==0){
    x=1;y=0;return a;
  }
  T q=a/b;
  T g=ext_gcd(b,a-q*b,x,y);
  T z=x-q*y;
  x=y;y=z;
  return g;
}

// aは割る言、mがmod
template <typename T>
T invmod(T a, T m){
  T x,y;
  ext_gcd(a,m,x,y);
  x%=m;
  if(x<0)x+=m;
  return x;
}

long long comb(long long n, long long k){
  if(n <= k || n<=0 || k<=0) return 1;
  long long x = func[n-k]; 
  long long y = func[k]; 
  return (long long)func[n] * invmod(x, MOD)%MOD * invmod(y, MOD)%MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    build_func();
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    FOR(i,0,min(n,k+1))ans = (ans + comb(n,i)* comb(n-1,i))%MOD;
    cout<<ans<<endl;
}