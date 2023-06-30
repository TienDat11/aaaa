#include <bits/stdc++.h>
using namespace std;
struct ngaythang{
	int ngay,thang,nam;
	void nhap(){
		cout<<"Nhap ngay sinh:" ;cin>>ngay;
		cout<<"Nhap thang sinh:";cin>>thang;
		cout<<"Nhap nam sinh:" ;cin>>nam;
	}
	void in(){
		if(ngay<10)
		cout<<"0"<<ngay<<"/"<<"0"<<thang<<"/"<<nam<<endl;
		else if(thang<10) cout<<ngay<<"/"<<"0"<<thang<<"/"<<nam<<endl;
		else cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
	}
};
struct student{
	string hoten,gioitinh;
	ngaythang ngaysinh;
	double diem;
};
struct sinhvien{
	student s;
	sinhvien *Next;
};
typedef struct sinhvien* sv;
sv madenode(){
	student s;
	cout<<"Nhap ho va ten:"; cin.ignore(); getline(cin,s.hoten);
	cout<<"Nhap gioi tinh:"; cin>>s.gioitinh;
	s.ngaysinh.nhap();
	cout<<"Nhap diem:"; cin>>s.diem;
	sv tmp  = new sinhvien();
	tmp->s = s;
	tmp->Next = NULL;
	return tmp;
}
int size(sv a){
	int cnt = 0;
	while(a!=NULL){
		++cnt;
		a = a->Next;
	}
	return cnt;
}
void chendau(sv &a){
	sv tmp = madenode();
	if(a==NULL){
		a = tmp;
	}
	else{
		tmp->Next = a;
		a = tmp;
	}
}
void chencuoi(sv &a){
	sv tmp = madenode();
	if(a==NULL){
		a = tmp;
	}
	else {
		sv p = a;
		while(p->Next!=NULL){
			p = p->Next;
		}
		p->Next = tmp;
		p = tmp;
	}
}
void chenbatky(sv &a,int pos){
	int n = size(a);
	if(pos<=0 ){
		cout<<"Vi tri khong hop le";
	}
	else if(pos == 1){
		chendau(a); return;
	}
	else if(pos == n+1 ||pos>n+1){
		chencuoi(a);
		return;
	}
	else{
	sv p = a;
	for(int i = 1;i < pos;i++){
		p = p->Next;
	}
	sv tmp = madenode();
	tmp->Next = p->Next;
	p->Next = tmp;
}
}
void in(student s){
	cout<<"Ho va ten:"<<s.hoten<<" "<<"Gioi tinh:"<<"    "<<s.gioitinh<<" "<<s.diem<<"   "<<"Ngay sinh:";
	s.ngaysinh.in();
	cout<<endl;
}
void xoadau(sv &a){
		if(a == NULL) return ;
		a = a->Next;
}
void xoacuoi(sv &a){
	if(a == NULL) return;
	sv truoc = NULL, sau = a;
	while(sau->Next != NULL){
		truoc = sau;
		sau = sau->Next;
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->Next = NULL;
	}
}
void xoabatky(sv &a,int pos){
	if(pos <= 0 || pos < size(a)){
		xoacuoi(a);
	}
	sv truoc = NULL, sau = a;
	for(int i = 1; i < pos;i++){
		truoc = sau;
		sau = sau->Next;
	}
}
void inds(sv a){
	cout<<"Danh sach sinh vien:\n";
	while(a!=NULL){
		in(a->s);
		a = a->Next;
	}
	cout<<endl;
}
int main(){
	sv head = NULL;
	while(1){
		cout<<"------------------Menu-------------------\n";
		cout<<"1.Chen dau danh sach sinh vien\n";
		cout<<"2.Chen cuoi danh sach sinh vien\n";
		cout<<"3.Chen vao 1 vi tri bat ky trong danh sach lien ket\n";
		cout<<"4.In ra danh sach lien ket ma ban nhap\n";
		cout<<"5.Xoa dau danh sach lien ket\n";
		cout<<"6.Xoa cuoi danh sach lien ket\n";
		cout<<"7.Xoa bat ky danh sach lien ket\n";
		cout<<"0.Ket thuc\n";
		cout<<"------------------Menu-------------------\n";
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
		if(lc==5){
			xoadau(head);
		}
		if(lc==6){
			xoacuoi(head);
		}
		if(lc==7){
			cout<<"Nhap vi tri ma ban muon xoa:";
			int n; cin>>n;
			xoabatky(head,n);
		}
		if(lc==0){
			break;
		}
	}
}

