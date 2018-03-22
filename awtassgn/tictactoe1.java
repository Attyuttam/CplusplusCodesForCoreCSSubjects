import java.awt.*;
import java.awt.event.*;
public class tictactoe1 extends Frame {
	Button b1,b2,b3,b4;
  int values[3][3]={{0,0,0},{0,0,0},{0,0,0}};

	tictactoe1(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){System.exit(0);}
		});
    this.setLayout(null);
    b1=new Button("00");
    b2=new Button("00");
    b3=new Button("00");
    b4=new Button("00");
    this.add(b1);
    this.add(b2);
    this.add(b3);
    this.add(b4);
	}
	public void paint(Graphics g){

	}

	public static void main(String args[]){
		tictactoe1 a=new tictactoe1();
		a.setVisible(true);
		a.setSize(400,400);
		a.setTitle("Layouts");
	}
}
