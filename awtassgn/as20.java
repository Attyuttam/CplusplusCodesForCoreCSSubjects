import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class as20 extends Applet implements ActionListener{
  int opt=0;
  Button b1;
  Button b2;
  Button b3;
  Button b4;
	public void init(){
    setBackground(Color.yellow);
    setLayout(null);
    b1=new Button("Hospitals");
    b2=new Button("Stadiums");
    b3=new Button("Post Office");
    b4=new Button("Schools");
    b1.setBounds(100,500,90,50);
    add(b1);
    b2.setBounds(250,500,90,50);
    add(b2);
    b3.setBounds(400,500,90,50);
    add(b3);
    b4.setBounds(550,500,90,50);
    add(b4);
    b1.addActionListener(this);
    b2.addActionListener(this);
    b3.addActionListener(this);
    b4.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae){
    Graphics g=getGraphics();
    if((ae.getSource()).equals(b1)){
      repaint();
        opt=1;
        paint(g);

    }
    else if((ae.getSource()).equals(b2)){
      repaint();
        opt=2;
        paint(g);

    }
    else if((ae.getSource()).equals(b3)){
      repaint();
        opt=3;
        paint(g);

    }
    else if((ae.getSource()).equals(b4)){
      repaint();
        opt=4;
        paint(g);

    }
	}
	public void paint(Graphics g){
		g.drawLine(300,30,300,200);
    g.drawLine(320,30,320,200);
    g.drawLine(300,200,200,200);
    g.drawLine(300,220,200,220);
    g.drawLine(300,200,300,350);
    g.drawLine(320,200,320,350);
    g.drawLine(300,200,450,200);
    g.drawLine(300,220,450,220);
    g.drawOval(270,30,20,20);//hospital
    g.drawOval(270,90,20,20);//stadium
    g.drawOval(360,230,20,20);//hospital
    g.drawOval(400,230,20,20);//school
    g.drawOval(390,170,20,20);//school
    g.drawOval(200,170,20,20);//postoffice
    g.drawOval(250,230,20,20);//stadium
    g.drawOval(270,260,20,20);//hospital
    g.drawOval(270,230,20,20);//postoffice
    g.drawOval(330,150,20,20);//hospital
    if(opt==1){
      //repaint();
      g.setColor(Color.red);
      g.fillOval(270,30,20,20);//hospital
      g.fillOval(360,230,20,20);//hospital
      g.fillOval(270,260,20,20);//hospital
      g.fillOval(330,150,20,20);//hospital
    //  opt=0;
    }

    else if(opt==2){
      //repaint();
      g.setColor(Color.green);
  g.fillOval(270,90,20,20);//stadium
  g.fillOval(250,230,20,20);//stadium
  //opt=0;
    }

    else if(opt==3){
      //repaint();
      g.setColor(Color.blue);
      g.fillOval(200,170,20,20);//postoffice
        g.fillOval(270,230,20,20);//postoffice
        //opt=0;
    }

    else if(opt==4){
      //repaint();
      g.setColor(Color.pink);
      g.fillOval(400,230,20,20);//school
      g.fillOval(390,170,20,20);//school
      //opt=0;
    }
	}
}
