
//Project 4: NameSurfer.java

import java.io.*;
import java.util.ArrayList; 
import java.util.Scanner;
import java.util.InputMismatchException;

public class NameSurfer {
    //store name records from file in namerecords instance var
    private static ArrayList<NameRecord> nameRecords = new ArrayList<NameRecord>();

    public static void main(String args[]) throws IOException{
        storeData();
        boolean quit = false;
        //run NameSurfer until the user wants to quit
        while(quit == false) {
            quit = processMenuOptions();
        }
    }

    public static boolean processMenuOptions() {
        Scanner scan = new Scanner(System.in);
        boolean quit =false;
        int option =  showMenu();
        String name;
        switch(option) {
            //get best year for a given name
            case 1:
            System.out.print("Enter a name: ");
            name = scan.next();
            int by = getBestYear(name);
            if(by == -1) {
                System.out.println("Best year could not be found for "+name);
            }else {
                System.out.println("Best Year for "+name+": "+ by );
            }
            quit = false;
            break;
            //get the best rank for a given name
            case 2: 
            System.out.print("Enter a name: ");
            name = scan.next();
            int br = getBestRank(name);
            if(br == -1) {
                System.out.println("Best rank could not be found for "+ name);
            }else {
                System.out.println("Best Rank for "+name+": "+br);
            }
            quit = false;
            break;
            //plot popularity of a name
            case 3:
            System.out.println("Not implemented");
            quit =false;
            break;
            //clear plot
            case 4: 
            System.out.println("Not implemented");
            quit = false;
            break;
            //quit 
            case 5: 
            quit = true;
            System.out.println("NameSurfer Application was terminated.");
            break;
        }
        return quit;
    }
    //return the best year based on the name.
    //linear search algorithm
    public static int getBestYear(String name) {
        int bestYear =0;
        for(int i=0;i<nameRecords.size();i++) {
            NameRecord n = nameRecords.get(i);
            if(name.equals(n.get_name())) {
                bestYear = n.bestYear();
                return bestYear;
            }
        }
        //return -1 if name is not in the ArrayList nameRecords
        return -1;
    }
    //return the best rank based on name
    //linear search algorithm
    public static int getBestRank(String name) {
        int bestRank = 0;
        for(int i=0;i<nameRecords.size();i++) {
            NameRecord n = nameRecords.get(i);
            if(name.equals(n.get_name())) {
                bestRank = n.getRank( n.bestYear() );
                return bestRank;
            }
        }
        //return -1 if name is not in the ArrayList nameRecords
        return -1;
    }
    //prints menu options to the console. 
    public static int showMenu() {
        String ret = "";
        int option = 0;
        Scanner scan = new Scanner(System.in);
        ret = ret + "------------------------------\n";
        ret = ret + "            MENU              \n";
        ret = ret + "1 – Find best year for a name\n";
        ret = ret + "2 – Find best rank for a name\n";
        ret = ret +"3 – Plot popularity of a name (extra credit)\n";
        ret = ret + "4 – Clear plot (extra credit)\n";
        ret = ret +"5 – Quit\n";
        ret = ret + "------------------------------\n";
        ret = ret + "Enter your selection: ";
        System.out.print(ret);
    
        do{ 
            try {
                option = scan.nextInt();
            }catch(InputMismatchException imexception) {
                System.out.println("Choice must be entered as a number.");
            }
            if(option < 1 || option > 5){
                System.out.println("Invalid option.");
            }           
        }while(option <1 &&option > 5 );
     
        return option;
    }
    //reads data from the file name_data.txt and stores the data into the
    //instance variable namerecords of type ArrayList<NameRecord>
    public static void storeData() {
        //fileinputstream object
        FileInputStream in = null;    
        try {
            //init the fileinputstream object with the filename
            in = new FileInputStream("name_data.txt");
            //create Scanner object with Fileinput stream object
            Scanner scan = new Scanner(in);
            //read data into ArrayList arr
            while (scan.hasNextLine()) {
                String line = scan.nextLine();
                NameRecord namerec = new NameRecord(line);
                nameRecords.add(namerec);
            }
        //catch FileNotFoundException if thrown
        }catch(FileNotFoundException ex) {
            //print the exception
            System.out.println(ex);
            System.exit(1);
        }
    }

}