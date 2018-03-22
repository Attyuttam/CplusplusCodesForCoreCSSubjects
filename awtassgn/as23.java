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
class face extends Frame{
    face(){
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });

    }
    public void paint(Graphics g){
        for(int i=0;i<=530;i+=160){
            g.setColor(Color.black);
            g.drawOval(50+i,150,150,150);
            g.setColor(Color.blue);
            g.fillOval(80+i, 180, 30, 30);
            g.fillOval(140+i, 180, 30, 30);
            g.setColor(Color.red);
            g.drawLine(90+i,250,160+i,250);
        }


    }
    public static void main(String args[]){
        face f=new face();
        f.setVisible(true);
        f.setSize(800,600);
        f.setTitle("face");
    }
}
