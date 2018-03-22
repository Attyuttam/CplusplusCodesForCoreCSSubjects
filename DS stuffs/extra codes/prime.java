import java.io.*;
public class prime {
    public static void main(String[] args){
        int n=13,i,flag=0;
        for(i=2;i<=n/2;i++){
            if(n%i==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            System.out.println("The number is prime");
        }
        else{
            System.out.println("The number is not prime");
        }
    }
}
