/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author mc16120
 */
import java.awt.*;
import java.awt.event.*;
class Myclass extends WindowAdapter{
    public void windowClosing(WindowEvent e){
        System.exit(0);
    }
    
}

public class dispstring extends Frame{
    dispstring(){
        this.addWindowListener(new Myclass());
    }
    public void paint(Graphics g){
        g.drawRect(300,200,200,200);
        g.drawString("Attyuttam saha",350,300);
    }
    public static void main(String args[]){
        dispstring ds1=new dispstring();
        ds1.setTitle("assignment1");
        ds1.setSize(800,600);
        ds1.setVisible(true);
    }
    
}
