import java.awt.*;
import java.util.*;
import java.applet.*;
import java.text.*;
public class cl extends Applet implements Runnable{
  Thread t=null;
  Label l1,l2,l3;
  int hours=0,minutes=0,seconds=0;
  public void init(){
    setBackground(Color.black);

  }
  public void start(){
    t=new Thread(this);
    t.start();
  }
  public void run(){
    try{
      while(true){
        Calendar cal=Calendar.getInstance();
        hours=cal.get(Calendar.HOUR_OF_DAY);
        minutes=cal.get(Calendar.MINUTE);
        seconds=cal.get(Calendar.SECOND);
        repaint();
        t.sleep(1000);
      }
    }
    catch(Exception e){}
  }
  public void paint(Graphics g){
    g.setColor(Color.yellow);
    g.drawString(String.valueOf(hours)+" : ",50,50);

    g.drawString(String.valueOf(minutes)+" : ",65,50);
    g.drawString(String.valueOf(seconds)+" : ",80,50);
  }
}
