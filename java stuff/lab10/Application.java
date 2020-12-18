

//Lab 10 Application.java

import java.util.Scanner;

public class Application {
    public static void main(String args[]) {
        //create a Scanner obj. sc 
        Scanner sc = new Scanner(System.in);
        //store all objects in all_objects array
        Point all_objects [] = new Point[9];
        //index counter for all_objects array
        int index =0;
        //get inputs from console using java.util.Scanner        
        for(int i=0;i<3;i++) {
            System.out.print("Enter a x coordinate: ");
            int x = sc.nextInt();
            System.out.print("Enter a y coordinate: "); 
            int y = sc.nextInt();
            System.out.print("Enter a radius value: "); 
            int r = sc.nextInt();
            System.out.print("Enter a height value: ");
            int h= sc.nextInt();
            //create a point, circle, and cylinder with the inputs
            Point point = new Point(x,y);
            Circle circle = new  Circle(r);
            circle.setCoordinates(x,y);
            Cylinder cyl = new Cylinder(h);
            cyl.setCoordinates(x, y);
            cyl.setRadius(r);
            //append the point, circle, and cylinder objects to the all_objects array
            all_objects[index++] = point;
            all_objects[index++] = circle;
            all_objects[index++] = cyl;
        }
        System.out.println("----------------------------------------------");
        System.out.println("ELEMENTS IN THE ARRAY all_objects:") ;
        System.out.println("----------------------------------------------");
        //use toString() method to print the description of each element in the all_objects array
        for(int i=0;i<all_objects.length;i++) {
            System.out.println("ELEMENT AT INDEX "+i+": \n"+all_objects[i].toString());
        }
        
    }
}