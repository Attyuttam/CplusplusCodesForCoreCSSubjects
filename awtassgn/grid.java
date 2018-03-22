import java.awt.*;
class fl extends Frame{
  Button b1,b2,b3,b4;
  fl(){
    b1=new Button("b1");
    b2=new Button("b2");
    b3=new Button("b3");
    b4=new Button("b4");
    GridLayout f=new GridLayout(2,2);
    this.setLayout(f);
    add(b1);
    add(b2);
    add(b3);
    add(b4);

  }
}
public class grid{
  public static void main(String[] args) {
    fl t=new fl();
    t.setVisible(true);
    t.setSize(800,800);
  }
}
