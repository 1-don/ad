#include<iostream>
using namespace std;

class Bnode
{
	public:
		char data[50];
		Bnode *lchild,*rchild;
};

class Booktree
{
	public:
		Bnode *root,*temp;
		Booktree()
		{
			root=NULL;
		}
		void create();
		void insert(Bnode *, Bnode *);
		int height(Bnode *);
		void print(Bnode *);
}; 	

void Booktree::create()
{
	char ch1='y';
	do
	{
		temp=new Bnode;	
		cout<<"\n Enter the Element";
		cin>>temp->data;
		temp->lchild= NULL;
		temp->rchild= NULL;
		
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);
		cout<<"\n do you want to enter more elements?(y/n)\t";
		cin>>ch1;
	}while(ch1 == 'y'||ch1 == 'Y');
}

void Booktree::insert(Bnode *root,Bnode *temp)
{
	char ch2;
	cout<<"\n Where do u want to insert?(left/right)"<<"of"<<root->data;
	cin>>ch2;
	if(ch2 == 'l'||ch2 == 'L')
	{
		if(root->lchild==NULL)
			root->lchild=temp;
		else
			insert(root->lchild,temp);
	}
	else
	{
		if(root->rchild == NULL)
			root->rchild=temp;
		else
			insert(root->rchild,temp);
	}
}

void Booktree::print(Bnode *root)
{
	int h= height(root),level;
	for(int i=0; i<h; i++)
	{
		cout<<"\n";
		if(root==NULL)
			return;
		if(level==1)
			cout<<" "<<root->data;
		else if(level>1)
		{
			print(root->lchild);
			print(root->rchild);
			level--;
		}
	}
}
	

int Booktree::height(Bnode *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int lht=height(root->lchild);
		int rht=height(root->rchild);
		if(lht>rht)
			return(lht+1);
		else
			return(rht+1);
	}
}

int main()
{
	int ch;
	Booktree B;
	do
	{
		cout<<"\n\t--------Menu--------";
		cout<<"\n\t\t 1.Create";
		cout<<"\n\t\t 2.Display";
		cout<<"\n\t\t 3.Exit";
		cout<<"\n\t\t Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:	B.create();	
				break;
			case 2:	if(B.root==NULL)
					cout<<"\n\t Tree is empty";
				else
					B.print(B.root);
				break;
		}
	}while(ch!=3);
}
