#include <iostream>
#include "createaccount.h"

int main() {
    char x;
    std::cout << "Welcome to Razer Car Rental, press y to continue or n to exit" << std::endl;
    std::cin >> x;

    if (x == 'y' || x == 'Y') {
        do {
            int choice;
            std::cout << "Please pick an option below with the correct choice" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "* MAIN MENU OPTIONS *" << std::endl;
            std::cout << "1. Create a new account" << std::endl;
            std::cout << "2. Edit an account" << std::endl;
            std::cout << "3. View an account" << std::endl;
            std::cout << "4. Delete an account" << std::endl;
            std::cin >> choice;

            if (choice == 1) {
                std::cout << "You would like to create a new account" << std::endl;
                CreateAccount newAccount("", "", "", "", "");
            } else if (choice == 2) {
                std::cout << "You would like to edit an account" << std::endl;
            } else if (choice == 3) {
                std::cout << "You would like to view an account" << std::endl;
            } else if (choice == 4) {
                std::cout << "You would like to delete an account" << std::endl;
            } else {
                std::cout << "The option you have is not available. Please pick another one" << std::endl;
            }

            std::cout << "Would you like to continue? (y/n)" << std::endl;
            std::cin >> x;
        } while (x == 'y' || x == 'Y');
    }

    return 0;
}