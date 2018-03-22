import java.awt.*;  
import java.awt.event.*;  
public class as12v extends Frame implements KeyListener{  
    Label l;  
    TextArea area;  
    as12v(){  
          
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
          //String text=;
          if((area.getText()).equals("circle 10")){
            g.drawOval(300,300,10,10);
          }
       
    }  
    public void keyTyped(KeyEvent e) {  
        l.setText("Key Typed");  
    }  
  
    public static void main(String args[]) {  
        as12v t=new as12v();  
        t.setSize(800,800);  
        t.setLayout(null);  
        t.setVisible(true); 
    }  
}  