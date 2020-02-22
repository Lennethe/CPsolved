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
    set<ll> s;
    ll n,k;
    cin>>n>>k;
    ll ans = n-k+1;
    ll m = 0;
    vector<ll> data(n);
    FOR(i,0,n) cin>>data[i];
    FOR(i,0,k){
        s.insert(data[i]);
        m = max(m,data[i]);
    }
    FOR(i,k,n){
        ll hd = i - k;
        ll hd_d = data[hd];
        ll tl = i;
        ll tl_d = data[tl];
        s.insert(tl_d);
        if(*s.begin() == hd_d && *s.rbegin() == tl_d) ans--;
        s.erase(hd_d);
    }
    vector<ll> c(n);
    ll res = -1;
    FOR(i,1,n){
        if(data[i]>data[i-1]) c[i] = c[i-1] + 1;
        if(c[i] == k - 1) res++;
    }
    res = max(res,(ll)0);
    cout<<ans-res<<endl;

}