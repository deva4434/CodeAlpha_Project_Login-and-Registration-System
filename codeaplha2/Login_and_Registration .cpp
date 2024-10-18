#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function for user registration
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Create and write user credentials to a file
    ofstream file;
    file.open(username + ".txt");
    file << username << endl;
    file << password << endl;
    file.close();

    cout << "Registration successful! Your credentials have been saved.\n";
}

// Function to check user login
bool loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open the user's file and read stored credentials
    ifstream file;
    file.open(username + ".txt");
    if (file.is_open()) {
        getline(file, storedUsername);
        getline(file, storedPassword);

        // Validate the entered credentials
        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful!\n";
            file.close();
            return true;
        } else {
            cout << "Invalid username or password.\n";
            file.close();
            return false;
        }
    } else {
        cout << "User not found. Please register first.\n";
        return false;
    }
}

int main() {
    int choice;

    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                // User logged in successfully
                cout << "Welcome to the system!\n";
            }
            break;
        default:
            cout << "Invalid choice. Exiting...\n";
            break;
    }

    return 0;
}
