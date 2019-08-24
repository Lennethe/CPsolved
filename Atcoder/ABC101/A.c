#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	
	string S;
	int l=0;
	
	cin >> S ;
	
	for(int i=0; i<(int)S.size(); i++){
		
		if(S.at(i) == '+') l++;
		else l--;
		
	}
	
	cout << l << endl;
}
