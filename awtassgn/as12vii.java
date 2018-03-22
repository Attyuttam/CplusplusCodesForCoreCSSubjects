import java.awt.*;
import java.awt.event.*;
public class as12vii extends Frame implements KeyListener{
    Label l;
    TextArea area;
    as12vii(){

        l=new Label();
        l.setBounds(220,50,100,20);
        area=new TextArea();
        area.setBounds(220,80,200, 200);
        area.addKeyListener(this);

        add(l);
        add(area);
        this.addWindowListener(new WindowAdapter()
            {
                public void windowClosing(WindowEvent e){
                    System.exit(0);
                }
            }
   );

    }
    public void keyPressed(KeyEvent e) {
        repaint();
        l.setText("key Pressed");


    }
    public void keyReleased(KeyEvent e) {
      l.setText("Key Released");

              Graphics g=getGraphics();
            //g.drawString(area.getText(),300,400);
          //String text=;
          if((area.getText()).equals("circle red")){
            g.setColor(Color.red);
            g.fillOval(25,35,50,50);
          }
          if((area.getText()).equals("circle")){
            g.setColor(Color.black);
            g.drawOval(25,35,50,50);
          }
          if((area.getText()).equals("rectangle")){
            g.setColor(Color.red);
            g.drawRect(25,35,50,80);
          }
          if(e.getKeyCode()==KeyEvent.VK_F1)  {
              g.drawOval(400,400,50,50);
          }
          if(e.getKeyCode()==KeyEvent.VK_F2)  {
              g.drawRect(400,400,90,50);
          }

    }
    public void keyTyped(KeyEvent e) {
        l.setText("Key Typed");
    }

    public static void main(String args[]) {
        as12vii t=new as12vii();
        t.setSize(800,800);
        t.setLayout(null);
        t.setVisible(true);
    }
}
