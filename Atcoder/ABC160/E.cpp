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
    ll x,y,r,g,c;
    cin>>x>>y>>r>>g>>c;
    vector<P> v;
    FOR(i,0,r){
        ll in; cin>>in;
        v.push_back(P(in,(ll)0));
    }
    FOR(i,0,g){
        ll in; cin>>in;
        v.push_back(P(in,(ll)1));
    }
    FOR(i,0,c){
        ll in; cin>>in;
        v.push_back(P(in,(ll)2));
    }
    sortAlr(v);
    ll ans=0;
    ll ra = 0;
    ll ga=0;
    ll ca=0;
    FOR(i,0,v.size()){
        ll a = v[i].first;
        ll k = v[i].second;
        if(k==0 && ra<x){
            ra++;
            ans+=a;
        }
        if(k==1 && ga<y){
            ga++;
            ans+=a;
        }
        if(k==2){
            ca++;
            ans+=a;
        }
        
        if(ra+ga+ca==x+y)break;
    }
    cout<<ans<<endl;
}