import java.awt.*;
import java.awt.event.*;
public class as12x extends Frame implements KeyListener{
    Label l;
    TextArea area;
    as12x(){

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
              String t=area.getText();
              int len=t.length();
              int flag=0;
              int i=0;
              while(i<len){
                if(t.charAt(i)-'0'<0 || t.charAt(i)-'0'>9 ){
                  flag=1;
                  break;
                }
                i++;
              }
              if(flag==0){
                i=0;
                int r=0;
                while(i<len){
                  r=r*10+(t.charAt(i)-'0');
                  i++;
                }
                g.drawOval(400,400,r*10,r*10);
              }
         //int r=(area.getText()).charAt(0)-'0';


    }
    public void keyTyped(KeyEvent e) {
        l.setText("Key Typed");
    }

    public static void main(String args[]) {
        as12x t=new as12x();
        t.setSize(800,800);
        t.setLayout(null);
        t.setVisible(true);
    }
}
