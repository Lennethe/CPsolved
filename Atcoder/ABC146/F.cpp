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
    ll n,m;
    string s;
    cin>>n>>m>>s;
    reverse(s.begin(), s.end());
    vector<ll> ans;
    ll po = 0;
    while(po<=n){
        ll t = po;
        FOR(i,1,m+1){
            if(i+po > n+1)break;        
            if(s[i+po] == '0')t = i+po;
        }
//        cout<<"t = "<<t<<endl;
        if(t >= n+1){
            po = t;
            break;
        }
        if(t == po && t < n){
            ans.push_back(-1);
            break;
        }
        else if(t == po){
            break;
        }
        else{
            ans.push_back(t - po);
            po = t;
        }
    }
    reverse(ans.begin(), ans.end());
    if(ans[0] == -1)cout<<-1<<endl;
    else{
        FOR(i,0,ans.size()){
            if(i != ans.size()-1)cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
        }
    }
}