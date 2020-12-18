//Nicholas Ngai   
//Lab 8 : RectPrism.java


import java.util.Scanner;

public class Demo {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        //RectPrism object 
        RectPrism rectprism = new RectPrism();
        //get prism dimensions
        System.out.print("Enter a height for the rectangular prism: ");
        rectprism.setHeight(sc.nextInt());
        System.out.print("Enter a width for the rectangular prism: ");
        rectprism.setWidth(sc.nextInt());
        System.out.print("Enter a depth for the rectangular prism: ");
        rectprism.setDepth(sc.nextInt());
        System.out.println("--------------------------------");
        //print the rectprism object using toString()
        System.out.println(rectprism);


        //Rectangle object with height 3, and width 4
        Rectangle rect = new Rectangle(3, 4);
        System.out.println(rect);
    }
}