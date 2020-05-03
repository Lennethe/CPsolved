#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define REV(v) reverse(v.begin(),v.end())
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n,1);
    FOR(i,0,k){
        ll d;
        cin>>d;
        FOR(i,0,d){
            ll in;
            cin>>in;
            v[in-1] = 0;
        }
    }
    ll ans=0;
    FOR(i,0,n){
        ans += v[i];
    }
    cout<<ans<<endl;
}