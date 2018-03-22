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
class mouseevent8 extends Frame implements MouseListener{
    double x,y;
    double x2,y2;
    mouseevent8(){
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        addMouseListener(this);
        
        
      
    }
    public void paint(Graphics g){
        for(int i=1;i<=30;i++){
            g.drawRect(5, 10*i,100, 8);
        }
    }
    public void mouseClicked(MouseEvent e){}
    
     public void mouseExited(MouseEvent e) {repaint();}
     public void mousePressed(MouseEvent e) {
      x=e.getX();
      y=e.getY();
      Graphics g=getGraphics();
      if(x>=5 && x<=105){
            for(int i=1;i<=30;i++){
                if(y>=10*i && y<=(10*i+8)){
                    g.setColor(Color.white);
                    g.drawLine(5,10*i,105,10*i);
                    g.drawLine(5,10*i,5,10*i+8);
                    g.drawLine(5,10*i+8,105,10*i+8);
                    g.drawLine(105,10*i,105,10*i+8);
                    g.setColor(Color.black);
                    break;
                }
            }
        }
     }
  
     public void mouseReleased(MouseEvent e){
        
        
     }
     public void mouseEntered(MouseEvent e) { }
     
     public static void main(String args[]){
         mouseevent8 me=new mouseevent8();
         me.setVisible(true);
         me.setSize(800,600);
         me.setTitle("draw line");
     }
}
