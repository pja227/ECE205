/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Pizza {
    private:
        int type;       // 1 = deep dish, 2 = hand tossed, 3 = pan
        int size;       // 1 = small, 2 = medium, 3 = large
        int toppings;   // number of toppings

    public:
        // Constants for type
        static const int DEEP_DISH = 1;
        static const int HAND_TOSSED = 2;
        static const int PAN = 3;

        // Constants for size
        static const int SMALL = 1;
        static const int MEDIUM = 2;
        static const int LARGE = 3;

        // Default constructor
        Pizza() {
            type = HAND_TOSSED;
            size = SMALL;
            toppings = 0;
        }

        Pizza(int t, int s, int top) {
            type = t; 
            size = s; 
            toppings = top;
        }
    
        void setType(int t) { type = t; };
        int getType() { return type; };

        void setSize(int s) { size = s; };
        int getSize() { return size; };

        void setToppings(int t) { toppings = t; };
        int getToppings() { return toppings; };

        void outputDescription() const;
        double computePrice() const;
};

void Pizza::outputDescription() const {
    string typeStr, sizeStr;

    switch (type) {
        case DEEP_DISH: 
            typeStr = "deep dish"; 
            break;
        case HAND_TOSSED: 
            typeStr = "hand tossed"; 
            break;
        case PAN: 
            typeStr = "pan"; 
            break;
        default: 
            typeStr = "unknown type"; 
            break;
    }
    
    switch (size) {
        case SMALL: 
            sizeStr = "small"; 
            break;
        case MEDIUM: 
            sizeStr = "medium"; 
            break;
        case LARGE: 
            sizeStr = "large"; 
            break;
        default: 
            sizeStr = "unknown size"; 
            break;
    }
    
    if (toppings > 0) {
        cout << "You have a " << sizeStr << " " << typeStr << " pizza with " << toppings << " pepperoni or cheese topping(s)." << endl;
    } else {
        cout << "You have a " << sizeStr << " " << typeStr << " pizza with no toppings." << endl;
    }
}

double Pizza::computePrice() const {
    double price = 0;
    
    if (size == 1) {
        price = 10.00 + (toppings * 2);
    } else if (size == 2) {
        price = 14.00 + (toppings * 2);
    } else if (size == 3) {
        price = 17.00 + (toppings * 2);
    }

    return price;
}

int main() {
    Pizza pizza(1, 1, 1); // Deep dish, small, 1 topping

    pizza.outputDescription();
    cout << "Price: $" << fixed << setprecision(2) << pizza.computePrice() << endl;

    pizza.setType(2); // Hand tossed
    pizza.setSize(2); // Medium
    pizza.setToppings(2); // 2 toppings

    pizza.outputDescription();
    cout << "Price: $" << fixed << setprecision(2) << pizza.computePrice() << endl;

    pizza.setType(3); // Pan
    pizza.setSize(3); // Large
    pizza.setToppings(0); // 0 toppings

    pizza.outputDescription();
    cout << "Price: $" << fixed << setprecision(2) << pizza.computePrice() << endl;

    return 0;
}