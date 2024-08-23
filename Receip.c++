#include <bits/stdc++.h>

using namespace std;

struct Item {
    string name;
    double price;
};

struct Order {
    string customerName;
    vector<Item> items;
};

const double VAT_RATE = 0.1;  // VAT rate of 10%

void displayOrder(const Order &order) {
    cout << "Customer Name: " << order.customerName << endl;
    cout << "---------------------------------------------\n";
    cout << setw(20) << "Item Name" << setw(10) << "Price" << endl;
    cout << "---------------------------------------------\n";

    double totalPrice = 0.0;

    for (const auto &item : order.items) {
        cout << setw(20) << item.name << setw(10) << fixed << setprecision(2) << item.price << endl;
        totalPrice += item.price;
    }

    double vat = totalPrice * VAT_RATE;
    double totalAmount = totalPrice + vat;

    cout << "---------------------------------------------\n";
    cout << setw(20) << "Total (excluding VAT)" << setw(10) << fixed << setprecision(2) << totalPrice << endl;
    cout << setw(20) << "VAT (" << (VAT_RATE * 100) << "%)" << setw(10) << fixed << setprecision(2) << vat << endl;
    cout << "---------------------------------------------\n";
    cout << setw(20) << "Total Amount" << setw(10) << fixed << setprecision(2) << totalAmount << endl;
    cout << "---------------------------------------------\n";
}

int main() {
    Order order;

    cout << "Enter customer name: ";
    getline(cin, order.customerName);

    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    for (int i = 0; i < numItems; ++i) {
        Item item;
        cout << "Enter item name for item " << i + 1 << ": ";
        cin.ignore();  // Consume the newline character left in the buffer
        getline(cin, item.name);

        cout << "Enter price for item " << i + 1 << ": ";
        cin >> item.price;

        order.items.push_back(item);
    }

    // Display the order details
    displayOrder(order);

    return 0;
}
