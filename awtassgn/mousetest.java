import java.awt.*;
import java.awt.event.*;
class mo extends Frame implements MouseListener{
Label l;
  mo(){
    addWindowListener(new WindowAdapter(){
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }

    });
    l=new Label();
    this.setLayout(null);
    l.setBounds(50,50,200,50);
    add(l);
    addMouseListener(this);
  }
  public void mouseEntered(MouseEvent e){
    l.setText("Mouse Entered");
  }
  public void mouseExited(MouseEvent e){
    l.setText("Mouse Exited");
  }
  public void mousePressed(MouseEvent e){
    l.setText("Mouse Pressed");
  }
  public void mouseReleased(MouseEvent e){
    l.setText("Mouse Released");
  }
  public void mouseClicked(MouseEvent e){
    l.setText("Mouse Clicked");
  }
}
public class mousetest{
  public static void main(String[] args) {
      mo m=new mo();
      m.setVisible(true);
      m.setSize(800,600);
  }
}
