#include <iostream>
using namespace std; 
class node
{
public:
	int data;
	node *left,*right;
	node(int x)
	{
		data=x; left=right=NULL;
	}
};

class BST
{
	node *root;
	void preorder(node * T);
 	int height(node * T);
	node * swap1(node * T);
	public:
	BST()
	{
		Root= NULL;
	}
	void insert(int x); 
	void create();
	void min();
	node *find(int x); 
	void preorder()
	{
		preorder1(root);
	}
	int height()
	{
		return (height 1 (root));
	}
	node* swap()
	{
		return(swap 1 (root));
	}
};

void BST::insert(int x)
{
	node *p,*q,*r; r=new node(x); 
	if(root=NULL)
	{
		root=r;
		return;
	}
	p=root;
	while(p!=NULL)
	{
		q=p;
		if(x>p->data)
			p=p->right;
		else
			p=p->left;
	}
	if(x>q->data) 
		q->right=r; 
	else
		q->left=r;
}

void BST::create()
{
	int n,x,i;
	root=NULL;
	cout<<"\nEnter the no of nodes::"; 
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		insert(x);
	}
}
void BST::preorderl(node *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" ";
		preorder1(T->left); 
		preorder1(T->right);
	}
}

int BST::height1(node *T)
{
	int hl,hr;
	if(T==NULL)
		return 0;
	if(T->left==NULL && T->right=NULL) 
		return 0:
	hl=height(T->left); 
	hr=height(T->right); 
	if(hl>hr)
		return(hl+1);
	return (hr+1);
}
void BST::min()
{
	node *T;
	T=root; 
	while(T->left!=NULL) 
		T=T->left;
	cout<<" \nMinimum value node in tree::"<<T->data;
}

node *BST::find(int x)
{
	node *T;
	T=root; 
	while(T!=NULL)
	{
		if(T->data==x)
			return T;
		if(x>T->data)
			T=T->right;
		else
			T=T->left;
	}
	return NULL;
}

node BST::swap1(node *T)
{
	node *temp; 
	if(T!=NULL)
	{
		temp=T->left; 
		T->left=swap1(T->right);
		T->right=swap1(temp); 
	}
	return T;
}

int main()
{
	BST b;
	node *p; 
	int x,ch; 
	do
	{
		cout<<"\n1.Create 	2.Display(Preorder)";
		cout<<"\n3.1nsert 	4.No. of nodes in longest path";	
		cout<<"\n5.Min node	6.Search ";
		cout<<"\n7.Swap nodes 	8.Exit";

		cout<<"\nEnter your choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:	b.create();	
				break;
			case 2:	b.preorder(); 	
				break;
			case 3:	cout<<"\nEnter the data to insert";
				cin>>x;
				b.insert(x); 	
				break;
			case 4:	x=b.height(); 
				cout<<"\nNo of nodes in longest path="<<x+1; 
				break;
			case 5:	b.min();	
				break;
			case6:	cout<<"\nEnter the data to search";
					cin>>x;
				b.find(x);	
				break;

			case 7:	b.swap1();	
				break;
		}
	}while(ch!=8);
}



