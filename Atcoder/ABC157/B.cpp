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
    vector<vector<ll>> bingo(3,vector<ll>(3,0));
    FOR(i,0,3){
        FOR(j,0,3){
            cin>>bingo[i][j];
        }
    }
    ll n;
    cin>>n;
    FOR(i,0,n){
        ll b;
        cin>>b;
        FOR(j,0,3)FOR(k,0,3)if(b == bingo[j][k])bingo[j][k] = 0;
    }

    ll res = 0;
    if(bingo[0][0] == 0 && bingo[0][1] == 0 && bingo[0][2] == 0) res = 1;
    if(bingo[1][0] == 0 && bingo[1][1] == 0 && bingo[1][2] == 0) res = 1;
    if(bingo[2][0] == 0 && bingo[2][1] == 0 && bingo[2][2] == 0) res = 1;
    if(bingo[0][0] == 0 && bingo[1][0] == 0 && bingo[2][0] == 0) res = 1;
    if(bingo[0][1] == 0 && bingo[1][1] == 0 && bingo[2][1] == 0) res = 1;
    if(bingo[0][2] == 0 && bingo[1][2] == 0 && bingo[2][2] == 0) res = 1;
    if(bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0) res = 1;
    if(bingo[2][0] == 0 && bingo[1][1] == 0 && bingo[0][2] == 0) res = 1;
    if(res == 0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}