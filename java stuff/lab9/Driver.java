
//Lab 9: Driver.java

public class Driver  {
    public static void main(String args[]){
    Rectangle r1 = new Rectangle(10, 5 , -4, 10,  "blue");
    Rectangle r2 = new Rectangle(10, 5, 4, 10, "green");
    Rectangle r3 = new Rectangle() ;
  
    //test get and set methods
    r3.setX(8.9);
    r3.setY(3.2);
    r3.setHeight(8.4);
    r3.setWidth(7.4);
    r3.setColor("blue");
    r3.getX();
    r3.getY();
    r3.getHeight();
    r3.getWidth();
    r3.getColor();


    //test toString
    System.out.println(r1);
    System.out.println(r2);
    System.out.println(r3);
    }
}