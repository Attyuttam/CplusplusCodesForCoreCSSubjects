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
class calculator extends Frame implements ActionListener{
  TextField fn,sn;
  calculator(){
      addWindowListener(new Myclass());
     // setLayout(new FlowLayout());
      this.setLayout(null);
      setBounds(100,200,300,400);
      Label fn1=new Label("First Number");//,Label.LEFT);
      Label sn1=new Label("Second Number");//,Label.LEFT);
      Button b1=new Button("+");
      Button b2=new Button("-");
      Button b3=new Button("/");
      Button b4=new Button("*");
      Button b5=new Button("clear");
      
      fn=new TextField(20);
      sn=new TextField(20);
      fn1.setBounds(100,100,100,100);
      fn.setBounds(230,140,200,30);
      sn1.setBounds(100,200,130,30);
      sn.setBounds(230,200,200,30);
      b1.setBounds(230,250,50,30);
      b2.setBounds(230,300,50,30);
      b3.setBounds(230,350,50,30);
      b4.setBounds(230,400,50,30);
      b5.setBounds(230,450,50,30);
      this.add(fn1);
      this.add(fn);
      this.add(sn1);
      this.add(sn);
      this.add(b1);
      this.add(b2);
      this.add(b3);
      this.add(b4);
      this.add(b5);
      
      //fn.addActionListener(this);
      //sn.addActionListener(this);
      b1.addActionListener(this);
      b2.addActionListener(this);
      b3.addActionListener(this);
      b4.addActionListener(this);
      b5.addActionListener(this);


//setBounds(100,200,300,400);
      
  }
  public void actionPerformed(ActionEvent ae){
      Graphics g=this.getGraphics();
      String str=ae.getActionCommand();
      //g.drawString(str,500,300);
      if(str.equals("+")){
        //this.setBackground(Color.YELLOW);
         
        g.drawString("Result: "+(Integer.parseInt(fn.getText())+Integer.parseInt(sn.getText())),500,300);
        
      }
      else if(str.equals("-")){
        //this.setBackground(Color.YELLOW);
         
        g.drawString("Result: "+(Integer.parseInt(fn.getText())-Integer.parseInt(sn.getText())),500,320);
      }
      else if(str.equals("/")){
        //this.setBackground(Color.YELLOW);
          g.drawString("",500,300);
        g.drawString("Result: "+(Integer.parseInt(fn.getText())/Integer.parseInt(sn.getText())),500,340);
      }
      else if(str.equals("*")){
        //this.setBackground(Color.YELLOW);
          g.drawString("",500,300);
        g.drawString("Result: "+(Integer.parseInt(fn.getText())*Integer.parseInt(sn.getText())),500,360);
      }
      else if(str.equals("clear")){
          repaint();
      }
            //g.drawString("Result: "+(Integer.parseInt(fn.getText())+Integer.parseInt(sn.getText())),300,200);
      
  }
  
  /*public void actionPerformed(ActionEvent ae){
      Graphics g=this.getGraphics();
      g.drawString("");
  }*/
  public static void main(String args[]){
      calculator c1=new calculator();
      c1.setTitle("calculator");
      c1.setSize(800,600);
      c1.setVisible(true);
   }
}
