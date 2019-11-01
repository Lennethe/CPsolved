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

template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

    int main(){
        cin.tie(0);
        ios::sync_with_stdio(false);
        ll n;
        cin>>n;
        FOR(i,0,n){
            ll in,in2;
            cin>>in>>in2;
            if((ll)gcd(in,in2) != 1)cout<<"Infinite"<<endl;
            else cout<<"Finite"<<endl;
        }
    }