#include <bits/stdc++.h>
#include <math.h>
using namespace std;
struct thisinh{
	string ten,ns;
	float a,b,c;
};
void nhap(thisinh &p){
	getline(cin,p.ten);
	cin>>p.ns;
	cin>>p.a>>p.b>>p.c;
}
void in(thisinh p) {
	cout<<p.ten<<" "<<p.ns<<" "<<(p.a+p.b+p.c)<<endl;
}
int main(){
	struct thisinh a;
	nhap(a);
	in(a);
}
