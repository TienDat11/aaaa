#include <bits/stdc++.h>
using namespace std;
string chuanhoa(string s){
	for(int i=0;i<s.length();i++){
		if(i==0) s[0]=toupper(s[0]);
		if(s[i]==' ') s[i+1]=toupper(s[i+1]);
		else s[i]=tolower(s[i]);
	}
}
struct sv{
	string ten,gioitinh;
	double diem;
	void in(){
		cout<<"----------------------------------------------------------\n";
		cout<<"Ten Sinh Vien:"<<ten<<" "<<"Gioi Tinh:"<<gioitinh<<" "<<"Diem:"<<diem<<endl;
		cout<<"----------------------------------------------------------\n";
	}
	void nhap(){
		cout<<"Nhap ten sinh vien:"; cin.ignore(); getline(cin,ten);
		cout<<"Nhap gioi tinh: "; cin>>gioitinh;
		cout<<"Nhap diem:"; cin>>diem;
	}
};
void inds(sv a[],int n){
	cout<<"Thong tin danh sach sinh vien:\n";
	for(int i=0;i<n;i++){
		a[i].in();
	}
}
void tbmsv(sv a[],int n){
	string s;
	cout<<"Nhap gioi tinh:";
	cin.ignore();
	getline(cin,s);
	int cnt=0;
	double sum=0;
	for(int i=0;i<n;i++){
		if(s==a[i].gioitinh){
			sum+=a[i].diem;
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		if(s==a[i].gioitinh){
			a[i].in();
		}
	}
	cout<<"Diem trung binh cua cac em "<<s<<":";
	cout<<sum/cnt<<endl;
}
void maxdiem(sv a[],int n){
	double res=0;
	for(int i=0;i<n;i++){
		if(a[i].diem > res) 
		res = a[i].diem;
	}
	cout<<"Danh sach sinh vien co diem cao nhat la:!\n";
	for(int i=0;i<n;i++){
		if(res==a[i].diem){
			a[i].in();
		}
	}
}
void mindiem(sv a[],int n){
	double res=10;
	for(int i=0;i<n;i++){
		if(a[i].diem < res) 
		res = a[i].diem;
	}
	cout<<"Danh sach sinh vien co diem cao nhat la:!\n";
	for(int i=0;i<n;i++){
		if(res==a[i].diem){
			a[i].in();
		}
	}
}
vector <string> chuanhoa1(string name){
	stringstream ss(name); vector<string>v;
	string tmp;
	while(ss>>tmp){
		v.push_back(tmp);
	}
	return v;
}
bool kieu(sv a, sv b){
	vector<string> v1 = chuanhoa1(a.ten), v2=chuanhoa1(b.ten);
	if(v1.back()!=v2.back()) return v1.back()< v2.back();
	int len1= v1.size(), len2= v2.size();
	for(int i=0;i<min(len1,len2);i++){
		if(v1[i]!=v2[i])
		return v1[i]<v2[i];
	}
	return len1<len2;
}
bool kieu1(sv a ,sv b){
	double diem1= a.diem;
	double diem2= b.diem;
	return diem1 < diem2;
}
void sxten(sv a[],int n){
	sort(a,a+n,kieu);
}
void sxdiem(sv a[],int n){
	sort(a,a+n,kieu1);
}
int main(){
	sv a[1000];
	int n=0;
	while(1){
		cout<<"----------------MENU----------------\n";
		cout<<"0.Ket Thuc\n";
		cout<<"1.Nhap Danh Sach Sinh Vien\n";
		cout<<"2.In danh sach sinh vien\n";	
		cout<<"3.Sap xep danh sach sinh vien theo ten\n";
		cout<<"4.Sap xep danh sach sinh vien theo diem\n";
		cout<<"5.Sinh vien co diem cao nhat\n";
		cout<<"6.Sinh vien co diem thap nhat\n";
		cout<<"7.Trung binh diem sinh vien theo gioi tinh ban tu chon\n";
		cout<<"------------------------------------\n";
		int v; cin>>v;
		if(v==1){
			a[n].nhap();
			++n;
		}
		else if(v==2){
			inds(a,n);
		}
		else if(v==3){
			sxten(a,n);
			inds(a,n);
		}
		else if(v==4){
			sxdiem(a,n);
			inds(a,n);
		}
		else if(v==5){
			maxdiem(a,n);
		}
		else if(v==6){
			mindiem(a,n);
		}
		else if(v==7){
			tbmsv(a,n);
		}
		else if(v==0){
			break;
		}
	}
}
