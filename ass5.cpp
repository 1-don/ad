/* Assignment 5
Title: Implement all the functions of a dictionary(ADT) using Hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique Standard Operations: 
Insert(key, value), Find(key), Delete(key)
*/

#include<iostream>
using namespace std;
#define MAX 10

class hash
{
	private:
		struct abc
		{
			int k; int val;
		}a[MAX];
	public:
		void init();
		int hdiv(int);
		void insert(int,int,int);
		void display();
		void size();
		int search(int);
		void del(int);
};

void hash::init()
{
	for(int i=0;i<MAX;i++)
	{
		a[i].k=-1;
		a[i].val=-1;
	}
}

int hash::hdiv(int cnt)
{
	int hashkey;
	hashkey= cnt % 10;
	return hashkey;
}

void hash::insert(int index,int key,int value)
{
	int flag=0,i,count=0;
	if(a[index].k==-1)
	{
		a[index].k=key;
		a[index].val=value;
	}
	else
	{
		i=0;
		while(i<MAX)
		{
			if(a[i].k!=-1)
				count++;
			i++;
		}
		if(count==MAX)
		{
			cout<<"\n Hash Table is FULL";
		}
		for(i=index+1;i<MAX;i++)
			if(a[i].k==-1)
			{
				a[i].k=key;
				a[i].val=value;
				flag=1;
				break;
			}
		for(i=0;i<index && flag==0;i++)
			if(a[i].k==-1)
			{
				a[i].k=key;
				a[i].val=value;
				flag=1;
				break;
			}
	}
}

void hash::display()
{
	int i;
	cout<<"\n The Hash Table is::\n";
	cout<<"\n------------------------------";
	for(i=0;i<MAX;i++)
	{
		cout<<"\n\t| "<<i<<" | "<<a[i].k<<" | "<<a[i].val<<" | ";
	}
	cout<<"\n------------------------------";
}

void hash::size()
{
	int i,len=0;
	for(i=0;i<MAX;i++)
	{
		if(a[i].k!=-1)
		len++;
	}
	cout<<"\n The size of dictionary is::"<<len;
}

int hash::search(int s_key)
{
	int i,j,flag=0;
	i=hdiv(s_key);
	if(a[i].k==s_key)
	{
		cout<<"\n Record is present at location::"<<i;	
		flag=1;
		return i;
	}
	if(a[i].k!=s_key)
	{
		for(j=i;j<MAX;j++)
		{		
			if(a[j].k==s_key)
			{
				cout<<"\n Record is present at location::"<<j;	
				flag=1;
				return j;
			}		
		}
		for(j=0;j<i;j++)
		{		
			if(a[j].k==s_key)
			{
				cout<<"\n Record is present at location::"<<j;	
				flag=1;
				return j;
			}		
		}
	}
	if(flag==0)
	{
		cout<<"\n Record not found!!!";	
		return 0;
	}		
}

void hash::del(int key)
{
	int index;
	index=search(key);
	if(index!=-99)
	{
		a[index].k=-1;
		a[index].val=-1;
		cout<<"\n Record is deleted!!!";
	}
}
int main()
{
	int key,value,hashkey,s_key,ch;
	char ans;
	int index;
	hash h;
	cout<<"\n Dictionary Functions using Hashing";
	h.init();
	do
	{
		cout<<"\n 1. Insert";
		cout<<"\n 2. Display";
		cout<<"\n 3. Search";
		cout<<"\n 4. Delete";
		cout<<"\n    Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter the key::";
				cin>>key;
				cout<<"\n Enter the Value::";
				cin>>value;
				hashkey=h.hdiv(key);
				h.insert(hashkey,key,value);
				break;
			case 2:
				h.display();
				h.size();
				break;
			case 3:
				cout<<"\n Enter the key to be searched::";
				cin>>s_key;
				index=h.search(s_key);
				break;  
			case 4:
				cout<<"\n Enter the key to be deleted::";
				cin>>s_key;
				h.del(s_key);
				break;  
				
		}
		cout<<"\n Do U Want to Add More?...(y/n)";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}							          