#include<iostream>
using namespace std;
int partitionv(int list[5],int low,int high){
    int pivot,i,j;
pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            cout<<"ex";
            while (list[i] <=list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                //cout<<endl<<list[pivot];
            }
        }
        int temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        return j;
}
void QS(int a[5],int beg,int endv){
    if(beg<endv){
    //cout<<"ex";
        int q=partitionv(a,beg,endv);
        QS(a,beg,q-1);
        QS(a,q+1,endv);
    }
}
int main(){
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
     QS(a,0,4);
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
