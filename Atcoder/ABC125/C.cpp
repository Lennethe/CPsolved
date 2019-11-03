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

template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> l(n+2);
    vector<ll> r(n+2);
    
    FOR(i,0,n){
        cin>>v[i];
        l[i+1] = v[i];
        r[i+1] = v[i];
    }
    FOR(i,1,n+2){
        l[i] = (ll)gcd(l[i],l[i-1]);
    }
    FORr(i,0,n){
        r[i] = (ll)gcd(r[i], r[i+1]); 
    }
    ll ans = 1;

    FOR(i,1,n+1){
        ans = max(ans, (ll)gcd(l[i-1],r[i+1]));
    }
    cout<<ans<<endl;
    
}