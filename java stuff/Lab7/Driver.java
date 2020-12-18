
//Lab 7

public class Driver {
    public static void main(String args[]) {
        //test all mehtods of the SquareMatrix class: 
        SquareMatrix testClass = new SquareMatrix(4);
        System.out.println(testClass);
        testClass.setElement(0, 1, 6);
        System.out.println(testClass);
        System.out.println("Element at row 2, col 0: "+testClass.getElement(2,0));
        System.out.println("Size: "+testClass.getSize());
    }
}