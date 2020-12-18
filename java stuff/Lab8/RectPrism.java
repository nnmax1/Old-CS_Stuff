
//Lab 8: RectPrism.java


public class RectPrism extends Rectangle {
    private double depth;
    //default constructor
    //initialize everything to 0
    RectPrism() {
        super.setHeight(0);
        super.setWidth(0);
        depth = 0;
    }
    //overloaded constructor
    RectPrism(double d) {
        depth = d;
    }
    //set depth
    public void setDepth(double d) {
        depth = d;
    }
    //returns depth
    public double getDepth() {
        return depth;
    }
    //prints dimensions, surface area, and volume
    @Override
    public String toString() {
        String res = "";
        res = res+"Height: "+super.getHeight()+"\n";
        res = res+"Width: "+super.getWidth()+"\n";
        res = res+"Depth: "+depth+"\n";
        res = res+ "Surface Area: "+ String.format("%.2f",computeSurfaceArea())+"\n";
        res = res+ "Volume: "+ String.format("%.2f",computeVolume())+"\n";
        return res;
    }
    //returns surface area of the prism
    @Override 
    public double computeSurfaceArea() {
       //Formula for S.A:   S.A= 2(wl+hl+hw)
        double wl = super.getWidth() * depth;
        double hl = super.getHeight() * depth;
        double hw = super.getHeight() * super.getWidth();
        return 2 * ( wl + hl + hw);
    }
    //returns volume
    public double computeVolume() {
        //Formula: V = h*w*l
        return super.getHeight() * super.getWidth() * depth;
    }

}