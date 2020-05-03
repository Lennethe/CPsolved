#define _GLIBCXX_DEBUG
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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<string> s(n);
    FOR(i,0,n)cin>>s[i];
    deque<char> ans;
    FOR(i,0,n){
        if(s[i]=="AB"){
            if(a==0 && b==0){
                cout<<"No"<<endl;
                return 0;
            }
            if(a<b){
                a++;b--;
                ans.push_back('A');
            }
            else if(a>b){
                a--;b++;
                ans.push_back('B');
            }
            else{
                if(i==n-1){
                    ans.push_back('A');
                    break;                    
                }
                if(s[i+1] == "AB"){
                    a++;b--;
                    ans.push_back('A');
                }
                else if(s[i+1] == "AC"){
                    a++;b--;
                    ans.push_back('A');
                }
                else{
                    b++;a--;
                    ans.push_back('B');
                }
            }
        }
        if(s[i]=="BC"){
            if(c==0 && b==0){
                cout<<"No"<<endl;
                return 0;
            }
            if(c<b){
                c++;b--;
                ans.push_back('C');
            }
            else if(c>b){
                c--;b++;
                ans.push_back('B');
            }
            else{
                if(i==n-1){
                    ans.push_back('C');
                    break;
                }
                if(s[i+1] == "CB"){
                    c++;b--;
                    ans.push_back('C');
                }
                else if(s[i+1] == "AC"){
                    c++;b--;
                    ans.push_back('C');
                }
                else{
                    b++;c--;
                    ans.push_back('B');
                }
            }

        }
        if(s[i]=="AC"){
            if(a==0 && c==0){
                cout<<"No"<<endl;
                return 0;
            }
            if(c<a){
                c++;a--;
                ans.push_back('C');
            }
            else if(c>a){
                c--;a++;
                ans.push_back('A');
            }
            else{
                if(i==n-1){
                    ans.push_back('C');
                    break;
                }
                if(s[i+1] == "AC"){
                    c++;a--;
                    ans.push_back('C');
                }
                else if(s[i+1] == "BC"){
                    c++;a--;
                    ans.push_back('C');
                }
                else{
                    a++;c--;
                    ans.push_back('A');
                }
            }

        }
        
    }    
    cout<<"Yes"<<endl;
    while(!ans.empty()){
        char s = ans.front();
        cout<<s<<endl;
        ans.pop_front();
    }
}