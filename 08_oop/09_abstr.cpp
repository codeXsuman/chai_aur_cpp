#include <iostream>
#include <string>
using namespace std;
// virtual functions is a function that can be overridden in derived classes.
// abstract class is a class that contains at least one pure virtual function.

class Tea {
    public:
        virtual void prepareIngredients() = 0; // Pure virtual function
        virtual void brew() = 0; // Pure virtual function
        virtual void serve() = 0; // Pure virtual function

        // method to make tea
        void makeTea() {
            prepareIngredients();
            brew();
            serve();
        }
};

//derived class
class GreenTea : public Tea {
public:
    void prepareIngredients() override { // Prepare ingredients for green tea
        cout << "Preparing green tea leaves and water." << endl;
    }
    void brew() override { // Brew the green tea
        cout << "Brewing green tea for 3 minutes." << endl;
    }
    void serve() override { // Serve the green tea
        cout << "Serving green tea in a cup." << endl;
    }
};

// derived class
class MasalaTea : public Tea {
public:
    void prepareIngredients() override { // Prepare ingredients for masala tea
        cout << "Preparing black tea, spices, and milk." << endl;
    }
    void brew() override { // Brew the masala tea
        cout << "Brewing masala tea for 5 minutes." << endl;
    }
    void serve() override { // Serve the masala tea
        cout << "Serving masala tea in a cup." << endl;
    }
};

int main() {

    GreenTea greenTea;
    MasalaTea masalaTea;

    greenTea.makeTea(); // Making green tea
    cout << endl; // Adding a line break for clarity
    masalaTea.makeTea(); // Making masala tea
    cout << endl;

    return 0; // No main logic needed for this abstract class example
}