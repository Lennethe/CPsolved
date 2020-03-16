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
#define dout(n) cout<<# n<<" = "<<n<<endl;
    
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,m;
    cin>>a>>b>>m;
    vector<ll> r(a);
    ll mr = 1e9;
    FOR(i,0,a)cin>>r[i];
    FOR(i,0,a)mr = min(mr,r[i]);
    
    vector<ll> d(b);
    ll md = 1e9;
    FOR(i,0,b)cin>>d[i];
    FOR(i,0,b)md = min(md,d[i]);

    ll ans_p = md+mr;
    FOR(i,0,m){
        ll x,y,c;
        cin>>x>>y>>c;
        x--;y--;
        ans_p = min(ans_p, r[x]+d[y]-c);
    }
    cout<<ans_p<<endl;

}