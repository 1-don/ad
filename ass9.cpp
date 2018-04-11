#include <iostream>
using namespace std;

    void max_heapify(int *a, int i, int n)
    {
        int j, temp;
        temp = a[i];
        j = 2*i;
        while (j <= n)
        {
            if (j < n && a[j+1] > a[j])
                j = j+1;
            if (temp > a[j])
                break;
            else if (temp <= a[j])
            {
               	a[j/2] = a[j];
               	j = 2*j;
            }

        }
        a[j/2] = temp;
        return;
    }

    void heapsort(int *a, int n)
    {
        int i, temp;
        for (i = n; i >= 2; i--)
        {
            temp = a[i];
            a[i] = a[1];
            a[1] = temp;
            max_heapify(a, 1, i - 1);
        }

    }

    void build_maxheap(int *a, int n)
    {
        int i;
        for(i = n/2; i >= 1; i--)
        {
            max_heapify(a, i, n);
        }
    }
    
    void max_min(int *a, int n)
    {
      int  small=a[0];
      cout<<"\nmin= "<<a[1]<<endl;
      cout<<"\nmax= "<<a[n]<<endl;
    }

    int main()
    {
        int n, i, x;
        cout<<"enter no of elements of array\n";
        cin>>n;
        int a[20];
        for (i = 1; i <= n; i++)
        {
            cout<<"enter element"<<(i)<<endl;
            cin>>a[i];
        }
        build_maxheap(a,n);
        heapsort(a, n);
        cout<<"sorted output\n";
        for (i = 1; i <= n; i++)
        {
            cout<<a[i]<<endl;
        }
	max_min(a,n);
        return 0;

    }

/*----------------output-------------------
sh-4.2$ g++ -o main *.cpp                                                                                                                    
sh-4.2$ main                                                                                                                                 
enter no of elements of array                                                                                                                
5                                                                                                                                            
enter element1                                                                                                                               
8                                                                                                                                            
enter element2                                                                                                                               
7

enter element3                                                                                                                               
15                                                                                                                                           
enter element4                                                                                                                               
2                                                                                                                                            
enter element5

67                                                                                                                                           
sorted output                                                                                                                                
2                                                                                                                                            
7                                                                                                                                            
8                                                                                                                                            
15                                                                                                                                           
67                                                                                                                                           
min= 2                                                                                                       
max= 67
*/