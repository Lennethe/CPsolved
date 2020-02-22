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
    int n;
    cin>>n;

    string s;
    if(n == 3){
        cout<<"aab"<<endl;
        cout<<"b.b"<<endl;
        cout<<"baa"<<endl;
        return 0;
    }
    if(n == 2){
        cout<<-1<<endl;
        return 0;
    }

    ll four = n/4 -1;
    FOR(i,0,n)s.push_back('.');
    vector<string> ans(n,s);
    ll p = 0;
    if(n%4 == 0) four++;
    while(four--){
        ans[p][p] = 'a'; ans[p][p+1] = 'a'; ans[p][p+2] = 'b'; ans[p][p+3] = 'a';
        ans[p+1][p] = 'c'; ans[p+1][p+1] = 'c'; ans[p+1][p+2] = 'b'; ans[p+1][p+3] = 'a';
        ans[p+2][p] = 'a'; ans[p+2][p+1] = 'b'; ans[p+2][p+2] = 'c'; ans[p+2][p+3] = 'c';
        ans[p+3][p] = 'a'; ans[p+3][p+1] = 'b'; ans[p+3][p+2] = 'a'; ans[p+3][p+3] = 'a';        
        p += 4;
    }
    if(n%4 == 1){
        ans[p+0][p+0] = 'a'; ans[p+0][p+1] = 'a'; ans[p+0][p+2] = 'b'; ans[p+0][p+3] = 'b'; ans[p+0][p+4] = 'a';
        ans[p+1][p+0] = 'b'; ans[p+1][p+1] = 'c'; ans[p+1][p+2] = 'c'; ans[p+1][p+3] = '.'; ans[p+1][p+4] = 'a';
        ans[p+2][p+0] = 'b'; ans[p+2][p+1] = '.'; ans[p+2][p+2] = '.'; ans[p+2][p+3] = 'c'; ans[p+2][p+4] = 'b';
        ans[p+3][p+0] = 'a'; ans[p+3][p+1] = '.'; ans[p+3][p+2] = '.'; ans[p+3][p+3] = 'c'; ans[p+3][p+4] = 'b';
        ans[p+4][p+0] = 'a'; ans[p+4][p+1] = 'b'; ans[p+4][p+2] = 'b'; ans[p+4][p+3] = 'a'; ans[p+4][p+4] = 'a';        
    }
    if(n%4 == 2){
        ans[p][p] = 'a'; ans[p][p+1] = 'a'; ans[p][p+2] = 'b'; ans[p][p+5] = 'a';
        ans[p+1][p+2] = 'b'; ans[p+1][p+3] = 'c'; ans[p+1][p+5] = 'a';
        ans[p+2][p+1] = 'a'; ans[p+2][p+2] = 'a'; ans[p+2][p+3] = 'c'; ans[p+2][p+4] = 'b'; ans[p+2][p+5] = 'b';
        ans[p+3][p] = 'b'; ans[p+3][p+1] = 'b'; ans[p+3][p+2] = 'c'; ans[p+3][p+3] = 'a'; ans[p+3][p+4] = 'a';
        ans[p+4][p] = 'a'; ans[p+4][p+2] = 'c'; ans[p+4][p+3] = 'b';
        ans[p+5][p] = 'a'; ans[p+4][p+3] = 'b'; ans[p+5][p+3] = 'b'; ans[p+5][p+4] = 'a'; ans[p+5][p+5] = 'a';                 
    }
    if(n%4 == 3){
        ans[p+0][p+0] = 'a'; ans[p+0][p+1] = 'a'; ans[p+0][p+2] = 'b'; ans[p+0][p+3] = 'b'; ans[p+0][p+4] = 'c'; ans[p+0][p+5] = 'c'; ans[p+0][p+6] = '.';
        ans[p+1][p+0] = 'd'; ans[p+1][p+1] = 'd'; ans[p+1][p+2] = '.'; ans[p+1][p+3] = 'd'; ans[p+1][p+4] = 'd'; ans[p+1][p+5] = '.'; ans[p+1][p+6] = 'a';
        ans[p+2][p+0] = '.'; ans[p+2][p+1] = '.'; ans[p+2][p+2] = 'd'; ans[p+2][p+3] = '.'; ans[p+2][p+4] = '.'; ans[p+2][p+5] = 'd'; ans[p+2][p+6] = 'a';
        ans[p+3][p+0] = '.'; ans[p+3][p+1] = '.'; ans[p+3][p+2] = 'd'; ans[p+3][p+3] = '.'; ans[p+3][p+4] = '.'; ans[p+3][p+5] = 'd'; ans[p+3][p+6] = 'b';
        ans[p+4][p+0] = 'd'; ans[p+4][p+1] = 'd'; ans[p+4][p+2] = '.'; ans[p+4][p+3] = 'd'; ans[p+4][p+4] = 'd'; ans[p+4][p+5] = '.'; ans[p+4][p+6] = 'b';
        ans[p+5][p+0] = '.'; ans[p+5][p+1] = '.'; ans[p+5][p+2] = 'd'; ans[p+5][p+3] = '.'; ans[p+5][p+4] = '.'; ans[p+5][p+5] = 'd'; ans[p+5][p+6] = 'c';
        ans[p+6][p+0] = '.'; ans[p+6][p+1] = '.'; ans[p+6][p+2] = 'd'; ans[p+6][p+3] = '.'; ans[p+6][p+4] = '.'; ans[p+6][p+5] = 'd'; ans[p+6][p+6] = 'c';                
    }
    
    FOR(i,0,n) cout<<ans[i]<<endl;
}