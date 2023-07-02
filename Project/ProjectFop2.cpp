#include <iostream>
using namespace std;

struct MenuItem 
{
    string name;
    int price;
};

struct Order 
{
    MenuItem item;
    int quantity;
};

int calculateTotalBill(const Order& order) 
{
    return order.item.price * order.quantity;
}

int main() 
{
    cout << "MENU CARD for Shahied Zulfikar Ali Bhutto Institute of Science and Technology, Islamabad (SZABIST -ISB) CAFE\n";

    MenuItem menu[5] = 
    {
        {"COFFEE", 150},
        {"TEA", 50},
        {"COLD COFFEE", 200},
        {"MILK SHAKES", 200},
        {"JUICE", 150}
    };

    int choice;
    cout << "\nSelect your drink:\n";
    for (int i = 0; i < 5; ++i) 
    {
        cout << "Press " << (i + 1) << " for " << menu[i].name << " - " << menu[i].price << " RS per " << menu[i].name << endl;
    }
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice < 1 || choice > 5) 
    {
        cout << "\nSorry, the selected option is not available. Thank you for coming.\n";
        return 0;
    }

    Order userOrder;
    userOrder.item = menu[choice - 1];
    cout << "\nEnter the quantity: ";
    cin >> userOrder.quantity;
    int totalBill = calculateTotalBill(userOrder);
    cout << "\nTotal amount: " << totalBill << " RS\n";
    int payment;
    cout << "Give money: ";
    cin >> payment;
    if (payment > totalBill) 
    {
        int change = payment - totalBill;
        cout << "Return: " << change << " RS\n";
    } 
    else if (payment == totalBill) 
    {
        cout << "Exact amount received. Thank you!\n";
    } 
    else 
    {
        cout << "Insufficient payment. Please give more money.\n";
    }

    cout << "\nEnjoy your " << userOrder.item.name << " - Thank you for coming!\n\n PROJECT DONE BY : \n TAYYAB RASHEED\n";

    int exitChoice;
    cout << "Enter 0 to exit or any other number to continue: ";
    cin >> exitChoice;

    if (exitChoice == 0)
    {
        cout << "\nThank you for using our service. Goodbye!\n";
        return 0;
    }

    main(); 

    return 0;
}