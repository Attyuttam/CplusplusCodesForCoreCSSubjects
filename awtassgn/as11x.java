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
class mouseevent7 extends Frame implements MouseListener,MouseMotionListener{
    double x,y;
    double x2,y2;
    mouseevent7(){
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        addMouseListener(this);
        addMouseMotionListener(this);
    }
    public void mouseClicked(MouseEvent e){}
    
     public void mouseExited(MouseEvent e) {repaint();}
     public void mousePressed(MouseEvent e) {
         x = e.getX();
         y = e.getY();
     }
     public void mouseMoved(MouseEvent e){}
     public void mouseDragged(MouseEvent e){
         Graphics g=getGraphics();
         //x2=x;
         //y2=y;
         g.setColor(Color.white);
         g.drawLine((int)x,(int)y,(int)x2,(int)y2);
         g.setColor(Color.black);
         g.drawLine((int)x,(int)y,(int)e.getX(),(int)e.getY());
         x2=e.getX();
         y2=e.getY();
         
     }
     public void mouseReleased(MouseEvent e){
         x2 = e.getX();
         y2 = e.getY();
         Graphics g=getGraphics();
         g.setColor(Color.black);
        
        g.drawLine((int)x,(int)y,(int)x2,(int)y2);
        
     }
     public void mouseEntered(MouseEvent e) { }
     
     public static void main(String args[]){
         mouseevent7 me=new mouseevent7();
         me.setVisible(true);
         me.setSize(800,600);
         me.setTitle("draw line");
     }
}
