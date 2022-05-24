#include<iostream>
using namespace std;
struct node{
	int chcount;
	char name[50];
	node*child[50];
}*root;  
class tree{
	public:
		int i,j,k;
	void insert();
	void display();
	tree(){
		root=NULL;
	}
};
void tree::insert(){
	
	root=new node();
	cout<<"Enter name of book"<<endl;
	cin>>root->name;
	cout<<"Enter no of chapters in book"<<endl;
	cin>>root->chcount;
	for(i=1;i<=root->chcount;i++){
		root->child[i]=new node;
		cout<<"Enter names of chapters"<<endl;
		cin>>root->child[i]->name;
		cout<<"Enter no of sections in chapter"<<endl;
		cin>>root->child[i]->chcount;
		for(j=1;j<=root->child[i]->chcount;j++){
			root->child[i]->child[j]=new node();
			cout<<"Enter name of sections"<<endl;
			cin>>root->child[i]->child[j]->name;
			cout<<"Enter no of subsections in sections"<<endl;
			cin>>root->child[i]->child[j]->chcount;
			for(k=1;k<=root->child[i]->child[j]->chcount;k++){
				root->child[i]->child[j]->child[k]=new node();
				cout<<"Enter name of subsections"<<endl;
				cin>>root->child[i]->child[j]->child[k]->name;
			}
		}
	}
}
void tree::display(){
	cout<<"Book name:";
	cout<<root->name<<endl;
	for(i=1;i<=root->chcount;i++){
		cout<<"Chapters in book:";
		cout<<root->child[i]->name<<endl;
		for(j=1;j<=root->child[i]->chcount;j++){
			cout<<"Sections in chapter:";
			cout<<root->child[i]->child[j]->name<<endl;
			for(k=1;k<=root->child[i]->child[j]->chcount;k++){
				cout<<"Sub sections on section:";
				cout<<root->child[i]->child[j]->child[k]->name<<endl;
			}
		}
	}
}

int main(){
tree t;
t.insert();
t.display();
return 0;
}

