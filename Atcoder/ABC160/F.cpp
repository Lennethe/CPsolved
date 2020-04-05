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
    

long long MOD = 1e9 + 7;
std::vector<long long> func(2e5+2);

void build_func(){
  func[0] = 1;
  func[1] = 1;
  for(int i=2;i<=2e5+2;i++)func[i] = func[i-1]*i%MOD;
}

template <typename T>
T ext_gcd(T a, T b, T&x, T&y){
  if(b==0){
    x=1;y=0;return a;
  }
  T q=a/b;
  T g=ext_gcd(b,a-q*b,x,y);
  T z=x-q*y;
  x=y;y=z;
  return g;
}

// aは割る言、mがmod
template <typename T>
T invmod(T a, T m){
  T x,y;
  ext_gcd(a,m,x,y);
  x%=m;
  if(x<0)x+=m;
  return x;
}
struct edge{int to,cost;};

struct treedp{
    static const int S = 200030;

    vector<vector<int>> g; //元の木
    //頂点の情報
    //int value[S]; 
    map<pair<int,int>,ll> value;
    map<pair<int,int>,int> c_num;   //子供の数
    
    int depth[S];   //深さ
    int deg[S];        //次数
    bool used[S];
    bool zero[S]; //初期化子
    int size;
    vector<int> round;

    void init(){
        for(int& d : deg)  d=0;
        g.resize(S);
    }
    //最初に親と子を判らせる
    //頂点からの距離
    void dfs(int idx, int par){
        value[{idx,par}] = 1;
        value[{idx,0}] = 1;
        value[{par,idx}] = 1;
        round.push_back(idx);
        for(int& to : g[idx]){
            pair<int,int> p_node = {idx,par};
            pair<int,int> c_node = {to,idx};            
            deg[to]++;
            if(to == par) continue;
            dfs(to, idx);
            value[p_node] = value[p_node] * value[c_node]%MOD * func[(c_num[p_node]+c_num[c_node]+1)]%MOD * invmod(func[c_num[p_node]],MOD)%MOD * invmod(func[c_num[c_node]+1],MOD)%MOD;
            c_num[p_node] += c_num[c_node]+1;
        }
    }
    void set(){
        size = c_num.size();
        for(bool& u : used)u=false;
        map<pair<int,int>,int> tmp = c_num;
        for(auto i=tmp.begin();i!=tmp.end();i++){
            int from = i->first.first;
            int to = i->first.second;
            int num = i->second;
            c_num[{to,from}] = size-num-2;
        }
    
    }
    
    void solve(){
        deque<int> q;
        q.push_back(round[0]);
        used[q.front()] = true;
        size--;
        while(!q.empty()){
            int from =q.back();
            q.pop_back();
            pair<int,int> p_node = {from,0};
            //ans計算
            value[p_node] = func[size]%MOD;
            for(int& to : g[from]){
                pair<int,int> c_node = {to,from};
                value[p_node] = value[p_node] * value[c_node]%MOD * invmod(func[c_num[p_node]],MOD)%MOD * invmod(func[c_num[c_node]+1],MOD)%MOD;
            }
            //value計算
            for(int& to : g[from])if(!used[to]){
                used[to] = true;
                q.push_back(to);
                value[{from,to}] =value[p_node]%MOD * invmod(value[{to,from}],MOD)%MOD * func[size - c_num[{to,from}]-1]%MOD * func[c_num[{to,from}]+1]%MOD * invmod(func[size],MOD)%MOD;            
            }

        }
    }
    
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    build_func();

    int n;
    cin>>n;
    treedp tr;
    tr.init();
    FOR(i,0,n-1){
        int a,b;
        cin>>a>>b;
        tr.g[a].push_back(b);
        tr.g[b].push_back(a);                
    }
    tr.dfs(1,-1);
    tr.set();
    tr.solve();
    FOR(i,1,n+1){
        cout<<tr.value[{i,0}]<<endl;
    }

}
