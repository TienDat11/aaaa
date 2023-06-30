#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(){
	string s;
	cin>>s;
	set<char>se;
	for(char x:s){
		se.insert(x);
	}
	if(se.size()==26) cout<<"Yes!\n";
	else cout<<"No!\n";
}
