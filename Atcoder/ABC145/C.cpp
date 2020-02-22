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
    vector<P> v(n);
    vector<ll> p(n);
    FOR(i,0,n) p[i] = i;
    FOR(i,0,n)cin>>v[i].first>>v[i].second;
    ld ans = 0;
    ll x = 0;
    do {
        FOR(i,1,n){
            ans += sqrt((v[p[i]].first - v[p[i-1]].first)*(v[p[i]].first - v[p[i-1]].first) + (v[p[i]].second - v[p[i-1]].second)*(v[p[i]].second - v[p[i-1]].second));
        }
        x++;
    } while (std::next_permutation(p.begin(), p.end()));
    cout(10)<<ans/x<<endl;
}