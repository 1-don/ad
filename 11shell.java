import java.io.*;

class sort
{
              int temp,gap,i,n;
              int swapped;
              int  a[]=new int[20];


              void get()throws IOException
              {
                    
                            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
                            System.out.println("\nEnter the no of elements");
                            n=Integer.parseInt(br.readLine());
                            for(i=0;i<n;i++)
                            {
                                    System.out.println("\nEnter the element");
                                    a[i]=Integer.parseInt(br.readLine());
                            }
               }                    
              void shell_sort()
              {
                     gap=n/2;
                     do
                     {
                            do
                            {
                                   swapped=0;
                                   for(i=0;i<n-gap;i++)
                                   {
                                          if(a[i]>a[i+gap])
                                          {
                                                 temp=a[i];
                                                 a[i]=a[i+gap];
                                                 a[i+gap]=temp;
                                                 swapped=1;
                                          }
                                   }
                             }while(swapped==1);
                             
                      }while((gap=gap/2)>=1);
             }
          void display()
          {
              System.out.println("\nSorted array is");
              for(i=0;i<n;i++)
              {
                     
                     System.out.println("\n "+a[i]);
              }
          }           
} 


class shell
{
       public static void main(String args[])throws IOException 
       {
              int n;
                     
              sort s=new sort();
              s.get();
              s.shell_sort(); 
              s.display();
       }
}                                                            
