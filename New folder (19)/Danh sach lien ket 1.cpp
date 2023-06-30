#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* Next;
};
typedef struct Node* node;
node inserthead(int x){
	node tmp = new Node();
	tmp->data = x;
	tmp->Next = NULL;
	return tmp;
}
void sapxep(node &a){
	for(node p =a;p->Next = NULL;p=p->Next){
		node min = p;
		for(node q=p->Next;q!=NULL;q=q->Next){
			if(q->data < min->data){
				min=q;
			}
		}
		int tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}
int size(node a){
	int cnt=0;
	while(a!=NULL){
		++cnt;
		a = a->Next;
	}
	return cnt;
}
node trung(node &a){
	node tmp ;
	set<int>s;
	while(a!=NULL){
		s.insert(a->data);
		a=a->Next;
	}
	for(auto x:s){
		tmp->data = x;
		tmp = tmp->Next;
	}
	tmp->Next = NULL;
	return tmp;
}
void in(node &a){
	while(a!=NULL){
		cout<<a->data<<" ";
		a = a->Next;
	}
}
int main(){
	node head = NULL;
	int n; cin>>n;
	while(n--){
		int x;
		cin>>x;
		head = inserthead(x);
	}
	in(head);
}


