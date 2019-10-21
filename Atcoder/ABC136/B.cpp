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

    ll n;
    cin>>n;

    ll ans = 0;
    if(n >= 10) ans+=9;
    else ans += n;
    if(n >= 1000) ans += 900;
    else if(n >= 100){
      ans += n%100 + 1;
      ans += (n/100-1) * 100;
    }
    if(n >= 100000) ans += 90000;
    else if(n >= 10000){
      ans += n%10000 + 1;
      ans += (n/10000 -1) * 10000;
    }
    cout<<ans<<endl;
}
