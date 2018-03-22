import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class as3 extends Applet implements ActionListener{
	Button b1;
	Label l1;
	Label l2;
	Label l3;
	TextField t1;
	TextField t2;
	TextArea t3;
	String str="";
	int pos=130;
	public void init(){

		setBackground(Color.yellow);
		setLayout(null);
		b1=new Button("Submit");
		add(b1);
		Label top=new Label("STUDENT PORTAL");
		top.setBounds(50,30,250,50);
		add(top);
		b1.setBounds(50,500,50,30);
		l1=new Label("Name: ");
		l1.setBounds(50,90,50,30);
		l2=new Label("Roll: ");
		l2.setBounds(50,150,50,30);
		l3=new Label("Address: ");
		l3.setBounds(50,210,50,30);
		t1=new TextField(50);
		t1.setBounds(120,90,150,50);
		t2=new TextField(50);
		t2.setBounds(120,150,150,50);
		t3=new TextArea(50,50);
		t3.setBounds(120,210,150,50);

		add(l1);
		add(l2);
		add(l3);
		add(t1);
		add(t2);
		add(t3);
		b1.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae){
		Graphics g=getGraphics();
		str="Name Entered: "+t1.getText();
		paint(g);
		str="";
		str="Roll Entered: "+t2.getText();
		paint(g);
		str="";
		str="Address Entered: "+t3.getText();
		paint(g);
		str="";
		pos=130;
	}
	public void paint(Graphics g){
		if(str!=""){
			g.drawString("Details Entered: ",300,80);
			g.drawString(str,300,pos);
			pos+=60;
		}
	}
}
