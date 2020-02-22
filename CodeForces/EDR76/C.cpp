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
    ll t;
    cin>>t;
    FOR(i,0,t){
        ll n;
        cin>>n;
        vector<ll> v(2e5+1);
        FOR(j,0,n)cin>>v[j];
        ll ans = n+1;
        vector<ll> key(2e5+1);
        map<ll,ll> mp;
        FOR(j,0,n){
            mp[v[j]]++;
            if(mp[v[j]]>1){
                ans = min(ans, j - key[v[j]]);
            }
            key[v[j]] = j;
        }
        if(ans == n+1) cout<<-1<<endl;
        else cout<<ans+1<<endl;
    }
}