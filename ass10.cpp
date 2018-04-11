
/*
Assignment no::10
Problem Statement:: To create ADT that implements the SET concept.
a. Add (newElement) -Place a value into the set b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over
collection
e. Intersection of two sets, f. Union of two sets, g. Difference between two sets, h. Subset

*/

#include<iostream>
using namespace std;
class SET
{
        public:
                int a[20];
                int cnt;
        public:
                 SET( )
                 {
                        cnt=0;
                  }
                  void accept();
                  void display();
                  int size();
                  void remove();
                  void search(int x);
                  void intersection(SET A,SET B);
                  void union_(SET A, SET B);
                  void difference(SET A,SET B);
		  void subset(SET A,SET B);
};

void SET::accept()
{
        int temp;
        cout<<"\nEnter the element--->";
        cin>>temp;
        a[cnt]=temp;
        cnt++;
}
void SET::display()
{
        cout<<"\nElement is--->"<<"\n";
        for(int i=0;i<cnt;i++)
        {
                cout<<a[i]<<"\n";
        }        
}

int SET::size()
{
        cout<<"\nThe size of the SET is--->"<<cnt;
        
}

void SET::remove()
{
        cnt--;
         cout<<"\n The element has been deleted is--->"<<a[cnt];
}

void SET::search(int x)
{
        int flag=0;
         for(int i=0;i<cnt;i++)
        {
                if(a[i]==x)
                {
                
                        flag++;
                 }
       }
       if(flag==1)
               {
               cout<<"The element is found"<<x;
               }
       else
               {
               cout<<"The element is not found";
               }
}       
void SET::intersection(SET A,SET B)
{
        int flag=0;
        for(int i=0;i<A.cnt;i++)
        {
                        flag=0;
                 for(int j=0;j<B.cnt;j++)
                 {
                         if(A.a[i]==B.a[j])
                         {
                         flag++;
                         }
                }
                if(flag==1)
                {
                a[cnt]=A.a[i];
                cnt++;
                }
          }        
}  
void SET::union_(SET A,SET B)
{
        int flag=0;
        for(int i=0;i<A.cnt;i++)
        {
                a[cnt]=A.a[i];
                cnt++;
        }
        for(int i=0;i<B.cnt;i++)
        {
                flag=0;
                for(int j=0;j<cnt;j++)
                {
                                if(B.a[i]==a[j])
                                {
                                        flag++;
                                        break;
                                 }
               }
               if(flag==0)
               {
                        a[cnt]=B.a[i];
                                cnt++;
                }
        }                  
}

void SET::difference(SET A,SET B)
{
        int flag=0;
        for(int i=0;i<A.cnt;i++)
        {
                        flag=0;
                 for(int j=0;j<B.cnt;j++)
                 {
                         if(A.a[i]==B.a[j])
                         {
                         flag++;
                         break;
                         }
                }
                if(flag==0)
                {
                a[cnt]=A.a[i];
                cnt++;
                }
          } 
}       
void SET::subset(SET A,SET B)
{
	for(int i=0;i<B.cnt;i++)
		{
			for(int j=0;j<A.cnt;j++)
			{
				if(B.a[i]==A.a[j])
				{
					cnt++;
				}
			}
		}
			if(cnt==B.cnt)
			{
				cout<<"B is subset of A";
			}
			else
			{
				cout<<"B is not a subset of A";
			}
			
	
}
                           
int main()
{
        SET s1;
        SET A,B,C;
        int ch,x;
        do
        {
                cout<<"\n1.Insert\n2.Display\n3.Size\n4.Delete\n5.Search\n6.Intersection\n7.Union\n8.Difference\n9.Subset";
                cout<<"\nEnter your choice---->";
                cin>>ch;

                switch(ch)
                {
                                case 1:s1.accept();
                                        break;
                                case 2:s1.display();
                                        break;
                                case 3:s1.size();
                                        break;
                                case 4:s1.remove();
                                        break;
                                case 5: cout<<"\nEnter the element to be search--->";
                                        cin>>x;
                                        s1.search(x);
                                        break;  
                                case 6:  int n1,n;
                                        cout<<"How many no. of element want for SET A--->"; 
                                        cin>>n1;
                                        for(int i=0;i<n1;i++)
                                        {
                                                A.accept();
                                        }      
                                        cout<<"How many no. of element want for SET B--->"; 
                                        cin>>n;
                                        for(int i=0;i<n;i++)
                                        {
                                                B.accept();
                                        } 
                                        C.intersection(A,B);
                                        C.display();
                                        break;
                                case 7: int n2,n3;
                                        cout<<"How many no. of element want for SET A--->"; 
                                        cin>>n2;
                                        for(int i=0;i<n2;i++)
                                        {
                                                A.accept();
                                        }      
                                        cout<<"How many no. of element want for SET B--->"; 
                                        cin>>n3;
                                        for(int i=0;i<n3;i++)
                                        {
                                                B.accept();
                                        } 
                                        C.union_(A,B);
                                        C.display();
                                        break;
                               
                               case 8: int n4,n5;
                                        cout<<"How many no. of element want for SET A--->"; 
                                        cin>>n4;
                                        for(int i=0;i<n4;i++)
                                        {
                                                A.accept();
                                        }      
                                        cout<<"How many no. of element want for SET B--->"; 
                                        cin>>n5;
                                        for(int i=0;i<n5;i++)
                                        {
                                                B.accept();
                                        } 
                                        C.difference(A,B);
                                        cout<<"The elements which are A but not in B are--->";
                                        C.display();
                                        break;
				case 9:int n6,n7;
					cout<<"How many no. of element want for SET A--->"; 
                                        cin>>n6;
                                        for(int i=0;i<n6;i++)
                                        {
                                                A.accept();
                                        }      
                                        cout<<"How many no. of element want for SET B--->"; 
                                        cin>>n7;
                                        for(int i=0;i<n7;i++)
                                        {
                                                B.accept();
                                        } 
                                        C.subset(A,B);
					break;

                }
       }while(ch!=9);  
       return 0;                           
}                                
/*
Output:
	gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ sett.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->1

Enter the element--->11

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->1

Enter the element--->22

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->1

Enter the element--->33

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->1

Enter the element--->44

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->2

Element is--->
11
22
33
44

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->3

The size of the SET is--->4
1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset

Enter your choice---->4

 The element has been deleted is--->44

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->5

Enter the element to be search--->11
The element is found11
1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->77

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->5

Enter the element to be search--->77
The element is not found

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->6
How many no. of element want for SET A--->3

Enter the element--->11

Enter the element--->22

Enter the element--->33
How many no. of element want for SET B--->3

Enter the element--->11

Enter the element--->22

Enter the element--->44

Element is--->
11
22

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->7
How many no. of element want for SET A--->4

Enter the element--->10

Enter the element--->20

Enter the element--->30

Enter the element--->40
How many no. of element want for SET B--->4

Enter the element--->50

Enter the element--->60

Enter the element--->70

Enter the element--->80

Element is--->
10
20
30
40
50
60
70
80

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset

Enter your choice---->8
How many no. of element want for SET A--->4

Enter the element--->11

Enter the element--->22

Enter the element--->33

Enter the element--->44
How many no. of element want for SET B--->4

Enter the element--->11

Enter the element--->22

Enter the element--->77

Enter the element--->88
The elements which are A but not in B are--->
Element is--->
33
44
1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->9
How many no. of element want for SET A--->5

Enter the element--->10

Enter the element--->20

Enter the element--->30

Enter the element--->40

Enter the element--->50
How many no. of element want for SET B--->4

Enter the element--->10

Enter the element--->20

Enter the element--->30

Enter the element--->40
B is subset of A

1.Insert
2.Display
3.Size
4.Delete
5.Search
6.Intersection
7.Union
8.Difference
9.Subset
Enter your choice---->9
How many no. of element want for SET A--->4

Enter the element--->10

Enter the element--->20

Enter the element--->30

Enter the element--->40
How many no. of element want for SET B--->3

Enter the element--->10

Enter the element--->60

Enter the element--->70
B is not a subset of A


*/
 	               
                
              
