import java.awt.*;
import java.awt.event.*;

public class Bank extends Frame implements ActionListener{
	Button b1;
	Label l1;
	Label l2;
	Label l3;
  Label l4;
  Label l5;
	TextField t1;
	TextField t2,t3,t4,t5;
  float bal=0.0f;
	String str="";
	int pos=130;
	Bank(){
    this.addWindowListener(new WindowAdapter(){
        public void windowClosing(WindowEvent e){
            System.exit(0);
        }
    });
		setBackground(Color.yellow);
		setLayout(null);
		b1=new Button("Submit");
		add(b1);
		Label top=new Label("BANK PORTAL");
		top.setBounds(50,30,250,50);
		add(top);
		b1.setBounds(50,500,50,30);
		l1=new Label("Name: ");
		l1.setBounds(50,90,100,30);
		l2=new Label("Account Number: ");
		l2.setBounds(50,150,100,30);
		l3=new Label("Initial Balance: ");
		l3.setBounds(50,210,100,30);
    l4=new Label("Deposit Amount: ");
		l4.setBounds(50,270,100,30);
    l5=new Label("Withdrawl amount: ");
		l5.setBounds(50,330,100,30);


    t1=new TextField(50);
		t1.setBounds(180,90,150,50);
		t2=new TextField(50);
		t2.setBounds(180,150,150,50);
		t3=new TextField(50);
		t3.setBounds(180,210,150,50);
    t4=new TextField(50);
    t4.setBounds(180,270,150,50);
    t5=new TextField(50);
		t5.setBounds(180,330,150,50);
		add(l1);
		add(l2);
		add(l3);
    add(l4);
    add(l5);
		add(t1);
		add(t2);
		add(t3);
    add(t4);
    add(t5);
		b1.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae){
		//repaint();
		//try{Thread.sleep(1000);}catch(InterruptedException e){}
		
		int dep=Integer.parseInt(t4.getText());
		int inbal=Integer.parseInt(t3.getText());
		int with=Integer.parseInt(t5.getText());
		if(dep+inbal>with)
    		bal=inbal+dep-with;
    	else
    		bal=-1;

    Graphics g=getGraphics();
		str="Name Entered: "+t1.getText();
		paint(g);
		str="";
		str="Account Number Entered: "+t2.getText();
		paint(g);
		str="";
		str="Initial Balance: "+t3.getText();
		paint(g);
		str="";
		pos=130;
    
	}
	public void paint(Graphics g){
		if(str!=""){
			g.drawString("Details Entered: ",300,80);
			g.drawString(str,500,pos);
			pos+=60;
			if(bal!=-1)
      			g.drawString("balance= "+bal,500,350);
      		else
      			g.drawString("Invalid withdrawl amount entered",500,350);
		}
	}
  public static void main(String[] args) {
    Bank b=new Bank();
    b.setVisible(true);
    b.setSize(800,600);
    b.setTitle("BANK");
  }
}
