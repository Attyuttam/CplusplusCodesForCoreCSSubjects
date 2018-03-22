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
class mouseevent9 extends Frame implements MouseListener{
    double x,y;
    double x2,y2;
    mouseevent9(){
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        addMouseListener(this);  
      
    }
    public void paint(Graphics g){
        for(int i=1;i<=15;i++){
            g.drawOval(5, 40*i,20,20);
        }
    }
     public void mouseClicked(MouseEvent e){
         x=e.getX();
         y=e.getY();
         Graphics g=getGraphics();
                double cx=0;
                double cy=40;
                double maxcx=0;
                double maxcy=40;
                double maxval=Math.sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy));
         for(int i=2;i<=30;i++){
                cx=0;
                cy=40*i;
                double val=Math.sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy));
                if(val<maxval){
                    maxval=val;
                    maxcx=cx;
                    maxcy=cy;
                }

            }
                    g.setColor(Color.white);
                    g.drawOval(5,(int)maxcy,20,20);
                    g.setColor(Color.black);

     }
     public void mouseExited(MouseEvent e) {repaint();}
     public void mousePressed(MouseEvent e){} 
     
  
     public void mouseReleased(MouseEvent e){
        
        
     }
     public void mouseEntered(MouseEvent e) { }
     
     public static void main(String args[]){
         mouseevent9 me=new mouseevent9();
         me.setVisible(true);
         me.setSize(800,600);
         me.setTitle("draw line");
     }
}
