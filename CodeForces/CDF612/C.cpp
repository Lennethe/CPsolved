//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<int,int>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

int cal(vector<int> v, int odd, int even, int n){
    int ans = 0;
    FOR(i,1,n+2){
        if(v[i] == 0 && v[i-1] == 1 && odd >0){
            v[i] = 1; odd--;
        }
        if(v[i] == 0 && v[i-1] == 2 && even >0){
            v[i] = 2; even--;
        }
    }
    FORr(i,1,n+0){
        if(v[i] == 0 && v[i+1] == 1 && odd >0){
            v[i] = 1; odd--;
        }
        if(v[i] == 0 && v[i+1] == 2 && even >0){
            v[i] = 2; even--;
        }
    }
    if(odd == 0)FOR(i,0,n+1)if(v[i] == 0)v[i] = 2;
    if(even == 0)FOR(i,0,n+1)if(v[i] == 0)v[i] = 1;
    
    
    FOR(i,2,n+1){
        if(v[i-1] == 2 && v[i] == 1)ans++;
        if(v[i-1] == 1 && v[i] == 2)ans++;
        if(v[i-1] == 0 && v[i] == 2)ans++;
        if(v[i-1] == 0 && v[i] == 1)ans++;
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int odd = (n+1)/2;
    int even = n/2;
    vector<int> v(n+2);
    FOR(i,1,n+1){
        cin>>v[i];
        if(v[i] != 0 && v[i]%2 == 0)v[i]=2;
        if(v[i] != 0 && v[i]%2 == 1)v[i]=1;        
        if(v[i] == 1) odd--;
        if(v[i] == 2) even--;
    }
    FOR(i,1,n+1)if(v[i] != 0)v[n+1] = v[i];
    FORr(i,1,n+1)if(v[i] != 0)v[0] = v[i];
    if(v[0] == 0){
        cout<<1<<endl;
        return 0;
    }
    vector<P> two_two;
    vector<P> one_one;
    int pre = v[0];
    int pos = 0;
    FOR(i,1,n+2)if(v[i] != 0){
        if(v[i] != pre){
            pre = v[i];
            pos = i;
        }
        else{
            if(v[i] == 1 && i-pos > 1) one_one.push_back(P(i-pos-1,pos+1));
            if(v[i] == 2 && i-pos > 1) two_two.push_back(P(i-pos-1,pos+1));
            pos = i;
        }
    }
    sortAl(one_one);
    sortAl(two_two);
    
    FOR(i,0,one_one.size()){
        int sz = one_one[i].first;
        int ps = one_one[i].second;
        if(sz<=odd){
            FOR(j,ps,ps+sz) v[j] = 1;
            odd -= sz;
        }
    }
    FOR(i,0,two_two.size()){
        int sz = two_two[i].first;
        int ps = two_two[i].second;
        if(sz<=even){
            FOR(j,ps,ps+sz) v[j] = 2;
            even -= sz;
        }
    }

    vector<int> vr = v;
    reverse(vr.begin(), vr.end());
    int x = cal(v,odd,even,n);
    x = min(x, cal(vr,odd,even,n));

    //FOR(i,1,n+1)cout<<v[i]<<" ";
    //cout<<endl;
    cout<<x<<endl;
    

    
}