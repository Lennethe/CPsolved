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
        vector<ll> fib(1e5);
        fib[0] = 1;
        fib[1] = 1;
        ll MOD = 1e9 + 7; 

        FOR(i,2,1e5){
            fib[i] = (fib[i-1] + fib[i-2]) % MOD;
        }

        ll t=1;
        ll ans = 1;
        char c = 'a';
        FOR(i,1,s.size()){
            if(s[i] == 'u') c = 'u';
            if(s[i] == 'n') c = 'n';
            if(s[i] == 'w' || s[i] == 'm'){
                ans = 0;
                break;
            }
            if(s[i] == s[i-1] && c == s[i]){
                t++;
            }
            if(s[i] != s[i-1]){
                ans = ans*fib[t]%MOD;
                t = 1;
            }
        }
        ans = ans*fib[t]%MOD;


        if(s[0] == 'w' || s[0] == 'm'){
            ans = 0;
        }
        cout<<ans<<endl;

    }