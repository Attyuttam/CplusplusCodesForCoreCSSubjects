import java.awt.*;
import java.awt.event.*;
public class as14 extends Frame{
	as14(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){System.exit(0);}
		});
		this.setLayout(new FlowLayout());
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
		//this.setLayout(new BorderLayout());
		Button b7=new Button("b7");
		Button b8=new Button("b8");
		Button b9=new Button("b9");
		Button b10=new Button("b10");
		Button b11=new Button("b11");
		Button b12=new Button("b12");
		this.add(b7);
		this.add(b8);
		this.add(b9);
		this.add(b10);
		this.add(b11);
		this.add(b12);
	}
	public static void main(String args[]){
		as14 a=new as14();
		a.setVisible(true);
		a.setSize(400,400);
		a.setTitle("Layouts");
	}
}