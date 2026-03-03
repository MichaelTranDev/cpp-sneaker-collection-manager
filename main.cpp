#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// 1. Define an Enum for Brand
enum SneakerBrand { NIKE, ADIDAS, JORDAN, NEW_BALANCE, VANS, OTHER };

// 2. Define an Enum for Category
enum SneakerCategory { RUNNING, BASKETBALL, LIFESTYLE, SKATE, TRAINING };

// 3. Define a Struct (Sneaker)
struct Sneaker {
    string modelName;
    SneakerBrand brand;
    SneakerCategory category;
    double size;
    double price;
    bool isDeadstock;
    int yearReleased;
};

// 4. Helper Functions
string brandToString(SneakerBrand b) {
    switch (b) {
        case NIKE: return "Nike";
        case ADIDAS: return "Adidas";
        case JORDAN: return "Jordan";
        case NEW_BALANCE: return "New Balance";
        case VANS: return "Vans";
        case OTHER: return "Other";
        default: return "Unknown";
    }
}

string categoryToString(SneakerCategory c) {
    switch (c) {
        case RUNNING: return "Running";
        case BASKETBALL: return "Basketball";
        case LIFESTYLE: return "Lifestyle";
        case SKATE: return "Skate";
        case TRAINING: return "Training";
        default: return "Unknown";
    }
}

// 6. Display Function for a single sneaker
void displaySneaker(Sneaker s) {
    cout << left << setw(20) << "Model Name:" << s.modelName << "\n"
         << left << setw(20) << "Brand:" << brandToString(s.brand) << "\n"
         << left << setw(20) << "Category:" << categoryToString(s.category) << "\n"
         << left << setw(20) << "Size:" << s.size << "\n"
         << left << setw(20) << "Retail Price:" << "$" << fixed << setprecision(2) << s.price << "\n"
         << left << setw(20) << "Deadstock:" << (s.isDeadstock ? "Yes" : "No") << "\n"
         << left << setw(20) << "Year Released:" << s.yearReleased << "\n"
         << "----------------------------------------\n";
}

// 6. Display Function for the whole array
void displayAll(Sneaker arr[], int count) {
    if (count == 0) {
        cout << "\nYour collection is currently empty.\n";
        return;
    }
    
    cout << "\n=== Your Sneaker Collection ===\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < count; i++) {
        displaySneaker(arr[i]);
    }
}

// Function to handle adding a new sneaker via user input
void addSneaker(Sneaker arr[], int& count, int max) {
    if (count >= max) {
        cout << "Collection is full! Cannot add more sneakers.\n";
        return;
    }

    Sneaker newSneaker;
    cout << "\n--- Add a New Sneaker ---\n";
    
    cout << "Model Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    getline(cin, newSneaker.modelName);

    int brandInput;
    cout << "Brand (0=Nike, 1=Adidas, 2=Jordan, 3=New Balance, 4=Vans, 5=Other): ";
    cin >> brandInput;
    newSneaker.brand = static_cast<SneakerBrand>(brandInput);

    int catInput;
    cout << "Category (0=Running, 1=Basketball, 2=Lifestyle, 3=Skate, 4=Training): ";
    cin >> catInput;
    newSneaker.category = static_cast<SneakerCategory>(catInput);

    cout << "Size (e.g., 10.5): ";
    cin >> newSneaker.size;

    cout << "Retail Price (USD): ";
    cin >> newSneaker.price;

    int dsInput;
    cout << "Is it Deadstock? (1 for Yes, 0 for No): ";
    cin >> dsInput;
    newSneaker.isDeadstock = (dsInput == 1);

    cout << "Year Released: ";
    cin >> newSneaker.yearReleased;

    // Add to array and increment count
    arr[count] = newSneaker;
    count++;
    
    cout << "\nSneaker added successfully!\n";
}

int main() {
    // 5. Array of Structs
    const int MAX_SNEAKERS = 20;
    Sneaker collection[MAX_SNEAKERS] = {
        {"Air Max 1", NIKE, RUNNING, 10.5, 150.00, true, 2023},
        {"Yeezy Boost 350", ADIDAS, LIFESTYLE, 10.0, 220.00, false, 2019},
        {"Air Jordan 1 Chicago", JORDAN, BASKETBALL, 11.0, 180.00, true, 2022},
        {"990v6", NEW_BALANCE, LIFESTYLE, 9.5, 200.00, true, 2023},
        {"Old Skool", VANS, SKATE, 10.0, 70.00, false, 2021},
        {"Metcon 8", NIKE, TRAINING, 10.5, 130.00, false, 2022},
        {"Ultraboost 1.0", ADIDAS, RUNNING, 11.5, 190.00, true, 2015},
        {"Air Jordan 4 Bred", JORDAN, BASKETBALL, 10.0, 210.00, false, 2019}
    };
    int count = 8; // We pre-loaded 8 sneakers

    int choice;

    // 7. Main Menu
    do {
        cout << "\n===== Sneaker Collection Manager =====\n";
        cout << "1. Display All Sneakers\n";
        cout << "2. Add a Sneaker\n";
        cout << "3. Search by Brand        [Part 2]\n";
        cout << "4. Search by Size         [Part 2]\n";
        cout << "5. Sort by Price          [Part 2]\n";
        cout << "6. Sort by Year           [Part 2]\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displayAll(collection, count);
                break;
            case 2:
                addSneaker(collection, count, MAX_SNEAKERS);
                break;
            case 3:
            case 4:
            case 5:
            case 6:
                cout << "\nComing in Part 2...\n";
                break;
            case 0:
                cout << "\nExiting Collection Manager. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

