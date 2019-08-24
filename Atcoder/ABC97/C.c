#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string s;
	int k;
	char w;
	w = 'a';
	
	int num;
	num = 0;
	vector<vector<char>> vec(3, vector<char>(0));
	
	cin >> s >> k;
	
	while( w <= 'z'){
		for(int i=0; std::abs(i)<s.size(); i++){
			
			if(s.at(i) == w){
				
				for(int j=0; j<5 || std::abs(i+j) < s.size() || j<k; j++){
					vec.at(num).push_back(s.at(i+j));
					cout << vec.at(num).at(j)  << endl;
					if(j==4) {
						i=s.size();
						w='z';
					};
				}
				cout << "asd" << endl;
				
				num++;
				if(num == 4){
					i=s.size();
					w='z';
				}
			}
		}
		w++;
	}
	
	for(int i=0; i<k; i++){
			cout << vec.at(0).at(i);
		}
	
	if(vec.at(0).size() >= std::abs(k) ){
		for(int i=0; i<k; i++){
			cout << vec.at(0).at(i) << endl;
		}
	}
	else {

		int a;
		if(vec.at(0).size() < vec.at(1).size()) a = vec.at(0).size();
		else a = vec.at(1).size();
		for(int j=0; j<a; j++){
			if(vec.at(0).at(j) == vec.at(1).at(j)){
				k++;
			}
		}
		
		k=k - vec.at(0).size() - 1;
		for(int i=0; i<k; k++){
			cout << vec.at(1).at(i) << endl;
		}
		
		
	}
	
}
