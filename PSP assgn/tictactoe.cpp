#include<iostream>
using namespace std;
int check_win(int board[3][3],int i){
    if(board[0][0]==i && board[0][1]==i && board[0][2]==i){
        return 1;
    }
    else if(board[1][0]==i && board[1][1]==i && board[1][2]==i){
        return 1;
    }
    else if(board[2][0]==i && board[2][1]==i && board[2][2]==i){
        return 1;
    }
    else if(board[0][0]==i && board[1][0]==i && board[2][0]==i){
        return 1;
    }
    else if(board[0][1]==i && board[1][1]==i && board[2][1]==i){
        return 1;
    }
    else if(board[0][2]==i && board[1][2]==i && board[2][2]==i){
        return 1;
    }
    else if(board[0][0]==i && board[1][1]==i && board[2][2]==i){
        return 1;
    }
    else if(board[0][2]==i && board[1][1]==i && board[2][0]==i){
        return 1;
    }
    else{
        return 0;
    }
}
void display_board(int board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=1 && board[i][j]!=2){
                cout<<"- ";
            }
            else{
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int board[3][3]={{0,0,0},{0,0,0},{0,0,0}},flag=0,r,c;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"- ";
        }
        cout<<endl;
    }
    int i=1,x=1,count=0;

    do{
        cout<<"Player "<<x<<": ";
        cout<<endl<<"enter row and coloumn on the board: ";
        cin>>r>>c;
        if(board[r][c]!=1 && board[r][c]!=2 && r<3 && c<3){
                board[r][c]=x;
                count++;
                flag=check_win(board,x);
                if(flag==1){
                cout<<"Player "<<x<<" wins."<<endl;
                display_board(board);
                break;
                }
                display_board(board);
                if(x==1){
                    x=2;
                }
                else{
                    x=1;
                }
        }
        else{
            cout<<"invalid"<<endl;
        }



    }while( count!=9);
}
