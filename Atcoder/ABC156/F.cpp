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
#define coutd(v) cout<<# v<<" = "<<v<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k,q;
    cin>>k>>q;
    vector<ll> d(k);
    FOR(i,0,k)cin>>d[i];
    FOR(i,0,q){
        ll n,x,m;
        cin>>n>>x>>m;
        x%=m;
        vector<ll> tmp = d;
        FOR(i,0,k) tmp[i]%=m;
        ll zero = 0;
        ll round_zero = 0;
        FOR(i,0,k)if(tmp[i]==0)round_zero++;
        FOR(i,0,(n-1)%k)if(tmp[i]==0)zero++;
        zero += round_zero*((n-1)/k);
        //coutd(zero);

        ll sum = 0;
        ll round_sum = 0;
        FOR(i,0,k)round_sum += tmp[i];
        FOR(i,0,(n-1)%k)sum += tmp[i];
        sum += round_sum*((n-1)/k);
        //coutd(sum);
        ll res = (sum+x)/m - x/m;
        //coutd(res);
        cout<<n-1-res-zero<<endl;

    }
}