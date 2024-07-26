#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <iostream>
#include <string>

class CreateAccount {
private:
    // Class variables
    std::string firstName;
    std::string lastName;
    std::string licenseNumber;
    std::string dateOfBirth;
    std::string emailAddress;

public:
    // Constructor Declaration
    CreateAccount(std::string first_name, std::string last_name, std::string license_number, std::string date_of_birth, std::string email_address);


    //function methods
    void writeToCSV();
    static void editAccount();
    static void displayAccounts();
    
};

#endif
