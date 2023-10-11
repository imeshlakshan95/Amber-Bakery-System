#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Class to represent bakery items
class BakeryItem {
public:
    BakeryItem(const string& name, double price, int stock)
        : name(name), price(price), stock(stock), orderedQuantity(0) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getStock() const {
        return stock;
    }

    int getOrderedQuantity() const {
        return orderedQuantity;
    }

    void updatePrice(double newPrice) {
        price = newPrice;
    }

    void updateStock(int newStock) {
        stock = newStock;
    }

    void addToOrderedQuantity(int quantity) {
        orderedQuantity += quantity;
    }

private:
    string name;
    double price;
    int stock;
    int orderedQuantity;
};

// Function to display the list of bakery items
void viewItems(const vector<BakeryItem>& items) {
    cout << "-----------------------------------------------------" << endl;
    cout << "            *** Available Bakery Items ***           " << endl;
    cout << "-----------------------------------------------------" << endl;
    for (const BakeryItem& item : items) {
        cout << item.getName() << " - GBP" << fixed << setprecision(2) << item.getPrice()
             << " (Stock: " << item.getStock() << ")\n";
    }
    cout << "" << endl;
    cout << "=====================================================" << endl;
    cout << "" << endl;
}

// Function to add a new bakery item
void addItem(vector<BakeryItem>& items) {
    string itemName;
    double itemPrice;
    int itemStock;

    cout << "-----------------------------------------------------" << endl;
    cout << "               *** Add Bakery Items ***              " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Enter the name of the bakery item: ";
    cin.ignore();
    getline(cin, itemName);

    cout << "Enter the price of the item: ";
    cin >> itemPrice;

    cout << "Enter the initial stock of the item: ";
    cin >> itemStock;

    items.push_back(BakeryItem(itemName, itemPrice, itemStock));
    cout << "" << endl;
    cout << "***         Bakery item added successfully!       ***\n";
    cout << "" << endl;
    cout << "=====================================================" << endl;
    cout << "" << endl;
}

// Function to update the price of a bakery item
void updatePrice(vector<BakeryItem>& items) {
    string itemName;
    double newPrice;

    cout << "-----------------------------------------------------" << endl;
    cout << "          *** Update Bakery Item Price ***           " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Enter the name of bakery item to update: ";
    cin.ignore();
    getline(cin, itemName);

    cout << "Enter the new price: ";
    cin >> newPrice;

    for (BakeryItem& item : items) {
        if (item.getName() == itemName) {
            item.updatePrice(newPrice);
            cout << "" << endl;
            cout << " ***          Price updated successfully!         ***\n";
            cout << "" << endl;
            cout << "=====================================================" << endl;
            cout << "" << endl;
            return;
        }
    }
    cout << "" << endl;
    cout << "***                Item not found!                ***\n";
    cout << "" << endl;
    cout << "=====================================================" << endl;
    cout << "" << endl;
}

// Function to update the stock of a bakery item
void updateStock(vector<BakeryItem>& items) {
    string itemName;
    int newStock;

    cout << "-----------------------------------------------------" << endl;
    cout << "         *** Update Bakery Item Quantity ***         " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Enter the name of the bakery item to update: ";
    cin.ignore();
    getline(cin, itemName);

    cout << "Enter the new quantity: ";
    cin >> newStock;

    for (BakeryItem& item : items) {
        if (item.getName() == itemName) {
            item.updateStock(newStock);
            cout << "" << endl;
            cout << "***         Quantity updated successfully!        ***\n";
            cout << "" << endl;
            cout << "=====================================================" << endl;
            cout << "" << endl;
            return;
        }
    }

    cout << "" << endl;
    cout << "***                Item not found!                ***\n";
    cout << "" << endl;
    cout << "=====================================================" << endl;
    cout << "" << endl;
}

// Function to search for a bakery item
void searchItem(const vector<BakeryItem>& items) {
    string itemName;

    cout << "-----------------------------------------------------" << endl;
    cout << "              *** Search Bakery Item ***             " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Enter the name of the bakery item to search: ";
    cout << "" << endl;
    cin.ignore();
    getline(cin, itemName);

    for (const BakeryItem& item : items) {
        if (item.getName() == itemName) {
            cout << "Item found: " << item.getName() << " - GBP" << fixed << setprecision(2)
                 << item.getPrice() << " (Stock: " << item.getStock() << ")\n";
            cout << "" << endl;
            cout << "=====================================================" << endl;
            cout << "" << endl;
            return;
        }
    }

    cout << "" << endl;
    cout << "***                Item not found!                ***\n";
    cout << "" << endl;
    cout << "=====================================================" << endl;
    cout << "" << endl;
}

// Function to place an order for bakery items
void placeOrder(vector<BakeryItem>& items) {
    string itemName;
    int quantity;

    cout << "-----------------------------------------------------" << endl;
    cout << "               *** Order Bakery Item ***             " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Enter the name of the bakery item to order: ";
    cin.ignore();
    getline(cin, itemName);

    cout << "Enter the quantity: ";
    cin >> quantity;

    for (BakeryItem& item : items) {
        if (item.getName() == itemName) {
            if (item.getStock() >= quantity) {
                cout << "" << endl;
                cout << "Order placed: " << itemName << " x" << quantity << "\n";
                cout << "" << endl;
                cout << "***             Successfully Ordered!             ***\n";
                cout << "" << endl;
                cout << "=====================================================" << endl;
                cout << "" << endl;
                item.addToOrderedQuantity(quantity);
                item.updateStock(item.getStock() - quantity);
            } else {
                cout << "" << endl;
                cout << "Insufficient stock for " << itemName << ".\n";
                cout << "" << endl;
                cout << "***             Order Unsuccessfuled!             ***\n";
                cout << "" << endl;
                cout << "=====================================================" << endl;
                cout << "" << endl;
            }
            return;
        }
    }

    cout << "" << endl;
    cout << "***                Item not found!                ***\n";
    cout << "" << endl;
    cout << "=====================================================" << endl;
    cout << "" << endl;
}

// Function to generate a bill for bakery items
void generateBill(const vector<BakeryItem>& items) {
    double total = 0.0;

    cout << "-----------------------------------------------------" << endl;
    cout << "               *** Amber Bakery Bill ***             " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Bill Details:\n";
    for (const BakeryItem& item : items) {
        double itemTotal = item.getPrice() * item.getOrderedQuantity();
        if (itemTotal > 0) {
            cout << item.getName() << " x" << item.getOrderedQuantity() << " - GBP"
                 << fixed << setprecision(2) << itemTotal << "\n";
            cout << "" << endl;
            total += itemTotal;
        }
    }
    cout << "Total: GBP" << fixed << setprecision(2) << total << "\n";
    cout << "" << endl;
    cout << "***            Thank You & Come again             ***\n";
    cout << "" << endl;
    cout << "=====================================================" << endl;
    cout << "" << endl;
}

int main() {
    vector<BakeryItem> bakeryItems;

    int selection1; // Login menu selection variable
    string username = "Amber";
    string password = "Ambuk123";
    string user;
    string pass;
    int loginAttempt = 0;
    int selection2; // Main menu selection variable
    bool loggedIn = false;  // Flag to check if the user is logged in

    while (true) {  // Main program loop
        if (!loggedIn) {
            cout << "-----------------------------------------------------" << endl;
            cout << "      *** Welcome to the Amber Bakery System ***     " << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "" << endl;
            cout << "01. Login" << endl;
            cout << "02. Exit" << endl;
            cout << "" << endl;
            cout << "***          Please enter your selection          ***" << endl;
            cout << "" << endl;
            cout << "=====================================================" << endl;
            cout << "" << endl;

            cin >> selection1;

            if (selection1 == 2) {
                cout << "" << endl;
                cout << "" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "***            Thank You & See You Again          ***" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "" << endl;
                cout << "" << endl;
                break;  // Exit the program
            } else if (selection1 == 1) {
                while (loginAttempt < 5) {
                    cout << "-----------------------------------------------------" << endl;
                    cout << "                     *** Login ***                   " << endl;
                    cout << "-----------------------------------------------------" << endl;
                    cout << "" << endl;
                    cout << "Please enter user name and password" << endl;
                    cout << "" << endl;
                    cout << "User Name :";
                    cin >> user;
                    cout << "Password  :";
                    cin >> pass;
                    cout << "" << endl;
                    cout << "=====================================================" << endl;
                    cout << "" << endl;

                    if (user == username && pass == password) {
                        loggedIn = true;
                        loginAttempt = 0; // Reset login attempts on successful login
                        break;  // Continue to main menu
                    } else {
                        cout << "" << endl;
                        cout << "" << endl;
                        cout << "-----------------------------------------------------" << endl;
                        cout << "***        Invalid login. Please try again!       ***" << endl;
                        cout << "-----------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "" << endl;
                        loginAttempt++;
                    }
                    if (loginAttempt == 5) {
                        cout << "" << endl;
                        cout << "" << endl;
                        cout << "-----------------------------------------------------" << endl;
                        cout << "***  Too many attempts! The program will now End. ***" << endl;
                        cout << "-----------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "" << endl;
                        return 0;
                    }
                }
            }
        }

        // Submenu loop after successful login
        while (loggedIn) {
            cout << "-----------------------------------------------------" << endl;
            cout << "                   *** Main Menu ***                 " << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "" << endl;
            cout << "01. Add Items" << endl;
            cout << "02. View Available Bakery Items " << endl;
            cout << "03. Update Quantity " << endl;
            cout << "04. Update Prices " << endl;
            cout << "05. Search Item" << endl;
            cout << "06. Place an Order" << endl;
            cout << "07. Generate a Bill" << endl;
            cout << "08. View Company Details " << endl;
            cout << "09. Logout " << endl;
            cout << "" << endl;
            cout << "***          Please enter your selection          ***" << endl;
            cout << "" << endl;
            cout << "=====================================================" << endl;
            cout << "" << endl;
            cin >> selection2;

            switch (selection2) {
            case 1:
                addItem(bakeryItems);
                break;
            case 2:
                viewItems(bakeryItems);
                break;
            case 3:
                updateStock(bakeryItems);
                break;
            case 4:
                updatePrice(bakeryItems);
                break;
            case 5:
                searchItem(bakeryItems);
                break;
            case 6:
                placeOrder(bakeryItems);
                break;
            case 7:
                generateBill(bakeryItems);
                break;
            case 8:
                cout << "-----------------------------------------------------" << endl;
                cout << "                 *** Company Details ***                " << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "" << endl;
                cout << "Company Name    :   Amber Bakery " << endl;
                cout << "Company Address :   No.100 Ring Road Bedford " << endl;
                cout << "Telephone No    :   (+44) 111 - 257896 " << endl;
                cout << "Email           :   info@amberbakery.com " << endl;
                cout << "Website         :   www.amberbakery.com" << endl;
                cout << "" << endl;
                cout << "=====================================================" << endl;
                cout << "" << endl;
                break;
            case 9:
                loggedIn = false;  // Logout and return to home screen
                break;
            default:
                cout << "" << endl;
                cout << "" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "***       Invalid choice. Please try again!       ***\n";
                cout << "-----------------------------------------------------" << endl;
                cout << "" << endl;
                cout << "" << endl;
                break;
            }
        }
    }

    return 0;
}
