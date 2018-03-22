import java.awt.*;  
import java.awt.event.*;  
class as12ii extends Frame implements KeyListener{  
    Label l,out;  
    TextArea area;  
    as12ii(){  
          
        l=new Label();  
        l.setBounds(20,50,100,20);  
        area=new TextArea();  
        area.setBounds(20,80,300, 300);  
        area.addKeyListener(this);  
          
        add(l);
        add(area);  
        out=new Label();  
        out.setBounds(100,400,200,100); 
        add(out);
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
        out.setText(area.getText());

    }  
    public void keyReleased(KeyEvent e) {

    
      l.setText("Key Released");  
       
    }  
    public void keyTyped(KeyEvent e) {  
        l.setText("Key Typed");  
    }  
  
    public static void main(String args[]) {  
        as12ii t=new as12ii();  
        t.setSize(800,800);  
        t.setLayout(null);  
        t.setVisible(true); 
    }  
}  