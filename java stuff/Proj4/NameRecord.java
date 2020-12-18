
//Project 4: NameRecord.java


public class NameRecord {
    //const instance vars
    private final int START=1900 ;
    private final int DECADES=11 ;
    //store ranks for each year in ranks
    private int []  ranks;
    //store name in name
    private String name;
    //default constructor
    public NameRecord() {
        name = "NO NAME";
        ranks = new int[DECADES];
    }
    //overloaded constructor
    public NameRecord(String line) {
        ranks = new int[DECADES];
        String delims = "[ ]";
        String[] tokens = line.split(delims);
        name = tokens[0];
        int i=0;
        for(String tok : tokens){
           if(tok != name) {
               ranks[i++] = Integer.parseInt(tok);
           }
        }
    }
    //return the current name 
    public String get_name() {
        return name;
    }
    //return the rank
    //returns -1, if decade is not in range
    public int getRank(int decade) {
        int decade_index = (decade - 1900)/10;
        if(decade_index >= 0 && decade_index <DECADES) {
            return ranks[decade_index];
        }
        return -1;
    }
    //linear search to find the best year
    //(lower the rank, the better)
    public int bestYear() { 
        int lowest_val=Integer.MAX_VALUE, lowest_index=0;
        for(int i=0;i<DECADES;i++) {
            if(ranks[i] > 0 && ranks[i] < lowest_val ) {
                lowest_val  = ranks[i];
                lowest_index = i;
            }
        }
        return 10 * lowest_index + 1900;
    }
  
}