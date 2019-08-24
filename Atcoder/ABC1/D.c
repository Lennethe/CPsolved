#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a ;
	string b, result,w,x,y,z;
	
	cin >> a;
	vector<int> vec(a*2, 0);
	vector<int> memo(2500, 0);
	
	for(int i =0; i<a; i++){
		cin >> b;
		
		w = b.at(0);
		x = b.at(1);
		y = b.at(2);
		z = b.at(3);
		
		result = w+x+y+z;
		
		cout << b.at(0) + b.at(1) + b.at(2) + b.at(3) << endl;
		cout << '1' + '2' + '3' + '4' << endl;
		
		vec.at(2*i) = std::stoi(result);
		vec.at(2*i) = vec.at(2*i) - vec.at(2*i)%5;
		
		w = b.at(5);
		x = b.at(6);
		y = b.at(7);
		z = b.at(8);
		result = w+x+y+z;
		vec.at(2*i+1) = std::stoi(result);
		vec.at(2*i +1) = vec.at(2*i+1)/5*5 + 5*(bool)(vec.at(2*i+1)%5);
		
		if (std::stoi(y) == 5 && std::stoi(z) >= 6 ) vec.at(2*i + 1) = vec.at(2*i+1) + 40;
	}

	for(int i=0; i<a; i++){
		
		for(int j=vec.at(2*i); j<= vec.at(2*i+1); j++){
			memo.at(j)=1;
		}
	}

	int pre = 0;
		
	for(int i=0; i<2500; i++){
		
		if(memo.at(i) != pre && pre == 0){
			if(i < 10) cout << "000" ;
			else if(i < 100) cout << "00" ;
			else if(i < 1000) cout << "0" ;
			
			cout << i << "-"  ;
			pre = 1;
		}
		
		if(memo.at(i) != pre && pre == 1){
			if(i < 10) cout << "000" ;
			else if(i < 100) cout << "00" ;
			else if(i < 1000) cout << "0" ;
			cout << i-1 << endl ;
			pre = 0;
		}
	}
}

