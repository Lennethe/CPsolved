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
    ll n; cin>>n;
    string s; cin>>s;
    ll q; cin>>q;
    map<int,set<ll>> mp;
    FOR(i,0,n)mp[s[i]-'a'].insert(i);
    FOR(i,0,'z'-'a'+3)mp[i].insert(n+1);

    FOR(time,0,q){
        ll in; cin>>in;
        if(in == 1){
            ll p; char cur;
            cin>>p>>cur;
            p--;
            char pre = s[p];
            s[p] = cur;
            mp[pre-'a'].erase(p);
            mp[cur-'a'].insert(p);
        }
        else{
            ll l,r; cin>>l>>r;
            l--;
            ll res = 0;
            FOR(i,0,'z'-'a'+3){
                if(r>*mp[i].lower_bound(l))res++;
            }
            cout<<res<<endl;
        }
    }
}