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
    ll n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    deque<ll> l;
    l.push_front(-1e6);
    FOR(i,0,n){
        if(s[i]=='o' && l.front()+c<i)l.push_front(i);
        if((ll)l.size()==k+1)break;
    }
    l.pop_back();
    
    deque<ll> r;
    r.push_front(1e6);
    FORr(i,0,n-1){
        if(s[i]=='o' && i+c<r.front())r.push_front(i);
        if((ll)r.size()==k+1)break;
    }
    r.pop_back();
    vector<ll> ans;

    FOR(i,0,k){
        if(r.front()==l.back())ans.push_back(r.front());
        r.pop_front();
        l.pop_back();
    }
    FOR(i,0,ans.size()){
        cout<<ans[i]+1;
        if(i==(ll)ans.size()-1)cout<<endl;
        else cout<<" ";
    }
    
    
}