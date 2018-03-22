import java.awt.*;
import java.awt.event.*;
public class as15 extends Frame {
	CardLayout card;
	;
	as15(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){System.exit(0);}
		});
		
		this.setLayout(new GridLayout(3,2));
		
		Button b1=new Button("b1");
		Button b2=new Button("b2");
		Button b3=new Button("b3");
		Button b4=new Button("b4");
		Button b5=new Button("b5");
		Button b6=new Button("b6");
		this.add(b1);
		this.add(b2);
		this.add(b3);
		this.add(b4);
		this.add(b5);
		this.add(b6);
	
	}
	
	public static void main(String args[]){
		as15 a=new as15();
		a.setVisible(true);
		a.setSize(400,400);
		a.setTitle("Layouts");
	}
}