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

        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            ll r,p,s;
            cin>>r>>p>>s;
            string janken;
            cin>>janken;

            ll b_r = 0;
            ll b_p = 0;
            ll b_s = 0;
            
            FOR(i,0,janken.size()){
                if(janken[i] == 'R') b_r++;
                if(janken[i] == 'P') b_p++;
                if(janken[i] == 'S') b_s++;                
            }

            ll win = min(b_r, p) + min(b_p, s) + min(b_s, r);
            if(win > n-win){
                cout<<"YES"<<endl;
                deque<char> q;
                FOR(i,0,p - b_r) q.push_back('P');
                FOR(i,0,s - b_p) q.push_back('S');
                FOR(i,0,r - b_s) q.push_back('R');
                
                FOR(i,0,n){
                    if(janken[i] == 'R' && p > 0){
                        cout<<"P";
                        p--;
                    }
                    else if(janken[i] == 'P' && s > 0){
                        cout<<"S";
                        s--;
                    }
                    else if(janken[i] == 'S' && r > 0){
                        cout<<"R";
                        r--;
                    }
                    else{
                        cout<<q.front();
                        q.pop_front();
                    }
                    
                }
                cout<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }