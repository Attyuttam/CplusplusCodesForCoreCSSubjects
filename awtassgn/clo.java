import java.awt.*;
import java.util.*;

class clocktest extends Frame{
  Label l1,l2,l3;
  clocktest(){
  //  setBackground(Color.black);
    l1=new Label();l2=new Label();l3=new Label();
    setLayout(null);
    add(l1);add(l2);add(l3);
    l1.setBounds(50,50,50,50);l2.setBounds(120,50,50,50);l3.setBounds(190,50,50,50);
  //}
  //public void paint(Graphics g){
    //while(true){
    //Graphics g=this.getGraphics();

      //try{
     while(true){
      //g.setColor(Color.yellow);
      Calendar cal=Calendar.getInstance();
      l1.setText(String.valueOf(cal.get(Calendar.HOUR_OF_DAY)));
      l2.setText(String.valueOf(cal.get(Calendar.MINUTE)));
      l3.setText(String.valueOf(cal.get(Calendar.SECOND)));
      setVisible(true);
      setSize(800,800);

      //Thread.sleep(1000);}}catch(InterruptedException e){}
    }
  }
}

public class clo{
  public static void main(String[] args) {
clocktest ct=new clocktest();
    ct.setVisible(true);
    ct.setSize(800,800);

  }

}
