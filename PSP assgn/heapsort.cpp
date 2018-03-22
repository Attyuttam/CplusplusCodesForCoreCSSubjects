#include<iostream>
#include<vector>
using namespace std;
vector<int> heapify(vector<int> heap,int n,int pos){
    int l=2*pos+1;
    int r=2*pos+2;
    int largest = pos;
    if(l<n && heap[l]>heap[largest]){
        largest = l;
    }
    if(r<n && heap[r]>heap[largest]){
        largest = r;
    }
    if(largest!=pos){
        int t=heap[largest];
        heap[largest]=heap[pos];
        heap[pos]=t;

        heap=heapify(heap,n,largest);
    }
    return heap;
}
void heap_sort(vector<int> heap){
    int n=heap.size();
    for(int i=(n/2)-1;i>=0;i--){
        heap=heapify(heap,n,i);

        //for(int i=0;i<n;i++)
          //  cout<<heap[i]<<" ";
        //cout<<endl;
    }
    cout<<"------------------------------------------\n";
    for(int i=n-1;i>0;i--){
        int t=heap[0];
        heap[0]=heap[i];
        heap[i]=t;
        heap=heapify(heap,i,0);
        //for(int i=0;i<n;i++)
          //  cout<<heap[i]<<" ";
        //cout<<endl;
    }
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";

    cout<<endl;
}
int main(){
    int n;
    vector<int> heap;
    int val;
    cout<<"Enter the number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        heap.push_back(val);
    }
    heap_sort(heap);
}
