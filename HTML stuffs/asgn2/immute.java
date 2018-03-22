import java.io.*;
import java.util.*;
public class immute{
	public static void printMat(int mat[][],int m,int n){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				System.out.print(mat[i][j]);
			}
			System.out.println();
		}
		System.out.println("-----------------------");
	}
	public static void formImmute(int mat[][],int m,int n){
		int matReserve[][]=new int[m+1][n+1];
		for(int i=0;i<=m;i++){
			matReserve[i][0]=0;
		}
		for(int i=0;i<=n;i++){
			matReserve[0][i]=0;
		}
		for(int i=1;i<=m;i++){
			matReserve[i][1]=mat[i-1][0]+matReserve[i-1][1];
		}
		for(int i=1;i<=n;i++){
			matReserve[1][i]=mat[0][i-1]+matReserve[1][i-1];
		}
		for(int i=2;i<=m;i++){
			for(int j=2;j<=n;j++){
				matReserve[i][j]=mat[i-1][j-1]+matReserve[i-1][j]+matReserve[i][j-1]-matReserve[i-1][j-1];
			}
		}
		printMat(matReserve,m+1,n+1);
	}
	public static void main(String[] args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the dimensions: ");
		int m=Integer.parseInt(br.readLine());
		int n=Integer.parseInt(br.readLine());
		int mat[][]=new int[m][n];
		System.out.println("Enter the data: ");
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				mat[i][j]=Integer.parseInt(br.readLine());
			}
		}
		printMat(mat,m,n);
		formImmute(mat,m,n);
	}
}