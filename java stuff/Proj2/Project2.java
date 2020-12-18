
//Project 2: Matrix operations

import java.io.*;
import java.util.Scanner;

public class Project2 {


    public static void main(String args[]) throws IOException { 
        //variables to store the dimensions of M1 & M2
        int[] rows=  {0,0};
        int[] cols = {0,0}; 
        //get matrix dimensions(rows, cols)
        getDimensions(rows, cols);
        //create 2 matrix variables with the dimensions
        //provided by user
        int [][] M1 = new int[rows[0]][cols[0]];
        int [][] M2 = new int[rows[1]][cols[1]];
        //fill matrices M1 and M2 with values entered by the user. 
        System.out.println("Enter elements for M1, in row major order");
        fillMatrix(M1);
        System.out.println("M1: ");
        showMatrix(M1);
        System.out.println("--------------------------");
        System.out.println("Enter elements for M2, in row major order");
        fillMatrix(M2);
        System.out.println("M2: ");
        showMatrix(M2);
        System.out.println("--------------------------");

        //Transpose of Matrix M1:
        System.out.println("M3 (transpose of M1):");
        int [][] M3  = new int[M1[0].length][M1.length];
        //store the transpose of M1 in variable M3
        M3 = getTranspose(M1);
        showMatrix(M3);
        System.out.println("--------------------------");

        //matrix addition:
        //check if matrices have same dimensions before 
        if(M1.length == M2.length && M1[0].length == M2[0].length) {
            int [][] sum = new int[M1.length][M1[0].length];
            sum = getSum(M1, M2);
            System.out.println("M1 + M2:");
            showMatrix(sum);
        }else {
            System.out.println("Error. Matrices must have same dimensions to perform matrix addition");
        }
        System.out.println("--------------------------");

        //matrix multiplication: 
        if(M1.length == M2[0].length && M1[0].length == M2.length) {
        int [][] product  = new int[M1.length][M2[0].length];
        product = getProduct(M1, M2);
        System.out.println("M1 * M2: ");
        showMatrix(product);
        }else {
            System.out.println("Error.");
            System.out.println("For matrix multiplication, the number of columns in the first matrix");
            System.out.println("must be equal to the number of rows in the second matrix.");
        }
        System.out.println("--------------------------");
    }
    //returns the product of two matrices
    public static int[][] getProduct(int M1[][], int M2[][]) {
        int [][] res = new int[M1.length][M2[0].length];

        for (int i = 0; i < M1.length; i++) { 
            for (int j = 0; j < M2[0].length; j++) { 
                for (int k = 0; k < M1[0].length; k++) { 
                    res[i][j] += M1[i][k] * M2[k][j];
                }
            }
        }
        return res;
    }
    //returns the sum of two matrices
    public static int[][] getSum(int [][] M1, int[][]M2) {
        int[][] sum = new int[M1.length][M1[0].length];
        for(int i = 0; i < M1.length; i++) {
            for (int j = 0; j < M1[0].length; j++) {
                sum[i][j] = M1[i][j] + M2[i][j];
            }
        }
        return sum;
    }
    //return transpose of a Matrix
    public static int [][] getTranspose(int [][] M) {
        int [][]res = new int[M[0].length][M.length];
        for(int r=0;r<M[0].length;r++) {
            for(int c=0;c<M.length;c++) {
                res[r][c] = M[c][r];
            }
        }
        return res;
    }
    //print matrix to console
    public static void showMatrix(int [][] M) {
        for(int r=0;r<M.length;r++){
            for(int c=0;c<M[0].length;c++) {
                System.out.print(M[r][c]+ " ");
            }
            System.out.println();
        }
    }
    //fill a matrix with value entered from console
    public static void fillMatrix( int [][] M) {
        Scanner sc = new Scanner(System.in); 
        for(int r=0;r<M.length;r++){
            for(int c=0;c<M[0].length;c++) {
                M[r][c] = sc.nextInt();
            }
        }
    }
    //get rows and cols for 2 matrices
    public static void getDimensions(int []rows, int []cols) {
        Scanner sc = new Scanner(System.in); 
        
        for(int i=0;i<2;i++) {
            //get the number of rows
            System.out.println("Enter number of rows for M"+(i+1)); 
            int tempRow = sc.nextInt();
            //only accept positive values for the number of rows
            while(tempRow < 0) {
                System.out.println("Invalid value. Enter a value > 0:");
                tempRow = sc.nextInt();
            }
            rows[i] = tempRow;
            //get number of columns
            System.out.println("Enter number of columns for M"+(i+1));
            int tempCol = sc.nextInt();
            //only accept positive values for the number of columns
            while(tempCol < 0) {
                System.out.println("Invalid value. Enter a value > 0:");
                tempCol= sc.nextInt();
            }
            cols[i] = tempCol;
        }
    }
}