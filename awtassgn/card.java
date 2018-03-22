import java.awt.*;
import java.awt.event.*;
class ca extends Frame implements ActionListener{
  Button b1,b2,b3,b4;
  CardLayout f;
  ca(){
    b1=new Button("b1");
    b2=new Button("b2");
    b3=new Button("b3");
    b4=new Button("b4");
    f=new CardLayout();
    this.setLayout(f);
    add("First Card",b1);
    add("Second Card",b2);
    add("Third Card",b3);
    add("Fourth Card",b4);
    b1.addActionListener(this);
    b2.addActionListener(this);
    b3.addActionListener(this);
    b4.addActionListener(this);

  }
  public void actionPerformed(ActionEvent e){
      f.next(this);
  }
}
public class card{
  public static void main(String[] args) {
    ca t=new ca();
    t.setVisible(true);
    t.setSize(800,800);
  }
}
