import java.applet.*;
import java.awt.*;

public class cartoon extends Applet
{
    int y = 200;
    public void init()
    {
        setBackground(Color.YELLOW);
    }

    public void stop()
    {
        if(y==200)y = 50;
        else y = 200;
    }

    public void paint(Graphics g)
    {
        g.drawOval(200,50,100,100);
        g.drawRect(50,150,400,50);

        g.drawRect(50,y,50,100);
        g.drawRect(400,y,50,100);

        g.drawRect(150,200,200,300);

        g.drawRect(150,500,50,100);
        g.drawRect(300,500,50,100);
    }
}
/*
<applet code="toonApplet" width="500" height="700"></applet>
*/
