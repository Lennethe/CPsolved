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
    ll n,k;
    cin>>n>>k;
    ll r,s,p;
    cin>>r>>s>>p;
    string si;
    cin>>si;
    vector<ll> dp_r(n);
    vector<ll> dp_p(n);
    vector<ll> dp_s(n);
    FOR(i,0,k){
        if(si[i] == 'r') dp_p[i] = p;
        if(si[i] == 'p') dp_s[i] = s;
        if(si[i] == 's') dp_r[i] = r;        
    }
    FOR(i,k,n){
        if(si[i] == 'r'){
            dp_r[i] = max(dp_p[i-k],dp_s[i-k]);
            dp_p[i] = max(dp_s[i-k],dp_r[i-k]) + p;
            dp_s[i] = max(dp_r[i-k],dp_p[i-k]);
        }
        if(si[i] == 'p'){
            dp_r[i] = max(dp_p[i-k],dp_s[i-k]);
            dp_p[i] = max(dp_s[i-k],dp_r[i-k]);
            dp_s[i] = max(dp_r[i-k],dp_p[i-k]) + s;
        }
        if(si[i] == 's'){
            dp_r[i] = max(dp_p[i-k],dp_s[i-k]) + r;
            dp_p[i] = max(dp_s[i-k],dp_r[i-k]);
            dp_s[i] = max(dp_r[i-k],dp_p[i-k]);
        }
        
    }
    ll ans = 0;
    FOR(i,n-k,n){
        ans += max(dp_p[i],max(dp_r[i],dp_s[i]));
    }
    cout<<ans<<endl;
}