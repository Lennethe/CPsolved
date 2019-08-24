#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int H,W,flag;
	cin >> H >> W;
	
	vector<vector<char>> vec = vector<vector<char>>(H+2,vector<char>(W+2,'.'));
	
	for(int i=1; i<H+1; i++){
		for(int j=1; j<W+1; j++){
			cin >> vec.at(i).at(j);
		}
	}
	flag = 0;
	
	for(int i=1; i<H+1; i++){
		for(int j=1; j<W+1; j++){
			if(vec.at(i).at(j) == '#'){
				if((vec.at(i).at(j+1) == '#') || (vec.at(i+1).at(j) == '#') || vec.at(i-1).at(j) == '#' || vec.at(i).at(j-1) == '#'){
				
				
				}
				else {
					flag = 1;
					break;
				}
			}
		}
	}
	

	if(flag == 1) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	
}
