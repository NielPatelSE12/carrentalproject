#include "createaccount.h"
#include <iostream>


// Constructor definition
CreateAccount::CreateAccount(std :: string firstname, std :: string lastname, std :: string licensenumber, std :: string dateofbirth, std :: string emailaddress){
    firstName = firstname;
    lastName  = lastname;
    licenseNumber = licensenumber;
    dateofbirth = dateOfBirth;
    emailAddress = emailaddress;

    std :: cout << "Please enter first name:";
    std :: cin >> firstName;
    std :: cout << " " << std :: endl;
    std :: cout << "Please enter last name:";
    std :: cout << " " << std :: endl;
    std :: cout << "Please enter license number:";
    std :: cout << " " << std :: endl;
    std :: cout << "Please enter date of birth (mm-dd-yyyy):";
    std :: cout << " " << std :: endl;
    std :: cout << "Please enter email address:";

    
}