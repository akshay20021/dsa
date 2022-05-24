#include<iostream>
using namespace std;

struct node{
	int data;
	node*lft;
	node*rgt;
}; 
class bst{
	public:
	int x,n,a;
	node*ptr;
	bst(){
		ptr=NULL;
	}
		node*root;
	node*newnode(int key){
	root=new node();
    root->data=key;
	root->lft=NULL;
	root->rgt=NULL;
	return root;
}
node*insert(node*temp,int key){
	if(temp==NULL){
		temp=newnode(key);
	}
	else if(temp->data>key){
		temp->lft=insert(temp->lft, key);
	}
	else{
		temp->rgt=insert(temp->rgt,key);
	}
	return temp;
}
int search(node*temp,int key){
	if(temp!=NULL){
		if(temp->data==key){
			cout<<"...Element found...."<<endl;
		}
		else if(key<temp->data){
			search(temp->lft,key);
		}
		else if(key>temp->data){
			search(temp->rgt,key);
		}
		else{
		     return 0;		}
	
	}
}
void maxval(node*temp){
	while(temp->rgt!=NULL){
		temp=temp->rgt;
	}
	cout<<"Maximum value is"<<temp->data<<endl;
}
void mirror(node*temp){
	if(temp==NULL){
		return ;
	}
	else{
	node*r;
	mirror(temp->lft);
	mirror(temp->rgt);
    r=temp->lft;
    temp->lft=temp->rgt;
    temp->rgt=r;
}
}

void input(){
	cout<<"Enter number of elements to be inserted:"<<endl;
	cin>>x;
	for(int i=1;i<=x;i++){
		cout<<"Number=";
		cin>>n;
		ptr=insert(ptr,n);
	
	}

}
	

void inorder(node*temp){
	
	if(temp!=NULL){
		inorder(temp->lft);
		cout<<temp->data;
		inorder(temp->rgt);
	}
}
void preorder(node*temp){
	if(temp!=NULL){
		cout<<temp->data;
		preorder(temp->lft);
		preorder(temp->rgt);
	}
}
void display(){
			
	cout<<"....Inorder......"<<endl;
	inorder(ptr);
	cout<<endl;
	cout<<"....Preorder......"<<endl;
	preorder(ptr);
	cout<<endl;
/*	cout<<"Enter no to search:"<<endl;
	cin>>a;
	search(ptr,a);
	cout<<endl;
	maxval(ptr);
*/
}
};

int main(){
bst b;
b.input();
b.display();
b.mirror(b.ptr);
b.display();
b.search(b.ptr,56);
return 0;
}

