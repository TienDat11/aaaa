#include<bits/stdc++.h>
using namespace std;
struct student{
	string hoten,gioitinh;
	string ngaysinh;
	
};
struct SinhVien{
	student s;
	SinhVien *next;
};
typedef struct SinhVien* sv;
sv madenode(){
	student s;
	cout<<"Nhap ten sinh vien:"; cin.ignore(); getline(cin,s.hoten);
	cout<<"Nhap gioi tinh :"; cin>>s.gioitinh;
	cout<<"Nhap ngay sinh:"; cin.ignore(); getline(cin,s.ngaysinh);cout<<endl;
	sv tmp = new SinhVien();
	tmp->s = s;
	tmp->next=NULL;
}

int size(sv a){
	int cnt=0;
	while(a!=NULL){
		a=a->next;
		++cnt;
	}
	return cnt;
}
void chendau(sv &a){
	sv tmp = madenode();
	if(a==NULL){
		a=tmp;
	}
	else{
		tmp->next = a;
		a = tmp ;
	}
}
void chencuoi(sv &a){
	sv tmp = madenode();
	if(a==NULL){
		a=tmp;
	}
	else{
		sv p = a;
		while(p->next!=NULL){
			p = p->next;
		}
		p->next=tmp;
	}
}
void chenbatky(sv &a,int pos){
	int n = size(a);
	if(pos<=0 || pos > n+1){
		cout<<"Vi tri k hop le"<<endl;
	}
	if(n==1){
		chendau(a); return;
	}
	else if(n==pos+1){
		chencuoi(a); return;
	}
	sv p = a;
	for(int i=1;i<pos-1;i++){
		p=p->next;
	}
	sv tmp = madenode();
	tmp->next = p->next;
	p->next = tmp;
}
void in(student s){
	cout<<"--------------------------------------\n";	 
	cout<<"Ho va ten"<<s.hoten<<" "<<" Gioi tinh: "<<s.gioitinh<<" "<<"Ngay Sinh:"<<s.ngaysinh<<endl;
}
void inds(sv a){
	cout<<"Danh sach sinh vien:\n";
	while(a!=NULL){
		in(a->s);
		a=a->next;
	}
	cout<<endl;
	cout<<"-------------------------------------\n";
}
int main(){
	sv head = NULL;
	while(1){
		cout<<"------------------Menu-------------------\n";
		cout<<"1.Chen dau danh sach sinh vien\n";
		cout<<"2.Chen cuoi danh sach sinh vien\n";
		cout<<"3.Chen vao 1 vi tri bat ky trong danh sach lien ket\n";
		cout<<"4.In ra danh sach lien ket ma ban nhap\n";
		cout<<"0.Ket thuc\n";
		int lc;
		cin>>lc;
		if(lc==1){
			chendau(head);
		}
		if(lc==2){
			chencuoi(head);
		}
		if(lc==3){
			cout<<"Nhap vi tri ma ban muon chen:";
			int pos; cin>>pos;
			chenbatky(head,pos);
		}
		if(lc==4){
			inds(head);
		}
		if(lc==0){
			break;
		}
	}
}
