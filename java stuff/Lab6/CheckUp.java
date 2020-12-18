class CheckUp {
    //CheckUp instance vars
    private String patientNumber;
    private int systolic;
    private int diatolic; 
    private double hdl;
    private double ldl;
    //default constructor
    public CheckUp() {
        patientNumber ="0";
    }
    //constructor to init a CheckUp obj. 
    //with a patient number
    public CheckUp(String p) {
        patientNumber = p;
    }
    //setter and getter methods
    public void setSystolic(int s) {
        systolic = s;
    }
    public void setDiatolic(int d) {
        diatolic = d;
    }
    public int getSystolic() {
        return systolic;
    }
    public int getDiatolic() {
        return diatolic;
    }
    public void setHDL(double h) {
        hdl = h;
    }
    public void setLDL(double l) {
       ldl = l;
    }
    public double getHDL() {
        return hdl;
    }
    public double getLDL() {
        return ldl;
    }
    //compute ratio
    public double computeRatio() {
        return ldl/hdl;
    }
    //return a message (as a String) with patient info
    public String toString() {
        String msg = "Summary for Patient #";
        msg= msg + patientNumber +"\n";
        msg = msg+ "  --Systolic: " + systolic+"\n";
        msg = msg + "  --Diatolic: "+diatolic+"\n";
        msg = msg + "  --LDL: "+ ldl+"\n";
        msg = msg + "  --HDL: "+ hdl+"\n";
        msg = msg + "  --Cholesterol Ratio: "+  String.format("%.5f", computeRatio()) + "\n";
        msg = msg + "  --HDL is known as “good cholesterol”.\n  --A ratio of 3.5 or lower is considered optimum.\n";
        return msg;
    }
}