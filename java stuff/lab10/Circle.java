
//Lab 10 Circle.java

public class Circle extends Point {
    // radius 
    private double radius;
    // default constructor
    public Circle() {
        radius = 0;
    }
    // overloaded constructor
    public Circle(double r) {
        if (r < 0) {
            System.out.print("Negative radii are not allowed.");
            r= 0;
        }else {
            radius = r; 
        }
    }
    // method to set radius
    public void setRadius(double r) {
        radius = r;
        if (r < 0) {
            System.out.print("Negative radii are not allowed.");
            r= 0;
        }else {
            radius = r; 
        }
    }
    //return radius
    public double getRadius() {
        return radius;
    }
    //return area of Circle
    public double getArea() {
        double area = Math.PI * (radius * radius);
        return area;
    }
    //overriden toString()
    @Override
    public String toString(){
        String ret = "";
        ret = ret +"Point (x,y): ("+getX_coord()+" , "+getY_coord()+")\n";
        ret = ret + "Radius: "+radius+"\n";
        ret = ret + "Area: " + String.format("%.5f",getArea()) + "\n";
        return ret;
    }
}