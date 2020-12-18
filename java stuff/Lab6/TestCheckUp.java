public class TestCheckUp {
    public static void main(String args[]) {
        //create 2 CheckUp objects with patient ID's
        CheckUp a = new CheckUp("8383829");
        CheckUp b = new CheckUp("1889389");

        //set fields for a and b
        a.setHDL(95.2);
        a.setLDL(43.9);
        a.setSystolic(120);
        a.setDiatolic(70);
        b.setHDL(101.82);
        b.setLDL(48.9);
        b.setSystolic(140);
        b.setDiatolic(90);
        //Note: decimal precision for cholesterol ratio is set to 5.

        //print health data for a to console
        System.out.println("Data for a: ");
        System.out.println("Systolic: "+a.getSystolic());
        System.out.println("Diatolic: "+ a.getDiatolic());
        System.out.println("LDL: "+a.getLDL());
        System.out.println("HDL: "+ a.getHDL());
        System.out.println("Cholesterol Ratio for a: "  + String.format("%.5f", a.computeRatio()) );
        //print health data for b to console
        System.out.println("\nData for b: ");
        System.out.println("Systolic: "+b.getSystolic());
        System.out.println("Diatolic: "+ b.getDiatolic());
        System.out.println("LDL: "+b.getLDL());
        System.out.println("HDL: "+ b.getHDL());
        System.out.println("Cholesterol Ratio for b: "  + String.format("%.5f", b.computeRatio()) );

        //call toString() to print patient message
        System.out.println("");
        System.out.println(a.toString());
        System.out.println(b.toString());

    }
}