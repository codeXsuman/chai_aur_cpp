#include <iostream> // used for input and output operations
#include <vector>        // used for storing employee data
#include <deque> // used for storing employee data in a deque
#include <list>          // used for storing employee data in a list
#include <algorithm>     // used for sorting and searching
#include <set> // used for storing unique product IDs in a set
#include <map>           // used for storing employee data in a map
#include <string>        // used for string manipulation
#include <ctime>         // used for date and time manipulation
#include <unordered_map> // used for storing employee data in an unordered map
#include <unordered_set> // used for storing unique employee IDs in an unordered set

using namespace std;
// struct is a type of container

struct product {  // structure to hold product information
    int product_id;
    string name;
    string catagory;
};

struct order {  // structure to hold order information
    int orderID;
    int productID;
    int quantity;
    string customerID;
    string orderDate;
};

int main() {

    vector<product> products = {
        {101, "Laptop", "Electronics"}, // product 1
        {102, "Smartphone", "Electronics"}, // product 2
        {103, "Tablet", "Electronics"}, // product 3
        {104, "Headphones", "Accessories"}, // product 4
        {105, "Smartwatch", "Accessories"} // product 5
    };
    
    // Deque = double-ended queue, allows insertion and deletion from both ends
    deque<string> recentCustoumers = {"C001", "C002", "C003"};//deque to hold recent customer IDs
    
    recentCustoumers.push_back("C004"); //adding a new customerID to the end of the deque
    recentCustoumers.push_front("C005"); //adding a new customerID to the

    list<order> orderHistory;
    orderHistory.push_back({1, 101, 2, "C001", "2025-10-01"}); // order 1
    orderHistory.push_back({2, 102, 1, "C002", "2025-10-02"}); // order 2
    orderHistory.push_back({3, 103, 5, "C003", "2025-10-03"}); // order 3

    set<string> Categories;

    for (const auto &product : products) {
        Categories.insert(product.catagory); // inserting unique categories into the set
    }

    // Example of using a map to store employee data
    map<int, int> productStock = { // map to hold product stock information
        {101, 50}, // product ID 101 has 50 units in stock
        {102, 30}, // product ID 102 has 30 units in stock
        {103, 20}, // product ID 103 has 20 units in stock
        {104, 15}, // product ID 104 has 15 units in stock
        {105, 10}  // product ID 105 has 10 units in stock
    };

    multimap<string, order> customerOrders; // multimap to hold orders by customer ID
    for (const auto &order : orderHistory) {
        customerOrders.insert({order.customerID, order}); // inserting orders into the multimap
    }

    unordered_map<string, string> customerData = { // unordered map to hold customer data
        {"C001", "Alice"}, // customer ID C001 is Alice
        {"C002", "Bob"},   // customer ID C002 is Bob
        {"C003", "Charlie"} // customer ID C003 is Charlie
        
    };

    unordered_set<int> uniqueProductIDs; // unordered set to hold unique product IDs
    for (const auto &product : products) {
        uniqueProductIDs.insert(product.product_id); //inserting unique productIDs into the unorderedset
    }



//          ============printing the data============


    // Print all products
    cout << "Products:\n";
    for (const auto& product : products) {
        cout << "ID: " << product.product_id
             << ", Name: " << product.name
             << ", Category: " << product.catagory << endl;
    }

    // Print recent customers
    cout << "\nRecent Customers:\n";
    for (const auto& cust : recentCustoumers) {
        cout << cust << endl;
    }

    // Print order history
    cout << "\nOrder History:\n";
    for (const auto& ord : orderHistory) {
        cout << "OrderID: " << ord.orderID
             << ", ProductID: " << ord.productID
             << ", Quantity: " << ord.quantity
             << ", CustomerID: " << ord.customerID
             << ", Date: " << ord.orderDate << endl;
    }

    // Print unique categories
    cout << "\nCategories:\n";
    for (const auto& cat : Categories) {
        cout << cat << endl;
    }

    // Print product stock
    cout << "\nProduct Stock:\n";
    for (const auto& pair : productStock) {
        cout << "ProductID: " << pair.first << ", Stock: " << pair.second << endl;
    }

    // Print customer orders
    cout << "\nCustomer Orders:\n";
    for (const auto& entry : customerOrders) {
        cout << "CustomerID: " << entry.first
             << ", OrderID: " << entry.second.orderID << endl;
    }

    // Print customer data
    cout << "\nCustomer Data:\n";
    for (const auto& entry : customerData) {
        cout << "CustomerID: " << entry.first
             << ", Name: " << entry.second << endl;
    }

    // Print unique product IDs
    cout << "\nUnique Product IDs:\n";
    for (const auto& id : uniqueProductIDs) {
        cout << id << endl;
    }

return 0;
}
