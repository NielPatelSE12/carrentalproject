#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <iostream>
#include <string>

class CreateAccount{
    private:
    // Class variables
    std :: string firstName;
    std :: string lastName;
    std :: string licenseNumber;
    std :: string dateOfBirth;
    std :: string emailAddress;

    public:
    // Default Constructor Declaration 
    CreateAccount(std :: string first_name, std :: string last_name, std :: string licensenumber, std :: string dateofbirth, std :: string emailaddress ){}
};

#endif 

