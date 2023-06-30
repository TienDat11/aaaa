#include <bits/stdc++.h>
using namespace std;
string chuanhoa(string s){
	for(int i=0;i<s.length();i++){
		if(i==0) s[0] = toupper(s[0]);
		if(s[i]==' ') s[i+1] = toupper(s[i+1]);
		else s[i] = tolower(s[i]);
	}
	return s;
}
int main(){
	string s;
	getline(cin,s);
	cout<<chuanhoa(s)<<endl;
}
