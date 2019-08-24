#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int H,W;
	cin >> H >> W;
	
	vector<vector<char>> vec1 = vector<vector<char>>(H,vector<char>(W,'a'));
	vector<vector<char>> vec2 = vector<vector<char>>(W,vector<char>(H,'a'));
	
	
	
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			char a;
			cin >> a;
			vec1.at(i).at(j) = a;
			vec2.at(j).at(i) = a;
			
		}
	}	

	/*
	for(int i=0; i<H; i++){
		std::sort(vec1.at(i).begin(),vec1.at(i).end());
	}
	std::sort(vec1.begin(), vec1.end());
	for(int i=0; i<W; i++){
		std::sort(vec2.at(i).begin(),vec2.at(i).end());
	}
	std::sort(vec2.begin(),vec2.end());
	*/
	
	
	int flag1=0;
	while((int)vec1.size()>0 && flag1==0){
		
		for(int i=1; i<(int)vec1.size(); i++){
			if(vec1.at(0)==vec1.at(i)){
				vec1.erase( vec1.begin());
				
				cout<<"kitewitk"<<endl;
				break;
			}
			if(i==(int)vec1.size()) flag1=1;
		}
		
		cout<< "size=" << vec1.size()<< " flag1=" << flag1   <<endl;
	
		for(int i=0; i<(int)vec1.size(); i++){
			for(int j=0; j<W; j++){
				cout<<vec1.at(i).at(j);
			}
			cout << endl;
		}
		
	}
	while((int)vec1.at(0).size()>0 && flag1==1){
		for(int i=1; i<(int)vec1.at(0).size(); i++){
			if(vec1.at(0).at(0)==vec1.at(0).at(i)){
				vec1.at(0).erase( vec1.at(0).begin(), vec1.at(0).begin()+i);
				break;
			}
			if(i==(int)vec1.at(0).size()) flag1=2;
		}
		if(vec1.at(0).size()<2) flag1=0;
	}
	
	
	cout<< flag1 << endl;
	
	
	cout<< endl;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cout << vec1.at(i).at(j);
		}
		cout<< endl;
	}	
	
	cout<<endl;
	for(int i=0; i<W; i++){
		for(int j=0; j<H; j++){
			cout << vec2.at(i).at(j);
		}
		cout<< endl;
	}	
	
	
}
