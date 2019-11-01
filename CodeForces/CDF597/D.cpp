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

    class UnionFind {
        std::vector<int> data;
        int root_count;

        public:
        UnionFind(int size) : data(size, -1), root_count(size) {}
        bool unite(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
            root_count--;
            }
            return x != y;
        }
        bool find(int x, int y) { return root(x) == root(y); }
        int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
        int size(int x) { return -data[root(x)]; }
        int count() const { return root_count; }
    };
     
    int main(){
        cin.tie(0);
        ios::sync_with_stdio(false);
        ll n;
        cin>>n;
        vector<P> v(n);
        FOR(i,0,n){
            cin>>v[i].first>>v[i].second;
        }
        vector<ll> cost(n);
        FOR(i,0,n)cin>>cost[i];
        vector<ll> k(n);
        FOR(i,0,n)cin>>k[i];

        UnionFind u(n+1);
        FOR(i,0,n+1){
            cout<<u.root(i)<<endl;
        }

        ll yen = 0;
        vector<ll> station;
        vector<P> line;
        
        vector<pair<ll,P>> c;
        FOR(i,0,n){
            c.push_back(pair<ll,P>(cost[i],P(i+1,i+1)));
        }
        FOR(i,0,n){
            FOR(j,i+1,n){
                ll d = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
                c.push_back(pair<ll,P>( (k[i]+k[j])*d, P(i+1,j+1) ));
            }
        }
        sortAl(c);

        FOR(i,0,c.size()){
            ll tc = c[i].first;
            ll city1 = c[i].second.first;
            ll city2 = c[i].second.second;
//            cout<<"i = "<<i<<" count ="<<u.count()<<endl;
//            cout<<" c = "<<tc<<" c1 = "<<city1<<" c2 = "<<city2<<endl;
            if(u.count() == 1) break;
            if(city1 == city2 && u.root(city1) != 0){
                u.unite(0,(int)city1);
                station.push_back(city1);
                yen += tc;
            }
            else if(u.root(city1) != u.root(city2)){
                u.unite((int)city1,(int)city2);
                line.push_back(P(city1, city2));
                yen += tc;
            }
        }

        cout<<yen<<endl;
        cout<<station.size()<<endl;
        FOR(i,0,station.size()){
            if(i != station.size()-1)cout<<station[i]<<" ";
            else cout<<station[i]<<endl;
        }
        cout<<line.size()<<endl;
        FOR(i,0,line.size()){
            cout<<line[i].first<<" "<<line[i].second<<endl;
        }
        

    }