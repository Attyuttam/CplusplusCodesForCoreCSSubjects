import java.awt.*;  
import java.awt.event.*;  
public class as12iv extends Frame implements KeyListener{  
    Label l;  
    TextArea area;  
    as12iv(){  
          
        l=new Label();  
        l.setBounds(20,50,100,20);  
        area=new TextArea();  
        area.setBounds(20,80,200, 200);  
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
      if((area.getText()).equals("CIRCLE"))  {
            //Graphics g=getGraphics();
            g.drawOval(300,300,40,40);
        } 
       
    }  
    public void keyTyped(KeyEvent e) {  
        l.setText("Key Typed");  
    }  
  
    public static void main(String args[]) {  
        as12iv t=new as12iv();  
        t.setSize(800,800);  
        t.setLayout(null);  
        t.setVisible(true); 
    }  
}  