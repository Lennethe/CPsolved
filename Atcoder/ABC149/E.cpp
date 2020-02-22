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
    ll n,m;
    cin>>n>>m;
    vector<ll> pow(n);
    vector<ll> dat(1e5+2);
    FOR(i,0,n){
        cin>>pow[i];
        dat[pow[i]]++;
    }
    sortAlr(pow);
    vector<ll> v(n+1);
    FOR(i,0,n) v[i+1] += v[i] + pow[i];
    FORr(i,1,1e5)dat[i-1] += dat[i];

    ll lb = 0;
    ll ub = 2e5+2;
    while(ub-lb!=1){
        ll md = (ub+lb)/2;
        ll cnt = 0;
        FOR(i,0,n){
            ll t = max((ll)0,min(md - pow[i],(ll)1e5+1));
            cnt += dat[t];
        }
        if(m>cnt) ub = md;
        else lb = md;
    }

    ll scr = 0;
    ll sum = 0;
    FOR(i,0,n){
        ll t = max((ll)0,min(ub - pow[i],(ll)1e5+1));
        ll cnt = dat[t];
        sum += cnt;
        scr += v[cnt] + pow[i]*cnt;
    }
    scr += lb*(m-sum);
    cout<<scr<<endl;
}