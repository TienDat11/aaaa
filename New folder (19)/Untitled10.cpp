#include <bits/stdc++.h>
using namespace std;
struct NgayThang{
	int Ngay,Thang,Nam;
	void nhap(){
		do{
		cout<<"Nhap ngay:"; cin>>Ngay;
		cout<<"Nhap Thang:"; cin>>Thang;
		cout<<"Nhap Nam:"; cin>>Nam;
		if(Ngay<=0&&Thang<=0&&Nam<=0) cout<<"Yeu cau nhap lai:"<<endl;
		}
		while(Ngay<=0&&Thang<=0&&Nam<=0);
	}
	void in(){
		if(Ngay<10)
		cout<<"0"<<Ngay<<"/"<<"0"<<Thang<<"/"<<Nam<<endl;
		else if(Thang<10) cout<<Ngay<<"/"<<"0"<<Thang<<"/"<<Nam<<endl;
		else cout<<Ngay<<"/"<<Thang<<"/"<<Nam<<endl;
	}
	
};
bool namnhuan(NgayThang a){
	if(a.Nam%400==0)
		return true;
	if(a.Nam%4==0&&a.Nam%100!=0)
		return true;
	return false;
}
int monthday(NgayThang a){
	int songay=0;
	switch(a.Thang){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			songay+=31;
			break;
		case 2:
			if(namnhuan(a)) songay+=29;
			else songay+=28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			songay+=30;
			break;
	}
	return songay;
}
int thoidiem(NgayThang a){
	NgayThang b;
	long long songay;
	songay = a.Ngay;
	for(int i=1;i<a.Thang;i++){
		b.Ngay = 1;
		b.Thang = i;
		b.Nam = a.Nam;
		songay +=monthday(b);
	}
	for(int i=1;i<a.Nam;i++){
		b.Ngay  = 1;
		b.Thang = 1;
		b.Nam = i;
		if(namnhuan(b)) songay += 366;
		else songay +=365;
	}
	return songay;
}
void Khoangcach(NgayThang a){
	NgayThang b;
	cout<<"Nhap ngay ma ban muon so sanh"<<endl;
	b.nhap();
	b.in();
	cout<<"So ngay cach nhau la:"<<abs(thoidiem(a)-thoidiem(b));
}
void ThuNgay(NgayThang a){
	int n=thoidiem(a);
	if(n%7==6) cout<<"Thu 7"<<endl;
	else if(n%7==0) cout<<"Chu Nhat"<<endl;
	else if(n%7==1) cout<<"Thu hai"<<endl;
	else if(n%7==2) cout<<"Thu 3"<<endl;
	else if(n%7==3) cout<<"Thu 4"<<endl;
	else if(n%7==4) cout<<"Thu 5"<<endl;
	else if(n%7==5) cout<<"Thu 6"<<endl;
}
int main(){
	NgayThang n;
	n.nhap();
	n.in();
	if(namnhuan(n)!=0){
		cout<<"La Nam Nhuan"<<endl;
	}
	else cout<<"Ko Phai Nam Nhuan"<<endl;
	cout<<"So Ngay cua thang "<<n.Thang<<" la  "<<monthday(n)<<" ngay"<<endl;
	cout<<thoidiem(n)<<endl;
	cout<<"Nhap thoi diem so sanh !!!"<<endl;
	cout<<"So sanh giua 2 ngay"<<endl;
	Khoangcach(n);
	cout<<endl;
	cout<<"Ngay hom nay la ";
	n.in();
	ThuNgay(n);
}
