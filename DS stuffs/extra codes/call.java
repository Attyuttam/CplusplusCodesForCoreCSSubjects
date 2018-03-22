/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author mc16120
 */
import java.util.Scanner;
class call_ref{
    int a;
    void ref(call_ref ob){
        ob.a+=5;
        System.out.println("The value of a: "+a);
    }
}

public class call {
    static void call_by_val(int a){
        a+=5;
        System.out.println("The value of a: "+a);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        //implementing call by value
        System.out.println("Enter the value of a: ");
        int a=sc.nextInt();
        System.out.println("The value of a before function call: "+a);
        call_by_val(a);
        System.out.println("The value of a after function call: "+a);
        //implementing call be reference
        call_ref cl=new call_ref();
        System.out.println("Enter another value of a: ");
        cl.a=sc.nextInt();
        System.out.println("The value of a before function call: "+cl.a);
        cl.ref(cl);
        System.out.println("The value of a after function call: "+cl.a);
        
    }
}
