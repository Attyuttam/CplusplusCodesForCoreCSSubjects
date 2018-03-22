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
class mouseevent5 extends Frame implements MouseListener{
    double x,y;
    double x2,y2;
    mouseevent5(){
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        addMouseListener(this);
    }
    public void mouseClicked(MouseEvent e){}

     public void mouseExited(MouseEvent e) {repaint();}
     public void mousePressed(MouseEvent e) {
         x = e.getX();
         y = e.getY();
     }

     public void mouseReleased(MouseEvent e){
         x2 = e.getX();
         y2 = e.getY();
         Graphics g=getGraphics();
         g.setColor(Color.black);

         g.drawLine((int)x,(int)y,(int)x,(int)y2);
         g.drawLine((int)x,(int)y,(int)x2,(int)(y));
         g.drawLine((int)(x),(int)y2,(int)x2,(int)y2);
         g.drawLine((int)x2,(int)(y),(int)x2,(int)y2);
     }
     public void mouseEntered(MouseEvent e) { }

     public static void main(String args[]){
         mouseevent5 me=new mouseevent5();
         me.setVisible(true);
         me.setSize(800,600);
         me.setTitle("draw line");
     }
}
