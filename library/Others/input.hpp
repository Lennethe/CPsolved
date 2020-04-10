#include <iostream>
#include <bits/stdc++.h>
//#include <Windows.h>
    
using namespace std;
#define FOR(i,n,m) for(int i=n; i<(int)m;i++)
 
// cin を用いることができないのでgetlineを使うメソッドを用意
vector<string> getline_string(){
    string line;
    getline(cin,line);
    line.push_back(' ');
    string tmp = "";
    vector<string> res;
    FOR(i,0,line.size()){
        if(line[i] == ' '){
            res.push_back(tmp);
            tmp = "";
        }
        else{
            tmp.push_back(line[i]);
        }
    }
    return res;
}
 
vector<int> getline_int(){
    vector<string> vs = getline_string();
    vector<int> res;
    FOR(i,0,vs.size()){
        res.push_back(stoi(vs[i]));
    }
    return res;
}
 
int get_int(){
    string line;
    getline(cin, line);
    istringstream first_line(line);
    int input_num;
    first_line >> input_num;
    return input_num;
}
/*
string str_rev(string str){
    char c;
    string answer;
    if(str=="END") return 0;
    do{
        c = str[0];
        if(IsDBCSLeadByte(c)==0){
            answer.insert(0,str.substr(0,1));
            str.erase(0,1);
        }else{
            answer.insert(0,str.substr(0,2));
            str.erase(0,2);
        }
    }while(!str.empty());
    return answer;
}*/
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n = get_int();
    vector<vector<string>> ans;
    while (!cin.eof()) {
    }

}