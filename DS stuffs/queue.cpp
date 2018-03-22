#include<iostream>
using namespace std;
int LQ[10];//Linear queue
int frontl =-1,rearl=-1;//for linear queue


int DQ[10];//double ended queue
int frontd=-1,reard=-1;//for double ended queue

int CQ[10];//circular queue
int frontc=-1,rearc=-1;
//linear queue functions
void enqueue(int el){
    if(rearl==9){
        cout<<"The queue is full";
    }
    else{
        LQ[++rearl]=el;
        if(frontl==-1){
            frontl++;
        }
    }
}
void dequeue(){
    if(frontl==-1){
        cout<<"The queue is empty";
    }
    else{
        cout<<"The deleted element is: "<<LQ[frontl];
        frontl++;
        if(frontl>rearl){
            frontl=-1;
            rearl=-1;
        }
    }
}
void display(int *Q,int front,int rear){//same for all the kinds of queue
    for(int i=front;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
}
//double ended queue functions
void enter_at_front(int el){
    if(reard==9){
        cout<<"The queue is full";
    }
    else{
        if(frontd>0){
            DQ[--frontd]=el;
        }
        else if(frontd==-1) {
                DQ[++frontd]=el;
        }
        else{
            cout<<"Cannot insert at front";
        }
        if(reard==-1){
            reard++;
        }
    }
}
void enter_at_end(int el){
    if(reard==9){
        cout<<"The queue is full";
    }
    else{
        DQ[++reard]=el;
        if(frontd==-1){
            frontd++;
        }
    }
}
void delete_from_front(){
    if(frontd==-1){
        cout<<"The queue is empty";
    }
    else{
        cout<<"The deleted element is : "<<DQ[frontd];
        frontd++;
        if(frontd>reard){
            frontd=-1;
            reard=-1;
        }
    }
}
void delete_from_end(){
    if(frontd==-1){
        cout<<"The queue is empty";
    }
    else{
        cout<<"The deleted element is: "<<DQ[reard];
        reard--;
        if(frontd>reard){
            frontd=-1;
            reard=-1;
        }

    }
}
int main(){
    //implementing linear queue
    int ch,chs,el;
    while(1){
        cout<<"\n1.Work with linear queue \n2.Work with DeQueue \n3.Work with circular queue \n4.Exit\nEnter your choice: ";
        cin>>chs;
        if(chs==1){
                while(1){
                    cout<<"\n1.Enqueue\n2.Dequeue\n3.Display the queue\n4.Exit\nEnter your choice: ";
                    cin>>ch;
                    if(ch==1){
                        cout<<"Enter the element: ";
                        cin>>el;
                        enqueue(el);

                    }
                    else if(ch==2){
                        dequeue();
                    }
                    else if(ch==3){
                        display(LQ,frontl,rearl);
                    }
                    else if(ch==4){
                        cout<<"Thank you";
                        break;
                    }
                    else{
                        cout<<"Wrong option";
                    }
                }
        }
        else if(chs==2){
            while(1){
                cout<<"\n1.Enter at the front of the queue\n2.Enter at the end of the queue\n3.Delete from the front of the queue \n4.Delete from the end of the queue \n5.Display the queue\n6.Exit\nEnter your choice: ";
                cin>>ch;
                if(ch==1){
                    cout<<"Enter the element: ";
                    cin>>el;
                    enter_at_front(el);
                }
                else if(ch==2){
                    cout<<"Enter the element: ";
                    cin>>el;
                    enter_at_end(el);
                }
                else if(ch==3){
                    delete_from_front();
                }
                else if(ch==4){
                    delete_from_end();
                }
                else if(ch==5){
                    display(DQ,frontd,reard);
                }
                else if(ch==6){
                    break;
                }
                else{
                    cout<<"Wrong option";
                }
            }
        }
        else if(chs==3){

        }
        else if(chs==4){
            break;
        }
        else{
            cout<<"Wrong option";
        }
    }

    return 0;
}

