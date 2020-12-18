
//Lab 8 : Rectangle.java


public class Rectangle {
    private double height;
    private double width;
    //default constructor
    //initializes height and width to 0
    public Rectangle() {
        height = 0;
        width = 0;
    }
    //overloaded constructor
    public Rectangle(double h, double w) {
        height = h;
        width = w;
    }
    //get and set methods for height and width: 
    public void setHeight(double h) {
        height = h;
    }
    public void setWidth(double w) {
        width = w;
    }
    public double getHeight() {
        return height;
    }
    public double getWidth() {
        return width;
    }
    //return dimensions and surface area as a String
    public String toString() {
        String res = "";
        res = res+"Height: "+height+"\n";
        res = res+"Width: "+width+"\n";
        res = res+ "Surface Area: "+ String.format("%.2f",computeSurfaceArea())+"\n";
        return res;
    }
    //returns surface area of the rectangle
    public double computeSurfaceArea() {
        return height * width;
    }

}