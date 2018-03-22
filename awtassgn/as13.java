import java.awt.*;  
import java.awt.event.*;  
class as13 {  
    static Dialog d;  
    as13() {  
        Frame f= new Frame();  
        d = new Dialog(f , "Dialog Example", true);  
        d.setLayout( new FlowLayout() );  
        Button b = new Button ("OK");  
        b.addActionListener ( new ActionListener()  
        {  
            public void actionPerformed( ActionEvent e )  
            {  
                as13.d.setVisible(false);  
            }  
        });  
        d.add( new Label ("Click button to exit."));  
        d.add(b);   
        d.setSize(300,300);    
        d.setVisible(true);  
    }  
    public static void main(String args[])  
    {  
        new as13();  
    }  
}