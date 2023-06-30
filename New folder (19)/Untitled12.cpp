#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=n;i<=m;i++){
		if(i%4==0||i%4==1) sum+=i;
		else sum-=i;
	}
	cout<<sum;
}
