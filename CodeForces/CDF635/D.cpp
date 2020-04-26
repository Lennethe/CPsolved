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
#define REV(v) reverse(v.begin(),v.end())
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin>>t;
    FOR(q,0,t){
        ll a,b,c;
        cin>>a>>b>>c;
        vector<ll> R(a);
        vector<ll> G(b);
        vector<ll> B(c);
        FOR(i,0,a)cin>>R[i];
        FOR(i,0,b)cin>>G[i];
        FOR(i,0,c)cin>>B[i];
        sortAl(R);
        sortAl(G);
        sortAl(B);
        R.push_back(1e16);
        G.push_back(1e16);
        B.push_back(1e16);        
        ll rr = R[0];
        ll gg = G[0];
        ll bb = B[0];
        ll rp = 0;
        ll gp = 0;
        ll bp = 0;  
        ll ans = 9e18;     
        while(rp<a && gp<b && bp<c){
            rr = R[rp];
            gg = G[gp];
            bb = B[bp];
            //cout<<rr<<" "<<gg<<" "<<bb<<endl;
            ans = min(ans, (rr-gg)*(rr-gg) + (rr-bb)*(rr-bb) + (bb-gg)*(bb-gg));
            if(rr<gg && rr<bb) rp++;
            else if(gg<rr && gg<bb) gp++;
            else if(bb<gg && bb<rr) bp++;
            else if(rr==gg && gg == bb){
                if(R[rp+1] == min(min(R[rp+1],G[gp+1]),B[bp+1])) rp++;
                if(G[gp+1] == min(min(R[rp+1],G[gp+1]),B[bp+1])) rp++;
                if(B[bp+1] == min(min(R[rp+1],G[gp+1]),B[bp+1])) rp++;
            }
            else if(rr == gg){
                if(rp-1<a && gp-1<b){
                    if(R[rp+1]<=G[gp+1])rp++;
                    else gp++;
                }
                else if(rp-1<a){
                    rp++;
                }
                else if(gp-1<b){
                    gp++;
                }
            }
            else if(gg == bb){
                if(gp-1<b && bp-1<c){
                    if(G[gp+1]<=B[bp+1])gp++;
                    else bp++;
                }
                else if(gp-1<b){
                    gp++;
                }
                else if(bp-1<c){
                    bp++;
                }
            }
            else if(bb == rr){
                if(bp-1<c && rp-1<a){
                    if(B[bp+1]<=R[rp+1])bp++;
                    else rp++;
                }
                else if(rp-1<a){
                    rp++;
                }
                else if(bp-1<c){
                    bp++;
                }

            }
            else abort();
            if(rp>=a){
                if(gg<=bb){
                    if(gp<b-1){
                        gp++;
                        rp--;
                    }
                }
                else{
                    if(bp<c-1){
                        bp++;
                        rp--;
                    }
                }
            }
            if(gp>=b){
                if(rr<=bb){
                    if(rp<a-1){
                        rp++;
                        gp--;
                    }
                }
                else{
                    if(bp<c-1){
                        bp++;
                        gp--;
                    }
                }
            }
            if(bp>=c){
                if(gg<=rr){
                    if(gp<b-1){
                        gp++;
                        bp--;
                    }
                }
                else{
                    if(rp<a-1){
                        rp++;
                        bp--;
                    }
                }
            }
            
        }
        cout<<ans<<endl;
    }
}