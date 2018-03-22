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
void check_for_opt(int board){

        if(board[0][0]==1){
            if(board[0][2]!=2 && board[0][1]!=2){
                board[0][1]=2;
            }
            else if(board[1][1]!=2 && board[2][2]!=2){
                board[1][1]=2;
            }
            else if(board[1][0]!=2 && board[2][0]!=2){
                board[1][0]=2;
            }
        }
        if(board[0][2]==1){
            if(board[0][2]!=2 && board[0][1]!=2){
                board[0][1]=2;
            }
            else if(board[1][1]!=2 && board[2][2]!=2){
                board[1][1]=2;
            }
            else if(board[1][0]!=2 && board[2][0]!=2){
                board[1][0]=2;
            }
        }
        if(board[1][0]==1){
            if(board[1][1]!=2){
                board[1][1]=2;

            }
            else if(board[1][2]!=2){
                board[1][2]=2;
            }
            else{
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                        if(board[i][j]==0){
                            board[i][j]=2;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1){
                        break;
                    }
                }
            }
        }
        if(board[1][2]==1){
            if(board[1][1]!=2){
                board[1][1]=2;

            }
            else if(board[1][0]!=2){
                board[1][0]=2;
            }
            else{
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                        if(board[i][j]==0){
                            board[i][j]=2;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1){
                        break;
                    }
                }
            }
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
        if(x==1){
            cout<<"Player"<<endl;
            cout<<endl<<"enter row and coloumn on the board: ";
            cin>>r>>c;
            if(board[r][c]!=1 && board[r][c]!=2 && r<3 && c<3){
                board[r][c]=x;
                flag=check_win(board,x);
                if(flag==1){
                    cout<<"Player wins";
                    display_board(board);
                    break;
                }

                x++;
            }
            else{
                cout<<"invalid"<<endl;
            }

        }
        else{
         check_for_opt(board,x);
         flag=check_win(board,x);
         if(flag==1){
            cout<<"computer wins";
            break;
         }
         x--;
        }
    }while(count!=9);
}
