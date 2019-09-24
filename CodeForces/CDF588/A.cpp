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
    vector<ll> v(4);
    ll x = 0;
    FOR(i,0,4){
      cin>>v[i];
      x += v[i];
    }
    string s = "NO";
    FOR(i,0,4){
      FOR(j,i+1,4){
        if(x == 2*(v[i]+v[j])) s ="YES";
      }
    }
    if(2*v[0] == x || 2*v[1] == x || 2*v[2] == x || 2*v[3] == x ) s = "YES";
    cout<<s<<endl;
}
