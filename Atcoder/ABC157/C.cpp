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
    string s = "aaa";
    if(n==1) s = "a";
    if(n==2) s = "aa";   
    FOR(i,0,m){
        ll a,b;
        cin>>a>>b;
        if(s[a-1] != 'a' && s[a-1] != b + '0'){
            s = "-1";
            break;
        }
        s[a-1] = b + '0';
    }
    if(n != 1 && s[0] == '0') s = "-1";

    FOR(i,0,n){
        if(n!=1 && s[0] == 'a') s[0] = '1';
        else if(s[i] == 'a') s[i] = '0';
    }
    cout<<s<<endl;
}