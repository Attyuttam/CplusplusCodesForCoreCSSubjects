import java.awt.*;
import java.awt.event.*;
//import java.applet.*;
public class pietest extends Frame implements ActionListener{
TextField tf1;
TextField tf2;
TextField tf3;
Label l1;
Label l2;
Label l3;
Button b1;
int Sci, Soc, Hum, Total,opt=0;
pietest(){
  this.addWindowListener(
   new WindowAdapter(){
     public void windowClosing(WindowEvent e){
       System.exit(0);
     }
   }
  );
  tf1=new TextField(40);
  tf2=new TextField(40);
  tf3=new TextField(40);
  l1=new Label("Enter science marks");
  l2=new Label("Enter Social marks");
  l3=new Label("Enter Humaities marks");
  setLayout(null);
  tf1.setBounds(250,300,80,30);
  tf2.setBounds(250,350,80,30);
  tf3.setBounds(250,400,80,30);

  add(tf1);
  add(tf2);
  add(tf3);
  l1.setBounds(50,300,120,30);
  l2.setBounds(50,350,120,30);
  l3.setBounds(50,400,130,30);

  add(l1);
  add(l2);
  add(l3);
  b1=new Button("Calculate");
  b1.setBounds(50,450,100,30);
  add(b1);
  b1.addActionListener(this);
}
public void actionPerformed(ActionEvent ae){
  if((ae.getSource()).equals(b1)){
    opt=1;
    repaint();
    Graphics g=getGraphics();
    paint(g);
  }
}
	public void paint(Graphics g) {

		// variables to store the number of students in each discipline
		// and the total number of students
if(opt==1){

		// variables to store percentages should be float
		float PercSci, PercSoc, PercHum;

		// the coordinates and size of the pie is fixed below
		int x = 50, y = 50, w = 100, h = 100;

		// these quantities will need to be computed for each slice
		int startAngle = 0, degrees;

		// Set # of students in each discipline
		Sci = Integer.parseInt(tf1.getText());
		Soc = Integer.parseInt(tf2.getText());
		Hum = Integer.parseInt(tf3.getText());

		// Computer percentages
		Total = Sci + Soc + Hum;

		PercSci = Sci * 100.0f / Total;
		PercSoc = Soc * 100.0f / Total;
		PercHum = Hum * 100.0f / Total;
    System.out.println(PercSci);
		// Print out results for checking

		g.drawString("Total = " + Total,200,50);
			g.drawString("Sci = " + Sci,200,80);

		g.drawString("Soc = " + Soc,200,110);
			g.drawString("Hum = " + Hum,200,140);

		// Display the Pie Chart
		// Display the Pie for Sciences
		degrees = (int) (PercSci*360/100);
		g.setColor(Color.red);
    g.fillOval(250,65,20,20);
		g.fillArc(x, y, w, h, startAngle, degrees);

		// Pie for Soc
		startAngle = degrees;
		degrees = (int) (PercSoc*360/100);
		g.setColor(Color.yellow);
    g.fillOval(250,95,20,20);
		g.fillArc(x, y, w, h, startAngle, degrees);

		// Pie for Hum
		startAngle = startAngle + degrees;
		degrees = (int) (PercHum*360/100);
		g.setColor(Color.green);
    g.fillOval(255,125,20,20);
		g.fillArc(x, y, w, h, startAngle, degrees);
}
	} // end of paint
public static void main(String[] args) {
    pietest p=new pietest();
    p.setVisible(true);
    p.setSize(800,600);
    p.setTitle("Pie chart");
  }
} // end of applet
