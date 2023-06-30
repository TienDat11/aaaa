#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
typedef struct Node* node;
node makenode(int x){
	node tmp = new Node();
	tmp->data=x;
	tmp->next=Null;
	return tmp;
}
bool empty(node a){
	return a == Null;
}
int size(node a){
	int cnt=0;
	while(a!=Null){
		a = a->next;
		cnt++;
	}
	return cnt;
}
void insertfirst(node &a,int x){
	node tmp = makenode(x);
	if(a==Null){
		a=tmp;
	}
	else{
		tmp->next=a;
		a=tmp;
	}
}
int main(){
	node head = Null;
	return 0;
}
