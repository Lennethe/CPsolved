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
#define REV(v) reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,p;
    cin>>n>>p;
    string s; cin>>s;
    if(p == 2 || p == 5){
        ll ret = 0;
        FOR(i,0,s.size()){
            if((s[i] - '0') % p == 0) ret += i+1;
        }
        cout<<ret<<endl;
        return 0;
    }
    REV(s);
    ll tmp  = 0;
    map<ll,ll> mp;
    ll ans = 0;
    mp[0]++;
    ll ten = 1;
    FOR(i,0,n){
        tmp += ten*(s[i] - '0');
        tmp%=p;
        ans += mp[tmp];
        mp[tmp]++;
        ten *= 10;
        ten%=p;
    }
    cout<<ans<<endl;
}