 import java.awt.*;  
import java.awt.event.*;  
public class as12ix extends Frame implements KeyListener{  
    Label l;  
    TextArea area;  
    as12ix(){  
          
        l=new Label();  
        l.setBounds(20,50,100,20);  
        area=new TextArea();  
        area.setBounds(20,80,300, 300);  
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
        l.setText("key Pressed");
        Graphics g=getGraphics();
        if(e.getKeyCode()==KeyEvent.VK_F1)  {
            g.drawOval(400,400,50,50);
        }
         else if(e.getKeyCode()==KeyEvent.VK_F2)  {
            g.drawRect(400,400,90,50);
        }
    }  
    public void keyReleased(KeyEvent e) {  
      l.setText("Key Released");  
      repaint();
       
    }  
    public void keyTyped(KeyEvent e) {  
        l.setText("Key Typed");  
    }  
  
    public static void main(String args[]) {  
        as12ix t=new as12ix();  
        t.setSize(800,800);  
        t.setLayout(null);  
        t.setVisible(true); 
    }  
}  