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
    string s;
    cin>>s;
    ll ans=0;
    ll x = 0;
    FOR(i,0,s.size()){
        ans += min(s[i]-'0', 10 - s[i] + '0');
        if(s[i]-'0'<=4){
            if(x==0)x=2;
            if(x==1 && s[i-1] == '5'){
                x = 2;
            }
            ans += 2-x;
            x = 0;
        }
        else{
            x++;
        }

    }
    if(x==0)x=2;
    ans += 2-x;
    x = 0;

    cout<<ans<<endl;

}