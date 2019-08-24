
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int N, M;
	cin >> N >> M;
	
	int flag1, flag2;
	
	vector<int> P(N);
	vector<vector<int>> vecxy = vector<vector<int>>(M, vector<int>(2,0));
	vector<vector<int>> mat;
	
	for(int i=0; i<N; i++){
		cin >> P.at(i);
	}
	
	for(int i=0; i<M; i++){
		cin >> vecxy.at(i).at(0) >> vecxy.at(i).at(1);
	}
	
	cout << "size = " << vecxy.size() << endl;
	cout << "size = " << vecxy.at(0).size() << endl;
	
	
	
	mat.push_back(vector<int>(0));
	mat.at(0).push_back(vecxy.at(0).at(0));
	mat.at(0).push_back(vecxy.at(0).at(1));
	
	
	for(int a=0; a<M; a++){
		for(int i=0; i<(int)mat.size(); i++){
			flag1 = 0;
			flag2 = 0;
			for(int j=0; j<(int)mat.at(i).size(); j++){
				if(mat.at(i).at(j)==vecxy.at(a).at(0)) flag1 = 1;
				if(mat.at(i).at(j)==vecxy.at(a).at(1)) flag2 = 1;
				
				
	cout << "here a = " << a << " i = " << i << " j = " << j  << endl;
			}
			
			if(flag1 == 1 && flag2 == 0) {
				mat.at(i).push_back(vecxy.at(a).at(1));
				i = mat.size();
				cout << "Im through1?" << endl;
			}
			else if(flag1 == 0 && flag2 == 1) {
				mat.at(i).push_back(vecxy.at(a).at(0));
				i = mat.size();
				cout << "Im through2?" << endl;
			
			}
			else if(flag1 == 0 && flag2 == 0 && i == (int)mat.size()-1){
				mat.push_back(vector<int>(0));
				mat.at(mat.size()-1).push_back(vecxy.at(a).at(0));
				mat.at(mat.size()-1).push_back(vecxy.at(a).at(1));
				cout << "Im through3?" << endl;
			
			}
			else cout << "another problem" << endl;
			
		}
		
		
	}
	
	cout << "mat.size = " << mat.size() << endl;
	
	for(int i=0; i<(int)mat.size(); i++){
		for(int j=0; j<(int)mat.at(i).size(); j++){
			cout << mat.at(i).at(j) <<  " " ;
		}
		
	}
	cout << " " << endl;
	
}