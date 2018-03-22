#include<iostream>
using namespace std;
void merger(int a[10],int beg_pos,int mid_pos,int end_pos){
    int i=beg_pos,k=0,j=mid_pos+1,c[10];
    //cout<<beg_pos<<","<<end_pos<<endl;
    while(i<=mid_pos && j<=end_pos){
        if(a[i]<=a[j]){
            c[k]=a[i];
            i++;
        }
        else{
            c[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid_pos){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<=end_pos){
        c[k]=a[j];
        j++;
        k++;
    }
    i=beg_pos;k=0;
    while(i<=end_pos){
        a[i]=c[k];
        i++;
        k++;
    }


}
void merge_sort(int a[10],int beg_pos,int end_pos){
    if(beg_pos<end_pos){
            //cout<<beg_pos<<","<<end_pos<<endl;
        int mid_pos=(beg_pos+end_pos)/2;
        merge_sort(a,beg_pos,mid_pos);
        merge_sort(a,mid_pos+1,end_pos);
        merger(a,beg_pos,mid_pos,end_pos);
    }

}
int main(){
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    merge_sort(a,0,9);
    cout<<endl<<"sorted list:"<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}
