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
    ll t;
    cin>>t;
    FOR(x,0,t){
        ll n;
        cin>>n;
        vector<ll> kaiju(n);
        FOR(i,0,n)cin>>kaiju[i];
        ll m;
        cin>>m;
        vector<P> hero(m);
        FOR(i,0,m)cin>>hero[i].first>>hero[i].second;
        sortAlr(hero);
        vector<P> c_hero;
        ll e = 0;
        FOR(i,0,m){
            if(hero[i].second>e){
                c_hero.push_back(hero[i]);
                e = hero[i].second;
            }
        }
        sortAl(c_hero);
//        cout<<endl;
//        FOR(i,0,c_hero.size()){
//            cout<<c_hero[i].first<<" "<<c_hero[i].second<<endl;
//       }
        ll po = 0;
        ll day = 0;
        while(true){
            ll t = 0;
            if(po>=n) break;
            FOR(i,0,c_hero.size()){
                if(t+po>=n) break;
                ll a = c_hero[i].first;
                ll b = c_hero[i].second;
                while(true){
                    if(t+po>=n) break;
                    if(a<kaiju[t+po] || t>=b)break;
                    else t++;
                }
            }
//            cout<<"day = "<<day<<" t = "<<t<<endl;
            if(t == 0){
                day = -1;
                break;
            }
            else{
                po += t;
                day++;
            }
        }
        cout<<day<<endl;

    }
}