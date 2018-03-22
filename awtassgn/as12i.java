import java.awt.*;  
import java.awt.event.*;  
public class as12i extends Frame implements KeyListener{  
    Label l;  
    TextArea area;  
    as12i(){  
          
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
        l.setText("Key Pressed");  
    }  
    public void keyReleased(KeyEvent e) {  
        l.setText("Key Released");  
    }  
    public void keyTyped(KeyEvent e) {  
        l.setText("Key Typed");  
    }  
  
    public static void main(String args[]) {  
        as12i t=new as12i();  
        t.setSize(400,400);  
        t.setLayout(null);  
        t.setVisible(true); 
    }  
}  