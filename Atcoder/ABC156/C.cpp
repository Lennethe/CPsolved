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
    vector<ll> v(n);
    FOR(i,0,n)cin>>v[i];
    ll tmp = 1e9;
    FOR(i,0,100){
        ll a = 0;
        FOR(j,0,n){
            a += (v[j]-i)*(v[j]-i);
        }
        if(a<=tmp){
            tmp = a;
        }
    }
    cout<<tmp<<endl;
}