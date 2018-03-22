import java.awt.*;
import java.awt.event.*;
import java.math.*;
public class nationalflag extends Frame{

	nationalflag(){
		this.addWindowListener(
				new WindowAdapter(){
					public void windowClosing(WindowEvent e){

						System.exit(0);
					}
				}
			);

	}
	public void paint(Graphics g){
		g.setColor(Color.orange);
		g.fillRect(100,100,500,100);
		g.setColor(Color.black);
		g.drawRect(100,200,500,99);
		g.setColor(Color.green);
		g.fillRect(100,300,500,100);
		g.setColor(Color.blue);
		g.drawOval(305,200,100,100);
		int x=355,y=250,radius=50,theta=0;
		for(int i=1;i<=24;i++){
			double radians=theta*(3.142/180);
			int x1=(int)(x+radius*Math.cos(radians));
			int y1=(int)(y+radius*Math.sin(radians));
			g.drawLine(x,y,x1,y1);
			theta+=(360/24);
		}
	}
	public static void main(String args[]){
		nationalflag nf=new nationalflag();
		nf.setTitle("National flag");
		nf.setSize(800,600);
		nf.setVisible(true);
	}
}