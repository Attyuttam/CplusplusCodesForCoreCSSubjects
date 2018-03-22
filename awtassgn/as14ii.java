import java.awt.*;
import java.awt.event.*;
public class as14ii extends Frame{
	as14ii(){
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){System.exit(0);}
		});
		this.setLayout(new BorderLayout());
		Button b1=new Button("b1");
		Button b2=new Button("b2");
		Button b3=new Button("b3");
		Button b4=new Button("b4");
		Button b5=new Button("b5");
		
		this.add(b1,BorderLayout.NORTH);
		this.add(b2,BorderLayout.SOUTH);
		this.add(b3,BorderLayout.EAST);
		this.add(b4,BorderLayout.WEST);
		this.add(b5,BorderLayout.CENTER);
		
	}
	public static void main(String args[]){
		as14ii a=new as14ii();
		a.setVisible(true);
		a.setSize(400,400);
		a.setTitle("Layouts");
	}
}