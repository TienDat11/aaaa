#include <bits/stdc++.h>
#include <math.h>
using namespace std;
struct diem{
	double x,y;
};
void input(diem &p){
	cin>>p.x>>p.y;
}
double khoangcach(diem a,diem b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int main(){
	struct diem a,b;
	int t;
	cin>>t;
	while(t--){
		cout<<"Nhap toa do 1:";
		input(a);
		cout<<"Nhap toa do 2:";
		input(b);
		cout<<"Khoang cach cua 2 toa do 1 va 2 la:"<<khoangcach(a,b)<<endl;
	}
}
