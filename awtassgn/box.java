import java.awt.*;
class fl extends Frame{
  Button b1,b2,b3,b4;
  fl(){
    b1=new Button("b1");
    b2=new Button("b2");
    b3=new Button("b3");
    b4=new Button("b4");
    BorderLayout f=new BorderLayout(2,5);
    this.setLayout(f);
    add("North",b1);
    add("South",b2);
    add("East",b3);
    add("West",b4);

  }
}
public class box{
  public static void main(String[] args) {
    fl t=new fl();
    t.setVisible(true);
    t.setSize(800,800);
  }
}
