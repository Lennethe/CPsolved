#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int N,M,x,y,flag ;
	cin >> N >> M;
	vector<vector<int>> vec = vector<vector<int>>(0, vector<int>(0));
	vector<int> input(N);
	
	for(int i=0; i<N; i++){
		cin >> input.at(i);
	}
	
	for(int i=0; i<M; i++){
		cin >> x >> y;
		
		flag = 0; 
		
		cout<<vec.size() << endl;
		
		for(int j=0; std::abs(j)<vec.size(); j++){
			for(int k=0; std::abs(k)<vec.at(j).size(); k++){
				if(vec.at(j).at(k) == x || vec.at(j).at(k) == y){
					flag = 1;
					vec.at(j).push_back(x);
					vec.at(j).push_back(y);
					cout << "through" << endl;
					break;
					//k = vec.at(j).size();
					//j = vec.size();
				}
			}
		}
		
		cout << "flag = " << flag << endl;
		
		if(flag == 0){
			vec.push_back(vector<int>(0));
			vec.at(vec.size() - 1).push_back(x);
			vec.at(vec.size() - 1).push_back(y);
		}
		cout << "size = " << vec.size()<<endl;
		
	}
	
	for(int i=0; std::abs(i)<vec.size(); i++){
		cout << "This group is" << i << " = ";
		for(int j=0; std::abs(j)<vec.at(i).size(); j++){
			cout << vec.at(i).at(j) << " ";
		}
		cout << endl;
		
	}
	
	
}
