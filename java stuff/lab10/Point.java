

//Lab 10 Point.java



public class Point {
    // (x, y) coordinate
    private int x_coord;
    private int y_coord;
    //default constructor
    public Point() {
        x_coord = 0;
        y_coord = 0;
    }
    //overloaded constructor
    public Point(int x, int y) {
        x_coord = x;
        y_coord = y;
    }
    //set x  and y coordinates
    public void setCoordinates(int x, int y) {
        x_coord = x;
        y_coord = y;
    } 
    //return x_coord
    public int getX_coord(){
        return x_coord;
    }
    //return y coordinate
    public int getY_coord(){
        return y_coord;
    }
    //prints the coordinates of the point.
    public String toString() {
        String ret = "";
        ret = "Point (x,y): ("+x_coord+" , "+y_coord+")\n";
        return ret;
    }

}