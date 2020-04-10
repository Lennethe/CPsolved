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
    string s;
    cin>>s;
    ll f = 0;
    string x = "";
    FOR(i,0,(s.size()-1)/2){
        x.push_back(s[i]);
    }
    string y = "";
    FOR(i,(s.size()+3)/2-1,s.size()){
        y.push_back(s[i]);
    }

    FOR(i,0,x.size()){
        if(x[i] != x[x.size()-1-i]) f = 1;
    }
    FOR(i,0,y.size()){
        if(y[i] != y[y.size()-1-i]) f = 1;
    }
    FOR(i,0,s.size()){
        if(s[i] != s[s.size()-1-i]) f = 1;
    }
    
    if(f == 1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}