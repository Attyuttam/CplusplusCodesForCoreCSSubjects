import java.io.*;
import java.awt.*;
import java.awt.event.*;
class fill extends Frame{
  int x[]={300,400,500};
  int y[]={400,200,400};
  public void paint(Graphics g){
    g.setColor(Color.green);
    g.fillPolygon(x,y,3);
  }
}

public class fillpoly{
  public static void main(String[] args) {
    fill t=new fill();
    t.setVisible(true);
    t.setSize(800,800);
  }
}
