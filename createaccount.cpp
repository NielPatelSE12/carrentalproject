#include "createaccount.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

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

// Function to display the account
void CreateAccount::displayAccounts(){
    std::ifstream file("accounts.csv");
    std::string line;

    if(file.is_open()){
        while(std::getline(file,line)){
            std :: cout << line << std:: endl;
        }
        file.close();
    }else{
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

void CreateAccount::editAccount(){
    //input and output streams for file handling
    std :: ifstream file("accounts.csv");
    // Array of dynamic strings
    std :: vector<std::string>lines;
    std:: string line,firstName,lastName,licenseNumber,dateOfBirth,emailAddress;
    std:: string searchLicenseNumber;
    bool found = false;

    if(file.is_open()){
        //vector libary tool to set the value to the end of the array
        while(std::getline(file,line)){
            lines.push_back(line);
        }
        file.close();
    }else{
        std :: cerr << "Unable to open file for reading" << std :: endl;
        return;
    }

    std :: cout << "Enter the license number of the account to edit:";
    std :: cin >> searchLicenseNumber;

    
    for(size_t i = 0; i < lines.size(); ++i){
        //
      std :: istringstream iss(lines[i]);
      std :: getline(iss, firstName, ',');
      std :: getline(iss, lastName,',');
      std :: getline(iss,licenseNumber,',');
      std :: getline(iss,licenseNumber,',');
      std :: getline(iss,dateOfBirth,',');
      std :: getline(iss,emailAddress,',');

      if(licenseNumber == searchLicenseNumber){
        found = true;


        std :: cout << "Editing account:" << lines[i] << std :: endl;

        std:: cout << "Enter new first name (or press enter to keep current):";
        std:: cin.ignore();
        std:: getline(std::cin, firstName);
        std:: cout << "Enter the new last name (or press enter to keep current):";
        std:: getline(std::cin,lastName);
        std:: cout << "Enter new license number (or press enter to keep current)";
        std:: getline(std::cin,licenseNumber);
        std:: cout << "Enter new date of birth (or press enter to keep current)";
        std:: getline(std::cin,dateOfBirth);
        std:: cout << "Enter new email address (or press enter to keep current)";
        std:: getline(std::cin,emailAddress);

        //
        std:: ostringstream oss;
        oss << firstName << "," << lastName <<"," << licenseNumber << "," << dateOfBirth << "," << emailAddress << ",";

        std ::ofstream outfile("accounts.csv");
        if(outfile.is_open()){
            for(const auto& line: lines){
                outfile << line << "\n";
            }
        }outfile.close();
        std:: cout << "Account has been updated successfully." << std:: endl;
      }else{
        std :: cerr << "Unable to open file for writing." << std :: endl;
      }break;


    }
    if(!found){
        std :: cerr << "Account not found." << std :: endl;
    }

}