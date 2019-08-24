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
    ll m1=0,m2=0,y1=1,y2=1;

    if((s[0] == '0' && (s[1] != '0')))m1=1;
    if((s[0] == '1' && (s[1] == '0' ||s[1] == '1' ||s[1] == '2')))m1=1;

    if((s[2] == '0' && (s[3] != '0')))m2=1;
    if((s[2] == '1' && (s[3] == '0' ||s[3] == '1' ||s[3] == '2')))m2=1;

    if(y1*y2*m1*m2 == 1) cout<<"AMBIGUOUS"<<endl;
    else if(y1 * m2 == 1) cout<<"YYMM"<<endl;
    else if(y2 * m1 == 1)cout<<"MMYY"<<endl;
    else cout<<"NA"<<endl;




}
