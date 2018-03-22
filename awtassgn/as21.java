import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class as21 extends Applet {

	public void init(){


	}

	public void paint(Graphics g){
    //1st umbrella
    g.setColor(Color.cyan);
		g.fillArc(50,50,180,60,0,90);
    g.setColor(Color.yellow);
		g.fillArc(50,50,180,60,90,90);
    g.setColor(Color.yellow);
    g.fillArc(90,50,90,60,0,90);
    g.setColor(Color.cyan);
    g.fillArc(90,50,90,60,90,90);
    g.setColor(Color.black);
    g.drawArc(50,50,180,60,0,180);
    g.drawLine(50,80,230,80);
    g.drawLine(140,80,140,140);
    g.drawArc(140,120,40,30,0,-180);
    //2nd umbrella
    g.setColor(Color.red);
    g.fillArc(150,250,200,60,0,90);
    g.setColor(Color.pink);
    g.fillArc(150,250,200,60,90,90);
    g.setColor(Color.pink);
    g.fillArc(190,250,100,60,0,90);
    g.setColor(Color.red);
    g.fillArc(190,250,100,60,90,90);
    g.setColor(Color.black);
    g.drawArc(150,250,200,60,0,180);
    g.drawLine(150,280,355,280);
    g.drawLine(240,280,240,390);
    g.drawArc(240,370,40,30,0,-180);
    //3rd umbrella
    g.setColor(Color.green);
    g.fillArc(250,350,200,60,0,90);
    g.setColor(Color.blue);
    g.fillArc(250,350,200,60,90,90);
    g.setColor(Color.blue);
    g.fillArc(290,350,100,60,0,90);
    g.setColor(Color.green);
    g.fillArc(290,350,100,60,90,90);
    g.setColor(Color.black);
    g.drawArc(250,350,200,60,0,180);
    g.drawLine(250,380,450,380);
    g.drawLine(350,380,350,500);
    g.drawArc(350,480,40,30,0,-180);
    //Text
    Label label1=new Label("Rain, Rain,");
    Font myFont = new Font("Serif",Font.BOLD,22);
    label1.setFont(myFont);
    label1.setBounds(500,50,200,100);
    add(label1);
    Label label2=new Label("Go Away !!");
    Font myFont1 = new Font("Serif",Font.BOLD,22);
    label2.setFont(myFont1);
    label2.setBounds(500,120,200,100);
    add(label2);
	}
}
