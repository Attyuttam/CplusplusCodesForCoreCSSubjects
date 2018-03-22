#include<iostream>
using namespace std;
void Heapify(int a[],int n){
    int j=n,pa;//the position of the newly inserted element
    while(j>0){
        if(j%2!=0)//odd index means LC
        {

                    pa=(j-1)/2;
                    if(a[j]>a[pa]){

                        int temp=a[j];
                        a[j]=a[pa];
                        a[pa]=temp;
                        j=pa;
                        continue;
                    }

        }
        else if(j%2==0)//even index means RC
        {
                if(a[j]<a[j-1]){
                    break;
                }
                else{
                    pa=(j-2)/2;
                    if(a[j]>a[pa]){
                        int temp=a[j];
                        a[j]=a[pa];
                        a[pa]=temp;
                        j=pa;
                        continue;
                    }
                }

        }
        break;
    }
}
void HeapSort(int a[],int n)//n is the last index
{
    int i=n,j;
    while(i>0){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        i--;
        j=0;
        while(j<i){
                int lc=2*j+1;
                int rc=2*j+2;
            if(a[j]<a[lc] && a[lc]>a[rc] && lc<=i){
                temp=a[j];
                a[j]=a[lc];
                a[lc]=temp;
                j=lc;
                continue;
            }
            else if(a[j]<a[rc] && a[rc]>a[lc] && rc<=i){
                temp=a[j];
                a[j]=a[rc];
                a[rc]=temp;
                j=rc;
                continue;
            }
            break;
        }
    }
}
int main(){
    int n,a[50];
    cout<<"Enter the number of numbers that you want to enter: ";
     cin>>n;
     cout<<"Enter element: ";
     cin>>a[0];

     for(int i=1;i<n;i++){
        cout<<"Enter element: ";
        cin>>a[i];
        Heapify(a,i);
        cout<<endl<<"The array after insertion: \n";
         for(int k=0;k<=i;k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
     }

     HeapSort(a,n-1);
      cout<<endl<<"The array after sorting: \n";
         for(int k=0;k<n;k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
}
