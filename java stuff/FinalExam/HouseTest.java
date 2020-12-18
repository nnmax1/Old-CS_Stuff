import java.io.*;
import java.util.ArrayList; 
import java.util.Scanner;
import java.lang.NumberFormatException;

class HouseRecord {
    public int ID;
    public int lotArea;
    public int yearBuilt, yearRemodeled;
    public int totalBasement, firstFloor, secondFloor;
    public int numFullBath, numHalfBath, numBedrooms;
    public String garageType;
    public int garageArea;
    public int mostRecentYearSold;    
    public int mostRecentSalePrice;
    public int totalSize;
    HouseRecord(String line) {
        int [] data = new int[14];
        String[] tokens = line.split("\t");
        int i=0;
        for(String tok : tokens){
            if(tok.equals("Attchd" )){
                //true
                data[i++] = 1;
            }else if(tok.equals("Detchd" )){
                //false
                data[i++] =0;
            }else {
                try {
                    data[i++] = Integer.parseInt(tok);
                }catch(NumberFormatException nfexc){
                    System.out.println(nfexc);
                }
            }
        }
        ID = data[0];
        lotArea= data[1];
        yearBuilt = data[2];
        yearRemodeled = data[3];
        totalBasement = data[4];
        firstFloor = data[5];
        secondFloor= data[6];
        numFullBath =data[7];
        numHalfBath = data[8];
        numBedrooms = data[9];
        if(data[10] == 1){
            garageType = "Attchd";
        }else if(data[10] == 0) {
            garageType = "Detchd";
        }
        garageArea = data[11];
        mostRecentYearSold = data[12];
        mostRecentSalePrice = data[13];
        totalSize = totalBasement + firstFloor + secondFloor + garageArea;
    }
}

public class HouseTest {
    public static ArrayList <HouseRecord> houseData = new ArrayList<HouseRecord>();
    
    public static void main(String args[]) {
        getData();
        Scanner scnr = new Scanner(System.in); 
        menu();
        int choice = 1;
        while(choice != 0) {
            System.out.print("Choose Menu: ");
            choice = scnr.nextInt();
            processChoice(choice);
        }
    }
    public static void menu() {
        String menu = "=== MENU ===\n";
        menu = menu + "1. Print top five youngest house IDs (remodel considered).\n";
        menu = menu + "2. Print top five oldest house IDs (remodel not considered).\n";
        menu = menu + "3. Print top five largest house IDs (basement + floors + garage)\n";
        menu = menu + menu + "4. Print bottom five house IDs in terms of lot size\n";
        menu = menu + menu + "5. Print bottom five expensive house IDs with at least 2500 sq ft (basement + floors + garage)\n";
        menu = menu + "6. Print top five most recently sold house IDs with at least 2 full bath rooms\n";
        menu = menu + "7. Print the least expensive house ID with a detached garage \n";
        menu = menu +"0. Exit\n";
        System.out.print(menu);
    }
    public static void bubbleSort_mostRecentSold(HouseRecord arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j].mostRecentYearSold < arr[j+1].mostRecentYearSold && arr[j].numFullBath >= 2) 
                { 
                    HouseRecord temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 
    public static void bubbleSort_youngest(HouseRecord arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j].yearRemodeled < arr[j+1].yearRemodeled) 
                { 
                    HouseRecord temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 
    public static void bubbleSort_oldest(HouseRecord arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j].yearBuilt > arr[j+1].yearBuilt) 
                { 
                    HouseRecord temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 

    public static void bubbleSort_largest(HouseRecord arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j].totalSize > arr[j+1].totalSize) 
                { 
                    HouseRecord temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 
    public static void bubbleSort_smallest(HouseRecord arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j].totalSize < arr[j+1].totalSize) 
                { 
                    HouseRecord temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 
    public static void bubbleSort_leastExpensive(HouseRecord arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j].mostRecentSalePrice < arr[j+1].mostRecentSalePrice && arr[j].totalSize >= 2500) 
                {
                    HouseRecord temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 


    public static void fiveYoungest() {
      HouseRecord [] houserecords = new HouseRecord[houseData.size()];
      for(int i=0;i<houseData.size();i++) {
          houserecords[i] = houseData.get(i);
      }
      bubbleSort_youngest(houserecords);
      System.out.print("top five youngest house IDs: ");
      for(int i=0;i<5;i++) {
          System.out.print(houserecords[i].ID + " , ");
      }
      System.out.println();
    }
    public static void fiveOldest() {
        HouseRecord [] houserecords = new HouseRecord[houseData.size()];
        for(int i=0;i<houseData.size();i++) {
            houserecords[i] = houseData.get(i);
        }
        bubbleSort_oldest(houserecords);
        System.out.print("top five oldest house IDs: ");
        for(int i=0;i<5;i++) {
            System.out.print(houserecords[i].ID + " , ");
        }
        System.out.println();
    }
    public static void fiveLargest() {
        HouseRecord [] houserecords = new HouseRecord[houseData.size()];
        for(int i=0;i<houseData.size();i++) {
            houserecords[i] = houseData.get(i);
        }
        bubbleSort_largest(houserecords);
        System.out.print("top five largest house IDs: ");
        for(int i=0;i<5;i++) {
            System.out.print(houserecords[i].ID + " , ");
        }
        System.out.println();
    }
    public static void bottomFiveSize() {
        HouseRecord [] houserecords = new HouseRecord[houseData.size()];
        for(int i=0;i<houseData.size();i++) {
            houserecords[i] = houseData.get(i);
        }
        bubbleSort_smallest(houserecords);
        System.out.print("bottom five smallest house IDs: ");
        for(int i=0;i<5;i++) {
            System.out.print(houserecords[i].ID + " , ");
        }
        System.out.println();
    }
    public static void bottomFiveExpensive() {
        HouseRecord [] houserecords = new HouseRecord[houseData.size()];
        for(int i=0;i<houseData.size();i++) {
            houserecords[i] = houseData.get(i);
        }
        bubbleSort_leastExpensive(houserecords);
        System.out.print("bottom 5 least expensive with at least 2500 sq ft : ");
        for(int i=0;i<5;i++) {
            System.out.print(houserecords[i].ID + " , ");
        }
        System.out.println();
    }
    public static void fiveMostRecentlySold() {

    }
    public static void leastExpensive() {
        int lowestPrice = houseData.get(0).mostRecentSalePrice;
        int minIndex = 0;
        for(int i=1;i<houseData.size();i++){
          if(houseData.get(i).mostRecentSalePrice < lowestPrice && houseData.get(i).garageType.equals("Detchd")){
            lowestPrice = houseData.get(i).mostRecentSalePrice;
            minIndex = i;
          }
        }
        System.out.println("House w/ lowest price and has Detached garage: House ID: " + (minIndex+1) );
        System.out.println("Price of house " + (minIndex+1) + ": " + lowestPrice);
    }

    public static void processChoice(int choice) {
        switch(choice) {
            case 0:
            System.out.println("exited program");
            break;
            case 1: 
            fiveYoungest();
            break;
            case 2: 
            fiveOldest();
            break;
            case 3: 
            fiveLargest();
            break;
            case 4: 
            bottomFiveSize();
            break;
            case 5: 
            bottomFiveExpensive();
            break;
            case 6: 
            fiveMostRecentlySold();
            break;
            case 7: 
            leastExpensive();
            break;
            default:
            System.out.println("invalid option"); 
            break;
        }
    }
    public static void getData() {
        FileInputStream in = null;    
        try {
            in = new FileInputStream("house.txt");
            Scanner scan = new Scanner(in);
            while (scan.hasNextLine()) {
                String line = scan.nextLine();
                HouseRecord hrec  = new HouseRecord(line);
                houseData.add(hrec);
            }
            HouseRecord house = houseData.get(0);
            System.out.println(house.mostRecentSalePrice);
        }catch(FileNotFoundException ex) {
            System.out.println(ex);
            System.exit(1);
        }
    }
}