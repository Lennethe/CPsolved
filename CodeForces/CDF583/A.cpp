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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,b;
    cin>>n>>a>>b;
    b *= 5;
    n = min(n,n%(a*b) + a*b);
    ll ans = n;
    FOR(i,0,n/a+1){
      FOR(j,0,n/b+1){
        if(n-(i*a)-(j*b)>=0)ans = min(ans, n-(i*a)-(j*b));
      }
    }
    cout<<ans<<endl;
}
