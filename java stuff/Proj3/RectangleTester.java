
//Project 3: RectangleTester.java

public class RectangleTester{
    public static void main(String args[]) {
        Rectangle rectObj = new Rectangle(2, 3, 25, 30, "blue");
        Rectangle rect = new Rectangle();
        Rectangle rectObj_copy = new Rectangle();
        //test set methods
        rect.setX(1);
        rect.setY(8);
        rect.setHeight(17);
        rect.setWidth(28);
        rect.setColor("green");
        //test get methods 
        System.out.println("(x , y): ("+rectObj.getX() + ", "+rectObj.getY()+") ");
        System.out.println("height x width: " + rectObj.getHeight() +" x " + rectObj.getWidth());
        System.out.println("color: " + rectObj.getColor());
        System.out.println("Area: " + rectObj.computeArea());
        System.out.println("Perimeter: " + rectObj.computePerimeter());
        rectObj_copy  = rectObj;
        //test equals()
        if(rectObj.equals(rectObj_copy) ){
            System.out.println("rectObj == rectObj_copy");
        }
        //test containsRectangle()
        if(rectObj.containsRectangle(rect)) {
            System.out.println("rectObj contains rect");
        }
        //test containsPoint()
        if(rectObj.containsPoint(2, 4)) {
            System.out.println("rectObj contains P(2, 4)");
        }
        if(!rectObj.containsPoint(26, 31)) {
            System.out.println("rectObj does not  contains P(36, 21)");   
        }
        //test intersects()
        if(rectObj.intersects(rect)) {
            System.out.println("rectObject intersects rect");
        }

        //test toString()
        System.out.println("\nrectObj.toString(): \n" + rectObj);
        System.out.println("\nrect.toString(): \n" + rect);

    }
}