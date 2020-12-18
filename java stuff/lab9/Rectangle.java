
//Lab 9: Rectangle.java

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


    public Rectangle() {
        x =0;
        y = 0;
        width = 1;
        height = 1;
        color = "red";
    }
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