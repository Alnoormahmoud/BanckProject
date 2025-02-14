#pragma once
#include<iostream>
#include"clsBanckClients.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;


class clsWithdrow : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAxxountNumber()
    {
        string AccountNumber;
        cout << "Enter The Account Number : ";
        cin >> AccountNumber;

        return AccountNumber;
    }

public:

    static void Withdrow()
    {
        _DrawScreenHeader("Withdrow Screen");

        string AccountNumber = _ReadAxxountNumber();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "\nSorrry, Account [" << AccountNumber << "] Is Not Exist, ";
            AccountNumber = _ReadAxxountNumber();
        };
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        int Amount;
        cout << "\nPlease Enter Amount Bigger Than 0 And Less Than " << Client.AccountBalance << " : ";
        Amount = clsInputValidate::ReadDblNumberBetween(1, Client.AccountBalance, "\nSorry, Cant't Withdrow Amount,Please Enter The Amount Bigger Than 0 And Less Than Your Cirrent Amount : ");

     
        char Permission;
        cout << "\nAre You Sure You Want To Performe This Operation : ";
        cin >> Permission;

        if (Permission == 'y' || Permission == 'Y')
        {
            Client.Withdrow(Amount);
            cout << "\nAmount Was Withdrowed Successfuly (: \n";
            cout << "\nNew Balance Is : (" << Client.AccountBalance << ")\n";
        }
        else
        {
            cout << "\nOperation Was Canceled ): \n";

        }

    }

};

