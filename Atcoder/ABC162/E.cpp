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
#define REV(v) reverse(v.begin(),v.end())
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);
const int MOD = 1e9 + 7;

// a^b O(log b)
template <typename T>
T mypow(T a, T b) {
  if (b == 0) return 1;
  T tmp = mypow(a, b / 2);
  if (b % 2)
    return (((tmp * tmp) % MOD) * a) % MOD;
  else
    return (tmp * tmp) % MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k; cin>>n>>k;
    vector<ll> func(k+2);
    FORr(i,1,k+1){
      func.at(i) = mypow(k/i,n);
      FOR(j,2,k+1){
        if(i*j>k)break;
        func.at(i) -= func.at(i*j);
        (func[i] += MOD) %= MOD;
      }
    }
    ll ans = 0;
    FOR(i,1,k+1) (ans+= (func[i]*i+MOD)%MOD) %=MOD;
    cout<<ans<<endl;
}