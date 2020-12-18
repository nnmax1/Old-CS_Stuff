import java.util.Scanner;

public class EuclidTest {   
    
    public static int recursiveEuclid(int a, int b) {
        if (b == 0) return a;
        else return recursiveEuclid(b, a % b);
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.print("First?: ");
        int n1 = scan.nextInt();
        System.out.print("Second?: ");
        int n2 = scan.nextInt();
        System.out.println("GCD: " + recursiveEuclid(n1, n2));


    }
}