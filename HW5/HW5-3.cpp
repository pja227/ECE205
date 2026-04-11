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

        // Parameterized constructor
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

class Order {
    private:
        vector <Pizza> Pizzas;

    public:
        void add_pizza(const Pizza& p) {
            Pizzas.push_back(p);
        }
        
        void add_pizza(int type, int size, int toppings) {
            Pizza p(type, size, toppings);
            Pizzas.push_back(p);
        }

        void outputOrder() const {
            double totalPrice = 0.0;

            if (Pizzas.empty()) {
                cout << "No pizzas in the order." << endl;  
            }

            for (size_t i = 0; i < Pizzas.size(); i++) {
                cout << "Pizza #" << i + 1 << ": ";
                Pizzas[i].outputDescription();
                cout << "Price: $" << Pizzas[i].computePrice() << endl << endl;
                totalPrice += Pizzas[i].computePrice();
            }

            cout << "Total Order Price: $" << totalPrice << endl;
            cout << "--------------------------\n" << endl;
        }
};

int main() {
    // Create pizza objects
    Pizza pizza1(1, 1, 1);
    Pizza pizza2(2, 2, 2);
    
    // Output details for pizza1
    cout << "---- Pizza 1 ----\n";
    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl;

    cout << endl;

    // Output details for pizza2
    cout << "---- Pizza 2 ----\n";
    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl;

    cout << endl;

    Order order1;
    order1.add_pizza(pizza1);
    order1.add_pizza(pizza2);

    Order order2;
    order2.add_pizza(pizza1);
    order2.add_pizza(pizza2);
    order2.add_pizza(pizza1);

    cout << "---- Order 1 ----\n";
    order1.outputOrder();

    cout << "---- Order 2 ----\n";
    order2.outputOrder();

    return 0;
}