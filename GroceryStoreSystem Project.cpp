#include <iostream>
#include <string>
#include <iomanip> // For std::setw

using namespace std;

// Structure to represent a Product in a linked list
struct Product {
    string name;
    double price;
    int stock;
    Product* next; // Pointer to the next product in the list
};

// Class to manage the store's product inventory using a linked list
class LinkedListInventory {
private:
    Product* head; 

public:
    LinkedListInventory() : head(NULL) {}

    // Add a new product to the inventory
    void addProduct(string name, double price, int stock) {
        Product* newProduct = new Product{name, price, stock,NULL};

        if (!head) {
            head = newProduct;
        } else {
            Product* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newProduct;
        }
    }

    // Remove a product from the inventory
    void removeProduct(string name) {
        if (!head) {
            cout << "Product not found!" << endl;
            return;
        }

        if (head->name == name) {
            Product* temp = head;
            head = head->next;
            delete temp;
            cout << "Product removed successfully!" << endl;
            return;
        }

        Product* current = head;
        Product* previous = NULL;
        while (current && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next;
            delete current;
            cout << "Product removed successfully!" << endl;
        } else {
            cout << "Product not found!" << endl;
        }
    }

    // Display all products in the inventory
    void displayProducts() {
        cout << left << setw(20) << "Product Name" << setw(10) << "Price" << setw(20) << "Stock" << endl;
        cout << string(40, '-') << endl; // Separator line
        Product* temp = head;
        while (temp) {
                 cout << left << setw(20) << temp->name 
     << setw(1) << fixed << setprecision(1) << "$" << temp->price 
     << setw(5) << " "<<temp->stock << endl;
            temp = temp->next;
        }
        cout << string(40, '-') << endl; // Separator line
    }

    // Find a product by name
    bool findProduct(string name, Product*& product) {
        Product* temp = head;
        while (temp) {
            if (temp->name == name) {
                product = temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Reduce the stock of a product
    void reduceStock(string name, int quantity) {
        Product* temp = head;
        while (temp) {
            if (temp->name == name) {
                temp->stock -= quantity; // Reduce stock
                return;
            }
            temp = temp->next;
        }
    }

   void searchProduct(string name) {
    Product* temp = head;
    bool found = false;
    cout << left << setw(20) << "Product Name" << setw(10) << "Price" << setw(10) << "Stock" << endl;
    cout << string(40, '-') << endl; // Separator line
    while (temp) {
        if (temp->name == name) {
            found = true;
            cout << left << setw(20) << temp->name
                 << "$" << fixed << setprecision(2) << temp->price
                 << setw(10) << temp->stock << endl;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Product not found!" << endl;
    }
}

};

// Stack class to manage low stock alerts
class Stack {
private:
    struct Node {
        string productName;
        Node* next;
    };

    Node* top;

public:
    Stack() : top(NULL) {}

    // Push a product name onto the stack
    void push(string productName) {
        Node* newNode = new Node{productName, top};
        top = newNode;
    }

    // Pop a product name from the stack
    string pop() {
        if (!top) return "";

        Node* temp = top;
        string productName = top->productName;
        top = top->next;
        delete temp;
        return productName;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

// Queue node to represent a customer in the queue
struct Customer {
    string name;
    string email;
    double totalSpent;
    Customer* next; // Pointer to the next customer in the queue
};

// Class to manage the customer queue
class CustomerQueue {
private:
    Customer* front;
    Customer* rear;

public:
    CustomerQueue() : front(NULL), rear(NULL) {}
    
    Customer* getFront() const {
        return front;
    }
    
    // Enqueue a new customer to the queue
    void enqueueCustomer(string name, string email, double totalSpent) {
        Customer* newCustomer = new Customer{name, email, totalSpent, NULL};

        if (!rear) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
    }

    // Dequeue the customer at the front of the queue
    Customer* dequeueCustomer() {
        if (!front) {
            return NULL;
        }

        Customer* temp = front;
        front = front->next;

        if (!front) {
            rear = NULL;
        }

        return temp;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

// Class to manage a customer's shopping cart
class Cart {
private:
    Product* products[100]; // Array of product pointers
    int quantities[100];
    int itemCount;

public:
    Cart() : itemCount(0) {}

    // Add a product to the cart
    void addProduct(Product* product, int quantity) {
        products[itemCount] = product;
        quantities[itemCount] = quantity;
        itemCount++;
    }

    // Display the cart contents
    void displayCart() {
        cout << left << setw(20) << "Product Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
        cout << string(40, '-') << endl; // Separator line
        for (int i = 0; i < itemCount; i++) {
            cout << left << setw(20) << products[i]->name
                 << setw(10) << quantities[i]
                 << "$" << fixed << setprecision(2) << products[i]->price << endl;
        }
        cout << string(40, '-') << endl; // Separator line
    }

    // Calculate the total cost of the cart
    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += products[i]->price * quantities[i];
        }
        return total;
    }

    int getItemCount() {
        return itemCount;
    }
};

// Struct for a processed customer node in the linked list
struct ProcessedCustomer {
    string name;
    double totalSpent;
    
};

class UserInterface {
private:
    LinkedListInventory inventory; // Inventory managed by a linked list
    CustomerQueue customerQueue; // Queue for customer management
    Stack lowStockAlerts; // Stack for low stock alerts
    double totalSales;
    int totalCustomers;

public:
    string adminUsername = "admin"; // Default admin username
    string adminPassword = "admin"; // Default admin password

    UserInterface() 
    {
        totalSales=0;
        totalCustomers=0;
    }

    void adminMenu() {
        string username, password;
        while (true) {
            cout << "Enter Admin Username: ";
            getline(cin, username);
            cout << "Enter Admin Password: ";
            getline(cin, password);

            if (username == adminUsername && password == adminPassword) {
                break; // Break if credentials are correct
            } else {
                cout << "Invalid credentials. Please enter valid username and password." << endl;
            }
        }

        int choice;
        do {
            cout << "\nAdmin Actions:\n";
            cout << "1. Change Admin Credentials\n";
            cout << "2. Manage Inventory & Shopping\n";
            cout << "3. Generate Daily Report\n";
            cout << "4. View Low Stock Alerts\n";
            cout << "5. Exit Admin Menu\n";
            cout << "Choose an option: ";
            cin >> choice;
            cin.ignore(); // Clear the newline
            cout<<endl;
            switch (choice) {
            case 1:
                changeAdminCredentials();
                break;
            case 2:
                manageInventoryShopping();
                break;
            case 3:
                generateDailyReport();
                break;
            case 4:
                viewLowStockAlerts();
                break;
            case 5:
                cout << "Exiting Admin Menu." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 5);
    }

    void changeAdminCredentials() {
        cout << "Enter new username: ";
        getline(cin, adminUsername);
        cout << "Enter new password: ";
        getline(cin, adminPassword);
        cout << "Admin credentials changed successfully." << endl;
    }

    void manageInventoryShopping() {
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Add New Product to Inventory\n";
            cout << "2. Remove Product from Inventory\n";
            cout << "3. Customer Shopping\n";
            cout << "4. View All Products\n";
            cout << "5. View Total Sales\n";
            cout << "6. Search for a Product\n";
            cout << "7. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;
            cin.ignore(); // Clear the newline
            cout<<endl;
            switch (choice) {
            case 1:
                addNewProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                handleCustomerShopping();
                break;
            case 4:
                inventory.displayProducts();
                break;
            case 5:
                cout << "Total Sales: $" << totalSales << endl;
                break;
            case 6: 
               {  
                  string productName;
                  cout << "Enter Product Name to Search: ";
                  getline(cin, productName);
                  inventory.searchProduct(productName);
                  break;
               }
            case 7:
                cout << "Exiting Inventory Management." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 7);
    }

    void addNewProduct() {
        string name;
        double price;
        int stock;

        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Product Price: ";
        cin >> price;
        cout << "Enter Product Stock: ";
        cin >> stock;
        cin.ignore(); // Clear the newline
        cout<<endl;
        inventory.addProduct(name, price, stock);

        // Check for low stock alert
        if (stock < 5) {
            lowStockAlerts.push(name);
        }
        cout << "Product added successfully!" << endl;
    }

    void removeProduct() {
        string name;
        cout << "Enter Product Name to Remove: ";
        getline(cin, name);
        inventory.removeProduct(name);
    }

    void handleCustomerShopping() {
    totalCustomers++;
    string name, email;
    cout << "Enter Customer Name: ";
    getline(cin, name);
    cout << "Enter Customer Email: ";
    getline(cin, email);

    // Enqueue the new customer with an initial totalSpent of 0
    customerQueue.enqueueCustomer(name, email, 0.0);

    Cart cart; // Create a new cart for the customer
    int choice;
    do {
        cout << "\nCustomer Shopping Menu:\n";
        cout << "1. Add Product to Cart\n";
        cout << "2. View Cart\n";
        cout << "3. Checkout\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Clear the newline
        cout<<endl;
        switch (choice) {
        case 1: {
            string productName;
            int quantity;

            cout << "Enter Product Name to Add: ";
            getline(cin, productName);
            cout << "Enter Quantity: ";
            cin >> quantity;
            cin.ignore(); // Clear the newline

            Product* product;
            if (inventory.findProduct(productName, product)) {
                if (product->stock >= quantity) {
                    cart.addProduct(product, quantity);
                    inventory.reduceStock(productName, quantity);
                    cout << "Product added to cart." << endl;

                    // Check for low stock alert
                    if (product->stock < 5) {
                        lowStockAlerts.push(product->name);
                    }
                } else {
                    cout << "Insufficient stock!" << endl;
                }
            } else {
                cout << "Product not found!" << endl;
            }
            break;
        }
        case 2:
            cart.displayCart();
            break;
        case 3: {
            double total = cart.calculateTotal();
            totalSales += total;

            // Update the totalSpent for the customer currently at the front of the queue
            Customer* currentCustomer = customerQueue.getFront();
            if (currentCustomer) {
                currentCustomer->totalSpent = total; 
            }

            cout << "Total amount to pay: $" << total << endl;
            cout << "Thank you for shopping!" << endl;

            customerQueue.dequeueCustomer(); // Process the customer after checkout
            break;
        }
        case 4:
            cout << "Exiting Customer Shopping Menu." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 4);
}
    
   void generateDailyReport() {
    cout << "\nDaily Report:\n";
    cout << "Total Customers: " << totalCustomers << endl;
    cout << "Total Sales: $" << totalSales << endl;
}

    void viewLowStockAlerts() 
{
    if (lowStockAlerts.isEmpty()) {
        cout << "No stock is low!" << endl; // Message when no products are low
    } else {
        while (!lowStockAlerts.isEmpty()) 
        {
            string productName = lowStockAlerts.pop();
            cout << productName << " is low on stock!" << endl;
        }
    }
}
};

int main() {
    UserInterface ui;
    ui.adminMenu();
    return 0;
}
