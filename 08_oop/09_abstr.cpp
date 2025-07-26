#include <iostream>
#include <string>
using namespace std;

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
// virtual functions is a function that can be overridden in derived classes.
// abstract class is a class that contains at least one pure virtual function.

//derived class
class GreenTea : public Tea {
public:
    void prepareIngredients() override { // Prepare ingredients for green tea
        cout << "Preparing green tea leaves and water." << endl;
    }
        