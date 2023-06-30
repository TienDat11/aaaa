#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
int main(){
int *p1,*p2;
p1= (int*)malloc(sizeof(int));
*p1=5;
p2=(int*)calloc(10,sizeof(int));
*(p2+3)=5;
cout<<"P1="<<*p1<<endl;
cout<<"P2[3]="<<*(p2+3)<<endl;
free(p1); free(p2);
cout<<*p1<<" "<<*p2<<endl;
int*p3=new int[4];
*p3=1;
p3[2]=5;
cout<<*p3<<" "<<p3[2]<<endl;
delete p3;
cout<<*p3<<endl;n
}
