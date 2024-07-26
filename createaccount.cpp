#include "createaccount.h"
#include <fstream>
#include <iostream>

// Constructor definition
CreateAccount::CreateAccount(std::string firstname, std::string lastname, std::string licensenumber, std::string dateofbirth, std::string emailaddress) {
    firstName = firstname;
    lastName  = lastname;
    licenseNumber = licensenumber;
    dateOfBirth = dateofbirth;
    emailAddress = emailaddress;

    std::cout << "Please enter first name: ";
    std::cin >> firstName;
    std::cout << "Please enter last name: ";
    std::cin >> lastName;
    std::cout << "Please enter license number: ";
    std::cin >> licenseNumber;
    std::cout << "Please enter date of birth (mm-dd-yyyy): ";
    std::cin >> dateOfBirth;
    std::cout << "Please enter email address: ";
    std::cin >> emailAddress;

    writeToCSV();
}

void CreateAccount::writeToCSV() {
    std::ofstream file("accounts.csv", std::ios::app);

    if (file.is_open()) {
        file << firstName << "," 
             << lastName << "," 
             << licenseNumber << "," 
             << dateOfBirth << "," 
             << emailAddress << "\n";
        file.close();
        std::cout << "Account created successfully and written to CSV." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}



