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
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> lR(n);
    vector<int> lG(n);
    vector<int> lB(n);
    vector<int> rR(n);
    vector<int> rG(n);
    vector<int> rB(n);
    FOR(i,0,n){
        if(s[i] == 'R') lR[i]=1;
        if(s[i] == 'G') lG[i]=1;
        if(s[i] == 'B') lB[i]=1;        
    }
    FOR(i,1,n){
        lR[i] += lR[i-1];
        lG[i] += lG[i-1];
        lB[i] += lB[i-1];        
    }

    FORr(i,0,n-1){
        if(s[i] == 'R') rR[i]=1;
        if(s[i] == 'G') rG[i]=1;
        if(s[i] == 'B') rB[i]=1;        
    }
    FORr(i,0,n-2){
        rR[i] += rR[i+1];
        rG[i] += rG[i+1];
        rB[i] += rB[i+1];        
    }


    ll ans = 0;
    FOR(i,0,n){
        if(s[i] == 'R'){
            ans += lG[i]*rB[i];
            ans += rG[i]*lB[i];            
        }
        if(s[i] == 'G'){
            ans += lR[i]*rB[i];
            ans += rR[i]*lB[i];            
        }
        if(s[i] == 'B'){
            ans += lG[i]*rR[i];
            ans += rG[i]*lR[i];            
        }       
    }   

    FOR(dif,1,n){
        FOR(l,0,n){
            ll m,r;
            m = l + dif;
            r = m + dif;
            if(r >= n)continue;
            if(s[l] != s[m] && s[m] != s[r] && s[r] != s[l]) ans--;
        }
    }
    cout<<ans<<endl;
    

    
    
}