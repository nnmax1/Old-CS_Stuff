import java.util.Scanner;

public class SieveTest {
    public static void sieveOfEratosthenes(int bound) 
    { 
        boolean primes[] = new boolean[bound+1]; 
        for(int i=0;i<bound;i++) {
            primes[i] = true; 
        }
        for(int p = 2; p*p <=bound; p++) { 
            if(primes[p] == true) { 
                for(int i = p*p; i <= bound; i += p) {
                    primes[i] = false; 
                }
            } 
        } 
        for(int i = 2; i <= bound; i++) { 
            if(primes[i] == true) 
                System.out.print(i + " "); 
        } 
        System.out.println();
    }
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Bound?: ");
        int bound = scan.nextInt();
        sieveOfEratosthenes(bound);
    } 
}