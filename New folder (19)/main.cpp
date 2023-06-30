#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
void viethoa(string &s){
	for(int i=0;i<s.length();i++){
		s[i]=toupper(s[i]);
	}

}
void chuanhoa(string &s){
	s[0]=toupper(s[0]);
	for(int i=1;i<s.length();i++){
		s[i]=tolower(s[i]);
	}

}
int main(){
	int t; cin>>t;
	map<string,int>mp;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		vector<string>v;
		while(ss>>tmp)
		v.push_back(tmp);
		viethoa(v[v.size()-1]);
		cout<<v[v.size()-1]<<",";
		for(int i=0;i<v.size()-1;i++){
			chuanhoa(v[i]);
			cout<<v[i];
			if(i!=v.size()-2) cout<<" ";
		}
		cout<<endl;
	}
	
}
