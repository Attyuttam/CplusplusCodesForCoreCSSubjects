import java.awt.*;
import java.awt.event.*;
public class as22 extends Frame {
	int flag,p,x=200,y=200;
	as22(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){System.exit(0);}
		});

	}
	public void paint(Graphics g){
				flag=1;p=8;
		
		for(int i=1;i<=100;i++){
			if(flag==1){
				g.drawLine(x,y,x+p,y);
				x=x+p;
				g.drawLine(x,y,x,y-p);
				y=y-p;
				flag=2;
			}
			else{
				g.drawLine(x,y,x-p,y);
				x-=p;
				g.drawLine(x,y,x,y+p);
				y+=p;
				flag=1;
			}
			p+=8;
		}
	}
	
	public static void main(String args[]){
		as22 a=new as22();
		a.setVisible(true);
		a.setSize(400,400);
		a.setTitle("Layouts");
	}
}