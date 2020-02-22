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
    ll n,d,a;
    cin>>n>>d>>a;
    vector<P> x_h(n+1);
    FOR(i,0,n){
        cin>>x_h[i].first>>x_h[i].second;
        x_h[i].second = (x_h[i].second+a-1)/a;
    }
    x_h[n] = P(1e12, 0);
    sortAl(x_h);
    ll ans = 0;
    ll l = 0;
    vector<ll> res(n);
    ll tmp = 0;
    FOR(i,0,n){
        while(x_h[l].first < x_h[i].first - 2*d){
            tmp -= res[l];
            l++;
        }
        ll dmg = max(x_h[i].second - tmp, (ll)0);
        res[i] = dmg;
        tmp += dmg;
        ans += dmg;
    }
    cout<<ans<<endl;

}