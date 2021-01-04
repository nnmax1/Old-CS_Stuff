
//solution to Shopping List CodeSignal Challenge posted on 9/12/2020

#include <iostream>
#include <sstream>//access std::stringstream


class ShoppingList {
    public: 
    //init shopping list object w/ a shopping list as a string
    ShoppingList(std::string i) {
        items =i;
    }
    double getTotalPrice() {
        std::stringstream s(items);
        std::string word;
        double totalPrice =0;
        double itemPrice=0;
        int quantity=0;
    
        while(s>>word)
        {
            std::string temp;
            //remove dollar sign from string if it contains one
            temp = removeSpecialChars(word);
            //find the item price in string
            if(isNumber(temp)) {
                itemPrice = std::stod(temp);
                totalPrice += itemPrice;
            }
        }
        return totalPrice;
    }
    private:
    std::string items;
    //remove special Chars '$', ';' , and ',' from string
    std::string removeSpecialChars(std::string w) {
        std::string str;
        for(int i=0;i<w.length();i++) {
            if(w.at(i) != '$' && w.at(i) != ';' && w.at(i)!=',') {
                str+=w.at(i);
            }
        }
        return str;
    }
    //check if string is number
    bool isNumber(const std::string& str) {
        long double num;
        return((std::istringstream(str) >> num >> std::ws).eof());
    }
};



//test ShoppingList Class in Main
int main() {
    std::string tests[3] = {"Doughnuts, 4; doughnuts holes, 0.08; glue, 3.4$", 
                            "blue suit for 24$, cape for 12.99$ & glasses for 15.70",
                            "Cocacola for 3.00$, each other beverage for 1.5"};
    for(int i=0;i<3;i++){
        ShoppingList item(tests[i]);
        std::cout<<i+1<<".) Total: $"<<item.getTotalPrice()<<"\n";
    }
/*console output should look like
    1.) Total: $7.48
    2.) Total: $52.69
    3.) Total: $4.5
*/
    return 0;
}