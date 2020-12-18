

//Lab 10 Cylinder.java


public class Cylinder extends Circle{
    // height var
    private double height;
    // default constructor
    public Cylinder() {
        height = 0;
    }
    // overloaded constructor
    public Cylinder(double h) {
        if(h < 0) {
            System.out.print("Negative heights are not allowed.");
        }else {
            height  = h;
        }
    }
    // set height
    public void setHeight(double h) {
        if(h < 0) {
            System.out.print("Negative heights are not allowed.");
        }else {
            height  = h;
        }
    }
    // return height
    public double getHeight() {
        return height;
    }
    // return volume
    public double getVolume() {
        return getArea() * height;
    }
    // overridden toString() method
    @Override
    public String toString() {
        String ret = "";
        ret = ret +"Point (x,y): ("+getX_coord()+" , "+getY_coord()+")\n";
        ret = ret + "Radius: "+getRadius()+"\n";
        ret = ret + "Height : "+height + "\n";
        ret = ret + "Area: " + String.format("%.5f",getArea()) + "\n";
        ret = ret + "Volume : "+String.format("%.5f",getVolume()) + "\n";
        return ret;
    }
}