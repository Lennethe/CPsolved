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
        ll a,b,t;
        cin>>a>>b>>t;
        cout<<(t/a)*b<<endl;
    }