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

char cal(char c, char d){
    if(c == d) return c;
    if(c == 'S'){
        if(d == 'T')return 'E';
        else return 'T';
    }
    if(c == 'E'){
        if(d == 'S')return 'T';
        else return 'S';
    }
    if(c == 'T'){
        if(d == 'S')return 'E';
    }
    return 'S';
            

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vector<string> v(n);
    FOR(i,0,n)cin>>v[i];
    map<string,vector<int>> mp;
    FOR(i,0,n){
        mp[v[i]].emplace_back(i);
    }

    int ans=0;
    FOR(i,0,n){
        FOR(j,i+1,n){
            string a,b;
            a = v[i];
            b = v[j];
            string c = "";
            FOR(q,0,k) c.push_back(cal(a[q],b[q]));
            FOR(p,0,mp[c].size()){
                if(mp[c][p]>j) ans+= mp[c].size() - p;
            }
        }
    }
    cout<<ans<<endl;

}