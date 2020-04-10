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
#define v1out(v) FOR(i,0,v.size()){cout<<v[i]; if(i!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

vector<int> sikiri(ll in, ll h){
    vector<int> res;
    res.push_back(0);    
    FOR(i,1,1<<h){
        if(in%2==1)res.push_back(i);
        in/=2;
    }
    res.push_back(h+1);
    return res;
}    

int solve(vector<string> &v, vector<int> &s, int k){
    int ans = 0;
    vector<int> ks(s.size());

    FOR(y,0,v[0].size()){//左からの位置
        bool all_clean = false;
        FOR(k_i,1,s.size()){
            //bool one_clean = true;
            int boarder = 0;
            FOR(x,s[k_i-1],s[k_i]){
                if(v[x][y] == '1'){
            //        one_clean = false;
                    ks[k_i]++;
                    boarder++;
                }
            }
            if(boarder>k)return 1e9;
            //if(one_clean) ks[k_i] = 0;
            if(ks[k_i]>k){
                all_clean = true;
            }
        }
        //v1out(ks);
        if(all_clean){
            //cout<<" y = "<<y<<endl;
            ans++;
            FOR(j,0,ks.size())ks[j]=0;
            FOR(k_i,1,s.size())FOR(x,s[k_i-1],s[k_i]){
                if(v[x][y] == '1')ks[k_i]++;
            }
        }
    }
    //cout<<"ans:s.size() "<<ans<<" "<<s.size()-2<<endl;
    return ans+s.size()-2;
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,k;
    cin>>h>>w>>k;
    vector<string> v(h);
    FOR(i,0,h){
        cin>>v[i];
    }
    int ans = 1e9;
    FOR(i,0,1<<(h-1)){
        //cout<<"i = "<<i<<endl;
        vector<int> s = sikiri(i,h-1);
        ans = min(ans,solve(v,s,k));
    }
    cout<<ans<<endl;
}