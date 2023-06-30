#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int gcd(int a, int b)
{
	a=abs(a);
	b=abs(b);
	if(a==0) return b;
		return gcd(b,a%b);
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
struct phanso{
	long long a,b;
	
};
void nhap(phanso &p){
		do{
			cin>>p.a>>p.b;
			if(p.b==0) cout<<"Yeu cau nhap lai ";
		}
		while(p.b==0);
	}
void xuat(phanso &p){
	if(p.a>0&&p.b>0||p.a<0&&p.b<0)
		cout<<p.a<<"/"<<p.b<<endl;
	else if(p.a>0&&p.b<0||p.a<0&&p.b>0)
		cout<<"-"<<p.a<<"/"<<p.b<<endl;
	}
void rutgon(phanso &p){
		long long r=gcd(p.a,p.b);
		p.a=p.a/r;
		p.b=p.b/r;
	}
phanso tong(phanso &x,phanso &y){
		long long mc=lcm(x.b,y.b);
		x.a=(mc/x.b)*x.a;
		y.a=(mc/y.b)*y.a;
		x.a+=y.a;
		x.b=mc;
		return x;
	}
phanso hieu(phanso &x,phanso &y){
		long long mc=lcm(x.b,y.b);
		x.a=(mc/x.b)*x.a;
		y.a=(mc/y.b)*y.a;
		x.a-=y.a;
		x.b=mc;
		return x;
	}

int main(){
	struct phanso a,b;
	cout<<"Nhap phan so a:";
	nhap(a);
	cout<<"Phan so a la:";
	xuat(a);
	cout<<"Nhap phan so b:";
	nhap(b);
	cout<<"Phan so b la:";
	xuat(b);
	cout<<"Phan so a sau khi rut gon la:";
	rutgon(a);
	xuat(a);
	cout<<"Phan so b sau khi rut gon la:";
	rutgon(b);
	xuat(b);
	phanso c=tong(a,b);
	cout<<"Tong cua hai phan so la:";
	xuat(c);
	phanso d=hieu(a,b);
	cout<<"hieu cua hai phan so la:";
	xuat(d);
	
}
