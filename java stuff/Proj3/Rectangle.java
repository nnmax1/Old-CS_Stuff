
//Project 3: Rectangle.java

public class Rectangle {
    double x, y;
    double width, height;
    String color; 

    //getter methods 
    public double getY() {return y;}
    public double getX() {return x;}
    public double getWidth() {return width;}
    public double getHeight() {return height;}
    public String  getColor() {return color; }
    //setter methods
    public void setX(double x) {this.x = x;}
    public void setY(double y){this.y = y;}
    public void setWidth(double w){this.width =w;}
    public void setHeight(double h){this.height = h;}
    public void setColor(String c){this.color = c;}
    //default constructor
    public Rectangle() {
        x =0;
        y = 0;
        width = 1;
        height = 1;
        color = "red";
    }
    //overloaded constructor
    public Rectangle(double x, double y, double h, double w, String c) {
        if(Rectangle.isValid(x, y, h, w)) {
            this.x = x;
            this.y  = y;
            this.height = h;
            this.width = w;
            this.color = c;
        }else {
            this.x = 0;
            this.y  = 0;
            this.height = 1;
            this.width = 1;
            this.color = "red";
        }
    }
    //check if current Rectangle obj == another Rectangle obj
    boolean equals(Rectangle rect) {
        boolean xyCheck = false, hwCheck = false, colorCheck = false;
        if(this.x == rect.x &this.y  == rect.y) {
            xyCheck = true;
        }
        if(this.height == rect.height && this.width == rect.width){
            hwCheck = true;
        }
        if(this.color == rect.color){
            colorCheck = true;
        }
        return xyCheck && hwCheck && colorCheck;
    }
    //check if curr rectangle contains a point (x, y)
    boolean containsPoint(double x, double y){
        boolean xVal = false, yVal = false;
        if(x >= 0 && x <= this.width){
            xVal = true;
        }
        if( y>=0 && y<= this.height) {
            yVal = true;
        }
        return xVal && yVal;
    }
    //check if current rectangle contains another rectangle obj
    boolean containsRectangle(Rectangle rect) {
        return this.height > rect.height && this.width > rect.width; 
    }
    //check if rectangle intersects with another rectangle
    boolean intersects(Rectangle rect){
        return this.height > rect.height && this.width > rect.width && containsPoint(rect.x, rect.y);
    }
    //return area
    double computeArea() {
        return this.height * this.width;
    }
    //return perimeter
    double computePerimeter() {
        return 2*this.height + 2*this.width;
   }
   public static boolean isValid(double x, double y, double w, double h)  {
        if(x > 0 && y > 0 && w > 0 && h > 0) {
            return true;
        }
        return false;
    }

    public String toString() {
        String ret = "";
        ret = ret + "(x,y) = ("+ x + ", "+y+") \n";
        ret = ret + "Width = "+ width +" / ";
        ret = ret + "Height = " + height +"\n";
        ret = ret + "Color: " + color + "\n";
        return ret;
    }
}