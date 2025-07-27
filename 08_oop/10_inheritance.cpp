#include <iostream>
#include <string>
#include <vector>
using namespace std;

// base class 
class Tea {
    protected:
        string teaName;
        int servings;
    public:
        Tea(string name, int servings) : teaName(name), servings(servings) {
            cout << "Tea constructor called for " << teaName << endl;
      }

        virtual void brew() const {
            cout << "Brewing " << teaName << " with generic method." << endl;
        }
        virtual void serve() const {
            cout << "serving " << servings << " cups of " << teaName << "." << endl;
        }
        // Virtual destructor for proper cleanup of derived classes
        virtual ~Tea() {
            cout << "Tea destructor called for " << teaName << endl;
        }
};

class GreenTea : public Tea {
    public:
        GreenTea(int serv) : Tea("Green Tea", serv) {
            cout << "GreenTea constructor called." << endl; cout << endl;
        }
        
        void brew() const override {
            cout << "Brewing " << teaName << " with green tea method." << endl;
        }
        ~GreenTea() {
            cout << "GreenTea destructor called." << endl;
        }
};

class MasalaTea : public Tea {
    public:
        MasalaTea (int serv) : Tea("Masala Tea", serv) {
            cout << "MasalaTea constructor called." << endl; cout << endl;
        }
        void brew() const override final { // final keyword prevents further overriding
            cout << "Brewing " << teaName << " with Masala tea method." << endl;
        }
        ~MasalaTea() {
            cout << "MasalaTea destructor called." << endl;
        }
};

// class SpicyMasalaTea : public MasalaTea {
//     public:
//         void brew() const override {
//             cout << "Brewing " << teaName << " with spicy masala tea method." << endl;
//         }
// };
/*uncomment to see the function of final key*/

int main () {

    Tea* tea1 = new GreenTea(2);
    Tea* tea2 = new MasalaTea(3);

    tea1->brew(); 
    tea1->serve(); cout << endl;

    tea2->brew();
    tea2->serve(); cout << endl;

    delete tea1; cout << endl;
    delete tea2; cout << endl;
    
    return 0;
}