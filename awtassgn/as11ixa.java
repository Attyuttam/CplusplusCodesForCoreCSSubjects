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
    double x=-10,y=-10;
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
       if(x<0){
         x = e.getX();
         y = e.getY();
       }
       else{
         Graphics g=getGraphics();
         g.drawOval((int)x-10,(int)y-10,20,20);
         x=e.getX();
         y=e.getY();
       }
     }
     public void mouseMoved(MouseEvent e){}
     public void mouseDragged(MouseEvent e){


     }
     public void mouseReleased(MouseEvent e){

     }
     public void mouseEntered(MouseEvent e) { }

     public static void main(String args[]){
         mouseevent7 me=new mouseevent7();
         me.setVisible(true);
         me.setSize(800,600);
         me.setTitle("draw line");
     }
}
