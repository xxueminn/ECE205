#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pizza{
public:
    // define const values for type
    static const int deepDish = 1;
    static const int handTossed = 2;
    static const int pan = 3;

    // define const values for size
    static const int small = 1;
    static const int medium = 2;
    static const int large = 3;

    // mutators
    void setType(int type1){
        type = type1;
    }

    void setSize(int size1){
        size = size1;
    }

    void setPepperoni(int pepperoni1){
        pepperoni = pepperoni1;
    }

    void setCheese(int cheese1){
        cheese = cheese1;
    }

    // accessors
    int getType(){
        return type;
    }

    int getSize(){
        return size;
    }

    int getPepperoni(){
        return pepperoni;
    }

    int getCheese(){
        return cheese;
    }

    void getInput();
    double computePrice();
    void outputDescription();

private:
    int type;      
    int size;    
    int pepperoni; 
    int cheese;
};

// user input
void Pizza::getInput(){
    cout << "Enter pizza type (1=deep dish, 2=hand tossed, 3=pan): ";
    cin >> type;
    cout << "Enter pizza size (1=small, 2=medium, 3=large): ";
    cin >> size;
    cout << "Enter number of pepperoni toppings: ";
    cin >> pepperoni;
    cout << "Enter number of cheese toppings: ";
    cin >> cheese;
}

double Pizza::computePrice(){
    double cost;
    int totalToppings = pepperoni + cheese;

    if (size == small){
        cost = 10 + 2 * totalToppings;
    }
    else if (size == medium){
        cost = 14 + 2 * totalToppings;
    }
    else{
        cost = 17 + 2 * totalToppings;
    }

    return cost;
}

// for order output
void Pizza::outputDescription(){
    if (size == small){
        cout << "small ";
    }
    else if (size == medium){
        cout << "medium ";
    }
    else{
        cout << "large ";
    }

    if (type == deepDish){
        cout << "deep dish pizza, ";
    }
    else if (type == handTossed){
        cout << "hand tossed pizza, ";
    }
    else{
        cout << "pan pizza, ";
    }

    cout << pepperoni << " pepperoni toppings, and "
         << cheese << " cheese toppings";
}

class Order{
private:
    vector<Pizza> pizzas;

public:
    void addPizza(Pizza p){
        pizzas.push_back(p); // add pizza to the order
    }

    double getTotalPrice(){
        double total = 0.0;
        for (int i = 0; i < pizzas.size(); i++){
            total = total + pizzas[i].computePrice();
        }

        return total;
    }

    void outputOrder(){
        if (pizzas.empty()){
            cout << "No pizzas in the order." << endl;
            return;
        }

        for (int i = 0; i < pizzas.size(); i++){
            cout << "Pizza " << i + 1 << ": ";
            pizzas[i].outputDescription();
            cout << endl;
            cout << "Price: $" << pizzas[i].computePrice() << endl;
        }

        cout << endl;
        cout << "Total Order Price: $" << getTotalPrice() << endl;
    }
};

int main(){
    Order order1;
    Pizza p;
    int numPizzas;

    cout << "How many pizzas are in the order? ";
    cin >> numPizzas;

    for (int i = 0; i < numPizzas; i++){
        cout << endl;
        cout << "Pizza " << i + 1 << endl;
        p.getInput();
        order1.addPizza(p);
    }

    cout << endl;
    cout << "Order:" << endl;
    order1.outputOrder();

    return 0;
}