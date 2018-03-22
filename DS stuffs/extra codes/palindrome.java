import java.io.*;
public class palindrome {
    public static void main(String[] args){
        int n=123,t,p=0,r;
        t=n;
        while(t!=0){
            r=t%10;
            p=p*10+r;
            t/=10;
        }
        if(p==n){
            System.out.println("The number is a palindrome");
        }
        else{
            System.out.println("The number is not a palindrome");
        }
    }
}
