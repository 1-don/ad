#include<iostream>
using namespace std;
#define size 10

class opt
{
	int p[size],q[size],a[size],w[size][size],c[size][size],r[size][size];
	int n,front,rear,que[20];
	public:
		opt();
		void getdata();
		int minval(int,int);
		void obst();
		void buildtree();
};

opt::opt()
{
	front=rear=-1;
}

void opt::getdata()
{
	int i;
	cout<<"\n Optimal binary search tree \n";
	cout<<"\n Enter the no of nodes::\t";
	cin>>n;
	cout<<"\n Enter the data::\n";
	for(i=1;i<=n;i++)
	{
		cout<<"\n a["<<i<<"]";
		cin>>a[i];
	}
	cout<<"\n Enter probabilities for successful search\n";
	for(i=1;i<=n;i++)
	{
		cout<<"\n p["<<i<<"]";
		cin>>p[i];
	}
	cout<<"\n Enter probabilities for unsuccessful search\n";
	for(i=0;i<=n;i++)
	{
		cout<<"\n q["<<i<<"]";
		cin>>q[i];
	}
}

int opt::minval(int i,int j)
{
	int m,k;
	int minimum=32000;
	for(m=r[i][j-1];m<=r[i+1][j];m++)
	{
		if((c[i][m-1]+c[m][j])<minimum)
		{
			minimum=c[i][m-1]+c[m][j];
			k=m;
		}
	}
	return k;
}

void opt::obst()
{
	int i,j,k,m;
	for(i=0;i<n;i++)
	{
		w[i][i]=q[i];
		r[i][i]=c[i][i]=0;

		w[i][i+1]=q[i]+q[i+1]+p[i+1];
		r[i][i+1]=i+1;
		c[i][i+1]=q[i]+q[i+1]+p[i+1];
	}
	w[n][n]=q[n];
	r[n][n]=c[n][n]=0;
	
	for(m=2;m<=n;m++)
	{
		for(i=0;i<=n-m;i++)
		{
			j=i+m;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			k=minval(i,j);
			c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
			r[i][j]=k;
		}
	}
}

void opt::buildtree()
{
	int i,j,k;
	cout<<"\n\t The root of OBST is::"<<r[0][n];
	cout<<"\n\t The cost of OBST is::"<<c[0][n];
	cout<<"\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD";
	cout<<"\n\t-------------------------------------------"<<endl;
	que[++rear]=0;
	que[++rear]=n;
	while(front!=rear)
	{
		i=que[++front];
	
		j=que[++front];
	
		k=r[i][j];
		
		cout<<"\n\t"<<k;
		
		if(r[i][k-1]!=0)
		{
			cout<<"\t\t"<<r[i][k-1];
			que[++rear]=i;
			que[++rear]=k-1;
		}
		else
			cout<<"\t\t-";
		if(r[k][j]!=0)
		{
			cout<<"\t\t"<<r[k][j];
			que[++rear]=k;
			que[++rear]=j;
		}
		else
			cout<<"\t\t-";
	}
		cout<<"\n";
}

int main()
{
	opt o;
	o.getdata();
	o.obst();
	o.buildtree();
}