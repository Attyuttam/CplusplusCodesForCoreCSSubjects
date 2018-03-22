import java.awt.*;
import java.awt.event.*;
public class game extends Frame implements ActionListener{
	Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b10;
  int board[][]={{0,0,0},{0,0,0},{0,0,0}};
  int i=1,x=1,count=0,pressed=0;
	game(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){System.exit(0);}
		});
    this.setLayout(null);
    b1=new Button("00");
    b2=new Button("01");
    b3=new Button("02");
    b4=new Button("10");
    b5=new Button("11");
    b6=new Button("12");
    b7=new Button("20");
    b8=new Button("21");
    b9=new Button("22");
    b10=new Button("clear");
    this.add(b1);
    this.add(b2);
    this.add(b3);
    this.add(b4);
    this.add(b5);
    this.add(b6);
    this.add(b7);
    this.add(b8);
    this.add(b9);
    this.add(b10);
    b1.setBounds(50,50,50,50);
    b4.setBounds(50,110,50,50);
    b7.setBounds(50,170,50,50);
    b2.setBounds(110,50,50,50);
    b5.setBounds(110,110,50,50);
    b8.setBounds(110,170,50,50);
    b3.setBounds(170,50,50,50);
    b6.setBounds(170,110,50,50);
    b9.setBounds(170,170,50,50);
    b10.setBounds(50,360,50,50);
    b1.addActionListener(this);
    b2.addActionListener(this);
    b3.addActionListener(this);
    b4.addActionListener(this);
    b5.addActionListener(this);
    b6.addActionListener(this);
    b7.addActionListener(this);
    b8.addActionListener(this);
    b9.addActionListener(this);
    b10.addActionListener(this);

	}
  int check_win(int i){
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
void fillColor(int i,int j,int p){
Graphics g=getGraphics();
  if(p==1){
    g.setColor(Color.red);
  }
  else{
    g.setColor(Color.blue);
  }

  if(i==0 && j==0){
      g.fillOval(260,60,20,20);
  }
  else if(i==0 && j==1){
    g.fillOval(310,60,20,20);
  }
  else if(i==0 && j==2){
    g.fillOval(360,60,20,20);
  }
  else if(i==1 && j==0){
    g.fillOval(260,100,20,20);
  }
  else if(i==1 && j==1){
    g.fillOval(310,100,20,20);
  }

  else if(i==1 && j==2){
    g.fillOval(360,100,20,20);
  }
  else if(i==2 && j==0){
    g.fillOval(260,150,20,20);
  }
  else if(i==2 && j==1){
    g.fillOval(310,150,20,20);
  }
  else if(i==2 && j==2){
    g.fillOval(360,150,20,20);
  }
}
void display_board(){
  Graphics g=getGraphics();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==1){
                fillColor(i,j,1);
            }
            else if(board[i][j]==2){
                fillColor(i,j,2);
            }
        }

    }
}

  public void actionPerformed(ActionEvent ae){

    int r=-1,c=-1;
    if(ae.getSource()==b10){
      repaint();
      return;
    }
    else if(ae.getSource()==b1){
      r=0;c=0;
      pressed=1;
    }
    else if(ae.getSource()==b2){
      r=0;c=1;
      pressed=1;
    }
    else if(ae.getSource()==b3){
      r=0;c=2;
      pressed=1;
    }
    else if(ae.getSource()==b4){
      r=1;c=0;
      pressed=1;
    }
    else if(ae.getSource()==b5){
      r=1;c=1;
      pressed=1;
    }
    else if(ae.getSource()==b6){
      r=1;c=2;
      pressed=1;
    }
    else if(ae.getSource()==b7){
      r=2;c=0;
      pressed=1;
    }
    else if(ae.getSource()==b8){
      r=2;c=1;
      pressed=1;
    }
    else if(ae.getSource()==b9){
      r=2;c=2;
      pressed=1;
    }
    Graphics g=getGraphics();
    int flag=0;
    while(true){
    if(board[r][c]!=1 && board[r][c]!=2 && pressed==1 && r>=0 && c>=0){
                board[r][c]=x;
                count++;
                flag=check_win(x);
                if(flag==1){

                g.drawString("Player "+x+" wins",50,350);
                display_board();
                pressed=0;

                for(int m=0;m<3;m++){
                  for(int n=0;n<3;n++){
                    board[m][n]=0;
                  }

                }
                x=1;
                break;
                }
                display_board();
                if(x==1){
                    x=2;
                }
                else{
                    x=1;
                }

                break;
        }
        else{
            repaint();
            for(int m=0;m<3;m++){
                for(int n=0;n<3;n++){
                      board[m][n]=0;
                }

            }
            x=1;
            //g.drawString("Invalid Move",50,350);
            break;
        }
      }
  }
  public void paint(Graphics g){
    g.drawLine(300,50,300,200);
    g.drawLine(350,50,350,200);
    g.drawLine(250,90,400,90);
    g.drawLine(250,140,400,140);
  }

	public static void main(String args[]){
		game a=new game();
		a.setVisible(true);
		a.setSize(800,800);
		a.setTitle("GAME");
	}
}
