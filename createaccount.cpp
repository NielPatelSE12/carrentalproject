#include "createaccount.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

// Constructor definition
CreateAccount::CreateAccount(std::string first_name, std::string last_name, std::string license_number, std::string date_of_birth, std::string email_address) {
    firstName = first_name;
    lastName = last_name;
    licenseNumber = license_number;
    dateOfBirth = date_of_birth;
    emailAddress = email_address;

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

void CreateAccount::displayAccounts() {
    std::ifstream file("accounts.csv");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

void CreateAccount::editAccount() {
    std::ifstream file("accounts.csv");
    std::vector<std::string> lines;
    std::string line, firstName, lastName, licenseNumber, dateOfBirth, emailAddress;
    std::string searchLicenseNumber;
    bool found = false;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
        return;
    }

    std::cout << "Enter the license number of the account to edit: ";
    std::cin >> searchLicenseNumber;

    for (size_t i = 0; i < lines.size(); ++i) {
        std::istringstream iss(lines[i]);
        std::string tempFirstName, tempLastName, tempLicenseNumber, tempDateOfBirth, tempEmailAddress;
        
        std::getline(iss, tempFirstName, ',');
        std::getline(iss, tempLastName, ',');
        std::getline(iss, tempLicenseNumber, ',');
        std::getline(iss, tempDateOfBirth, ',');
        std::getline(iss, tempEmailAddress, ',');

        if (tempLicenseNumber == searchLicenseNumber) {
            found = true;

            std::cout << "Editing account: " << lines[i] << std::endl;

            std::cout << "Enter new first name (or press enter to keep current): ";
            std::cin.ignore();
            std::getline(std::cin, firstName);
            if (firstName.empty()) firstName = tempFirstName;

            std::cout << "Enter new last name (or press enter to keep current): ";
            std::getline(std::cin, lastName);
            if (lastName.empty()) lastName = tempLastName;

            std::cout << "Enter new license number (or press enter to keep current): ";
            std::getline(std::cin, licenseNumber);
            if (licenseNumber.empty()) licenseNumber = tempLicenseNumber;

            std::cout << "Enter new date of birth (or press enter to keep current): ";
            std::getline(std::cin, dateOfBirth);
            if (dateOfBirth.empty()) dateOfBirth = tempDateOfBirth;

            std::cout << "Enter new email address (or press enter to keep current): ";
            std::getline(std::cin, emailAddress);
            if (emailAddress.empty()) emailAddress = tempEmailAddress;

            std::ostringstream oss;
            oss << firstName << "," << lastName << "," << licenseNumber << "," << dateOfBirth << "," << emailAddress;
            lines[i] = oss.str();

            std::ofstream outfile("accounts.csv");
            if (outfile.is_open()) {
                for (const auto& line : lines) {
                    outfile << line << "\n";
                }
                outfile.close();
                std::cout << "Account updated successfully." << std::endl;
            } else {
                std::cerr << "Unable to open file for writing." << std::endl;
            }
            break;
        }
    }

    if (!found) {
        std::cerr << "Account not found." << std::endl;
    }
}
