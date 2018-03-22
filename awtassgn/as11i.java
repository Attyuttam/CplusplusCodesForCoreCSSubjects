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
import javax.swing.*;
class mouseevent1 extends Frame implements MouseListener{
    double x,y;
    mouseevent1(){
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        addMouseListener(this);
    }
    public void mouseClicked(MouseEvent e){
         x = e.getX();
         y = e.getY();
         Graphics g=getGraphics();
         g.setColor(Color.black);
         g.drawOval((int)x-35,(int)y-35,70,70);
        
       
    }
    
     public void mouseExited(MouseEvent e) {repaint();}
     public void mousePressed(MouseEvent e) {}
     public void mouseReleased(MouseEvent e){}
     public void mouseEntered(MouseEvent e) { }
     
     public static void main(String args[]){
         mouseevent1 me=new mouseevent1();
         me.setVisible(true);
         me.setSize(800,600);
         me.setTitle("circle");
     }
}
