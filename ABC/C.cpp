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
    ll n;
    cin>>n;
    vector<vector<ll>> tree(n+1);
    FOR(i,1,n){
        ll from,to;
        cin>>from>>to;
        tree[from].push_back(to);
        tree[to].push_back(from);        
    }
    cout<<endl;
    vector<vector<ll>> v(n+1); // 頂点が距離3にあるやつ
    
    FOR(i,1,n+1){
        deque<ll> q;
        ll start = i;
        q.push_back(start);
        vector<ll> used(n+1,-1);
        used[start] = 0;
        while(!q.empty()){
            ll from = q.front();
            q.pop_front();
            FOR(j,0,tree[from].size()){
                ll to = tree[from][j];
                if(used[to] != -1) continue;
                used[to] = used[from]+1;
                if(used[to]<3 )q.push_back(to);
                if(used[to]==3)v[start].push_back(to);
            }
        }
    }


    vector<ll> num(n+1); //頂点 -> 個数
    map<ll,set<ll>> mp; // 個数 -> 頂点
    ll max_s = 0;
    FOR(i,1,n+1){
        num[i] = v[i].size();
        mp[num[i]].insert(i);
        max_s = max(max_s, num[i]);
    }
    ll three = n/3;
    ll one = (n+2)/3;
    ll two = (n+1)/3;
    
    vector<ll> assign(n+1,-1);
    FORr(i,1,max_s){
        set<ll> tmp = mp[i];
        FORm(j,tmp){
            if(i != num[*j]) continue;
            ll top = *j;
            if(assign[top] != -1){
                num[top] = 0;
                mp[i].erase(top);
                FOR(k,0,v[top].size()){
                    ll child = v[top][k];
                    if(assign[child] != -1) continue;
                    assign[child] = 3-assign[top];
                    if(3-assign[top]==2)two--;
                    if(3-assign[top]==1)one--;
                    mp[num[child]].erase(child);
                    num[child]--;               
                    mp[num[child]].insert(child);
                }
            }
            if(three > 0){
                assign[top] = 3; three--;
                num[top] = 0;
                mp[i].erase(top);
                FOR(k,0,v[top].size()){
                    ll child = v[top][k];
                    if(assign[child] != -1) continue;
                    mp[num[child]].erase(child);
                    num[child]--;               
                    mp[num[child]].insert(child);
                }
            }
            else if(one>two){
                // 2を入れる
                assign[top] = 2; two--;
                num[top] = 0;
                mp[i].erase(top);
                FOR(k,0,v[top].size()){
                    ll child = v[top][k];
                    if(assign[child] != -1) continue;
                    mp[num[child]].erase(child);
                    num[child]--;               
                    mp[num[child]].insert(child);
                    assign[child] = 1; one--;
                }                
            }
            else{
                // 1
                cout<<1<<endl;
                assign[top] = 1; one--;
                num[top] = 0;
                mp[i].erase(top);
                FOR(k,0,v[top].size()){
                    ll child = v[top][k];
                    if(assign[child] != -1) continue;
                    mp[num[child]].erase(child);
                    num[child]--;               
                    mp[num[child]].insert(child);
                    assign[child] = 2; two--;
                }                                
            }
        }
    }
    //cout<<"ans"<<endl;
    one = 0;
    two = 0;
    three = 0;
    vector<ll> used(n+1);
    used[0] = 1;
    FOR(i,1,n+1){
        if(assign[i] == 3){
            three++;
            assign[i] = three*3;
        }
        if(assign[i] == 2){
            assign[i] = two*3+2;
            two++;
        }
        if(assign[i] == 1){
            assign[i] = one*3+1;
            one++;
        }        
        used[assign[i]] = 1;
    }
    deque<ll> w;
    FOR(i,1,n+1)if(used[i] == 0){
        w.push_back(i);
    }

    FOR(i,1,n+1)if(assign[i] == -1){
        assign[i] = w.front();
        w.pop_front();
    }

    FOR(i,1,n+1){
        cout<<assign[i];
        if(i == n)cout<<endl;
        else cout<<" ";
    }

}