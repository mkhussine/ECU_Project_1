#include <iostream>
#include <string>
using namespace std;

const int menu_size = 100;  // maximum number of menu items
const int order_size = 100; // Maximum number of order items



// /--------------------------------------       mohamed hussien part  --------------------------------------------------------/

class MenuItem {  // Class for a single menu item.

public:
    int id;
    string name;
    string description;
    double price;
    string category;
    int stock;

    MenuItem(int i = 0, string n = "", string d = "", double p = 0.0, string c = "", int s = 0) //Constructor to initialize the menu items
    {
        id = i;
        name = n;
        description = d;
        price = p;
        category = c;
        stock = s;
    }

    void display() const //function that  Display the menu item details
    {
        cout << "id   " << id << endl
            << name << "  " << endl
            << description<< "  \n $" << price 
            << "\n  " << category << "\n  Stock = " 
            << stock << endl;
    }
};

class MenuManager {//Class for managing the menu items
private:
    MenuItem menuItems[menu_size]; //  Array of objects of menu items
    int itemCount;

public:

    MenuManager()  //Constructor to initialize the menu manager
    {
        itemCount = 0;
    }

    // function that add menu items
     void addMenuItem( string& name,  string& description, double& price, string& category, int& stock) {
        if (itemCount >= menu_size) {
            cout << "Menu is full." << endl;
            return;
        }
        menuItems[itemCount] = MenuItem(itemCount + 1, name, description, price, category, stock);
        itemCount++;
    }

    // function that Edit existing menu item  
    void editMenuItem(int& id, string& newName, string& newDescription, double& newPrice,  string& newCategory, int& newStock) {
        for (int i = 0; i < itemCount; i++) {
            if (menuItems[i].id == id) {
                menuItems[i].name = newName;
                menuItems[i].description = newDescription;
                menuItems[i].price = newPrice;
                menuItems[i].category = newCategory;
                menuItems[i].stock = newStock;
                return;
            }
        }
        cout << "Menu item not found." << endl;
    }




    // /-------------------------------------        mohamed rashik part         -------------------------------------/



    /* re study*/
    // function that Delete menu item
    void deleteMenuItem(int id) {
        for (int i = 0; i < itemCount; i++) {
            if (menuItems[i].id == id) {
                for (int j = i; j < itemCount - 1; j++) {
                    menuItems[j] = menuItems[j + 1];
                }
                itemCount--;
                return;
            }
        }
        cout << "Menu item not found." << endl;
    }

    // function that Display all menu items
    void displayAllMenuItems() const {
        for (int i = 0; i < itemCount; i++) {
            menuItems[i].display();
        }
    }
    // function that Get a menu item by ID
    MenuItem* getMenuItemById(int id) {
        for (int i = 0; i < itemCount; i++) {
            if (menuItems[i].id == id) {
                return &menuItems[i];
            }
        }
    }
};


struct OrderItem {//declaring a Struct for a single order item
    MenuItem menuItem;
    int quantity;

    OrderItem(const MenuItem& mi = MenuItem(), int q = 0) //Constructor to initialize an order item
    { menuItem = mi; quantity = q; }
};

class OrderManager { //Class for managing customer order
private:
    OrderItem currentOrder[order_size];//array of objects of order items
    int orderItemCount;
    double totalPrice;

public:
    OrderManager() { orderItemCount = 0; totalPrice = 0.0; } //empty Constructor to initialize the order manager.

    // function to Add item to order
    void addItemToOrder(const MenuItem& menuItem, int quantity) {
        if (orderItemCount < order_size) {
            currentOrder[orderItemCount] = OrderItem(menuItem, quantity);
            totalPrice += menuItem.price * quantity;
            orderItemCount++;
        }
        else {
            cout << "Order is full." << endl;
        }
    }

   
    /*
restudy
*/
    // function to Display current order
    void displayOrder() const {
        cout << "Current Order: " << endl;
        for (int i = 0; i < orderItemCount; i++) {
            cout << currentOrder[i].menuItem.name << " x " << currentOrder[i].quantity
                << " - $" << currentOrder[i].menuItem.price * currentOrder[i].quantity << endl;
        }
        cout << "Total Price: $" << totalPrice << endl;
    }

    // function for Process payment
    void processPayment(const string& paymentMethod) {
        cout << "\nPayment of $" << totalPrice << " received via " << paymentMethod << "." << endl;
    }
/*
re study
*/
    // function to Generate invoice
    void generateInvoice() const {
        cout << "\nInvoice:" << endl;
        for (int i = 0; i < orderItemCount; i++) {
            cout << currentOrder[i].menuItem.name << " x " << currentOrder[i].quantity
                << " - $" << currentOrder[i].menuItem.price * currentOrder[i].quantity << endl;
        }
        cout << "Total Price: $" << totalPrice << endl;
    }
};


// /-----------------------------------------      mohamed osama part         ---------------------------------------/




// function for Menu Management options
void choice_menu_items(MenuManager& menuManager) {
    cout << "1- Add new menu items\n";
    cout << "2- Edit existing menu items\n";
    cout << "3- Delete menu items\n";
    cout << "4- Display all menu items\n";
    int x;
    cin >> x;
    if (x == 1)
    {
        string name, description, category;
        double price;
        int stock;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter description: ";
        getline(cin, description);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter category: ";
        cin >> category;
        cout << "Enter stock: ";
        cin >> stock;
        menuManager.addMenuItem(name, description, price, category, stock);
    }

   
    else if (x == 2)
    {
        int id;
        string newName, newDescription, newCategory;
        double newPrice;
        int newStock;
        cout << "Enter ID of the item to edit: ";
        cin >> id;
        cout << "Enter new name: ";
        cin >> newName;
        cout << "Enter new description: ";
        getline(cin, newDescription);
        cout << "Enter new price: ";
        cin >> newPrice;
        cout << "Enter new category: ";
        cin >> newCategory;
        cout << "Enter new stock: ";
        cin >> newStock;
        menuManager.editMenuItem(id, newName, newDescription, newPrice, newCategory, newStock);

    }
        else if (x==3)
    {
        int id;
        cout << "Enter id of the item to delete: ";
        cin >> id;
        menuManager.deleteMenuItem(id);
    }
        else if (x==4)
    {
        cout << "all menu items:" << endl;
        menuManager.displayAllMenuItems();
    }


        
 
}
// /-------------------------------------             mohamed alaa part          ------------------------------------/



//function for  Customer Order options
void choice_customer_orders(OrderManager& orderManager, MenuManager& menuManager) {
    int x;
    cout << "1- create new order\n";
    cout << "2- display current order\n";
    cin >> x;
    if (x == 1)
    {
        int id, quantity;
        string choise;
        do {
            cout << "enter menu item ID: ";
            cin >> id;
            MenuItem* item = menuManager.getMenuItemById(id);
            if (item) {
                cout << "enter quantity: ";
                cin >> quantity;
                orderManager.addItemToOrder(*item, quantity);
            }
            else {
                cout << "menu item not found." << endl;
            }
            cout << "add more items? yes or no: ";
            cin >> choise;
        } while (choise == "yes");
    }
    else if(x==2)
    {
        orderManager.displayOrder();

    }
    else{
        cout << "invalid choice" << endl;
    }
}

//function for  Payment Processing options
void choice_Process_payments(OrderManager& orderManager) 
{
    string paymentMethod;
    cout << "enter payment method cash or credit: ";
    cin >> paymentMethod;
    orderManager.processPayment(paymentMethod);
}

// function for Invoice Generation options
void choice_Generate_invoices(OrderManager& orderManager) 
{
    orderManager.generateInvoice();
}


// /-------------------------------------             Kirolos Ashraf Nasr part          ------------------------------------/

//function for  User choices
void choices(MenuManager& menuManager, OrderManager& orderManager) {//
    int x;
    cout << "enter your choice: ";
    cin >> x;
    if (x == 1) {
        choice_menu_items(menuManager);
    }
    else if (x == 2) {
        choice_customer_orders(orderManager, menuManager);
    }
    else if (x == 3) {
        choice_Process_payments(orderManager);
    }
    else if (x == 4) {
        choice_Generate_invoices(orderManager);
    }
    else {
        cout << "invalid choice" << endl;
    }
}

// Starting the program
static void start() { //done
    while (true) {
        MenuManager menuManager;
        OrderManager orderManager;
        cout << "Welcome to the Restaurant Management System\n";
        cout << "1- Manage menu items\n";
         cout << "2- Take customer orders\n";
        cout << "3- Process payments\n";
        cout << "4- Generate invoices\n";
          choices(menuManager, orderManager);
    }
}

int main() {
    
        start();
    

  

    return 0;
}