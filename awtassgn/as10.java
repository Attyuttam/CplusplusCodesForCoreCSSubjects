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


class menu extends Frame{
    menu(){
        this.addWindowListener(
                new WindowAdapter(){
                    public void windowClosing(WindowEvent e){
                        System.exit(0);
                    }
                }
        );
        MenuBar m=new MenuBar();
        Menu m1=new Menu("File");
        MenuItem i1=new MenuItem("New");
        MenuItem i2=new MenuItem("Save");
        MenuItem i3=new MenuItem("Open");
        Menu sub=new Menu("sub");
        MenuItem i4=new MenuItem("New sub");
        MenuItem i5=new MenuItem("Save sub");
        MenuItem i6=new MenuItem("Open sub");
        sub.add(i4);
        sub.add(i5);
        sub.add(i6);
        
        m1.add(i1);
        m1.add(i2);
        m1.add(i3);
        m1.add(sub);
        m.add(m1);
        setMenuBar(m);
        
    }
    public static void main(String args[]){
        menu m1=new menu();
        m1.setTitle("assignment1");
        m1.setSize(800,900);
        m1.setVisible(true);
    }
    
}
