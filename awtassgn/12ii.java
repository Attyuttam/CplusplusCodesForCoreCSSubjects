import java.awt.*;  
import java.awt.event.*;  
class as12ii extends Frame implements KeyListener{  
    Label l;  
    TextArea area;  
    as12ii(){  
          
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

    }  
    public void keyReleased(KeyEvent e) {

        if(area.getText()!=""){
            //System.out.println("yo");
        String s=area.getText();
        int len=s.length();
        int i=len-1;
        String text="";
        
        while( i>=0 && s.charAt(i)!=' ' ){
                text=String.valueOf(s.charAt(i))+text;
                    i--;
        }
        if(i>=0 && s.charAt(i)==' ') {
            if(text.equals("ENTER")){
                area.setText(""+'\u0000');
            }
        }
      }  
      l.setText("Key Released");  
       
    }  
    public void keyTyped(KeyEvent e) {  
        l.setText("Key Typed");  
    }  
  
    public static void main(String args[]) {  
        as12ii t=new as12ii();  
        t.setSize(400,400);  
        t.setLayout(null);  
        t.setVisible(true); 
    }  
}  