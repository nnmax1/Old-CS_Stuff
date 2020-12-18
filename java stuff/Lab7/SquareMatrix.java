
//SquareMatrix.java

import java.util.Random;

public class SquareMatrix {
    //size of matrix
    private static int M_SIZE;
    //2D array variable  of type int representing the current matrix
    private static int [][] matrix;
    //default constructor (M_SIZE = 5)
    public SquareMatrix() {
        Random rand = new Random();
        M_SIZE = 5;
        for(int r=0;r<M_SIZE;r++) {
            for(int c=0;c<M_SIZE;c++) {
                //get a random integer (0-9)
                int num = rand.nextInt(10);
                matrix[r][c] = num;
            }
        }
    }
    //overloaded constructor (M_SIZE = sz)
    public SquareMatrix(int sz) {
        Random rand = new Random();
        //valid sizes are between 1 and 5
        //if not in range, size will be set to 5
        if(sz > 0 && sz <6) {
            matrix = new int[sz][sz];
            M_SIZE = sz;
        }else {
            M_SIZE = 5;
        }
        for(int r=0;r<M_SIZE;r++) {
            for(int c=0;c<M_SIZE;c++) {
                //get a random integer (0-9)
                int num = rand.nextInt(10);
                matrix[r][c] = num;
            }
        }
    }
    //return elements in matrix formatted as a String
    public String toString() {
        //concactenate each element in matrix into a string
        String res="";
        for(int r=0;r<M_SIZE;r++) {
            for(int c=0;c<M_SIZE;c++) {
                res = res+" "+matrix[r][c];
            }
            res =res+ "\n";
        }
        return res;
    }
    //set an element in the matrix based on the provided row and column
    public void setElement(int row, int col, int element) {
        if(row >=0 && row <M_SIZE && col >=0 && col < M_SIZE ){
            matrix[row][col] = element;
        }else {
            System.out.println("Error. Cannot set element at given location");
        }
    }
    //get an element in the matrix based on the row and column
    public int getElement(int row, int col) {
        if(row >=0 && row <M_SIZE && col >=0 && col < M_SIZE ){
            return matrix[row][col];
        }
        //return -1 if element is not in the matrix
        return -1;
    }
    //return size of matrix
    public int getSize() {
        return M_SIZE;
    }
}