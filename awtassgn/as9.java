import java.io.*;
import java.awt.*;
import java.awt.event.*;
public class as9 extends Frame{

	as9(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		}
		);
		this.setLayout(null);

	}
	public void paint(Graphics g){
		g.drawLine(50,50,200,50);
		g.drawRect(55,55,100,50);
		g.drawOval(50,200,100,80);
		g.drawString("Attyuttam Saha",50,300);
	}
	public static void main(String args[]){
		as9 a=new as9();
		a.setTitle("Draw everything");
		a.setSize(800,600);
		a.setVisible(true);
	}
}