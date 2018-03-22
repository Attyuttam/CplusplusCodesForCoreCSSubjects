import java.awt.*;
import java.awt.event.*;
class pattern extends Frame{
	pattern(){
		setBackground(Color.cyan);
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
	}
	public void drawtriangle(int ox1,int oy1,int ox2,int oy2,int ox3,int oy3,int ptx1,int pty1,int ptx2,int pty2,int ptx3,int pty3,int n){
		if(n>0){
			Graphics g=getGraphics();
			g.drawLine(ptx1,pty1,ptx2,pty2);
			g.drawLine(ptx1,pty1,ptx3,pty3);
			g.drawLine(ptx2,pty2,ptx3,pty3);
			//the left side
			int mx1=(ptx1+ox2)/2;
			int mx2=(pty1+oy2)/2;
			int mx3=(ptx1+ptx3)/2;
			int mx4=(pty1+pty3)/2;
			int mx5=(ox2+ptx3)/2;
			int mx6=(oy2+pty3)/2;
			//System.out.println(mx1+" "+mx2+" "+mx3+" "+mx4+" "+mx5+" "+mx6+" ");
			drawtriangle(ptx1,pty1,ox2,oy2,ptx3,pty3,mx1,mx2,mx3,mx4,mx5,mx6,n-1);
			//the top part
			mx1=(ox1+ptx1)/2;
			mx2=(oy1+pty1)/2;
			mx3=(ox1+ptx2)/2;
			mx4=(oy1+pty2)/2;
			mx5=(ptx1+ptx2)/2;
			mx6=(pty1+pty2)/2;
			drawtriangle(ox1,oy1,ptx1,pty1,ptx2,pty2,mx1,mx2,mx3,mx4,mx5,mx6,n-1);
			//the right part
			mx1=(ptx2+ptx3)/2;
			mx2=(pty2+pty3)/2;
			mx3=(ptx2+ox3)/2;
			mx4=(pty2+oy3)/2;
			mx5=(ptx3+ox3)/2;
			mx6=(pty3+oy3)/2;

			drawtriangle(ptx2,pty2,ptx3,pty3,ox3,oy3,mx1,mx2,mx3,mx4,mx5,mx6,n-1);
		}

	}
	public void paint(Graphics g){
		g.drawLine(400,50,100,500);
		g.drawLine(400,50,700,500);
		g.drawLine(100,500,700,500);
		drawtriangle(400,50,100,500,700,500,250,275,550,275,400,500,7);

	}
	public static void main(String args[]){
		pattern p=new pattern();
		p.setVisible(true);
		p.setSize(800,800);
		p.setTitle("pattern");
	}
}
