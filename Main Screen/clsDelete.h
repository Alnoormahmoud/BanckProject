#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsBanckClients.h"
#include "clsInputValidate.h"


class clsDeleteClient:protected clsScreen
{
    static    void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAccNumber   : " << Client.AccountNumber();
        cout << "\nPinCode     : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountNumber();
        cout << "\n___________________\n";

    }

public:

    static void DeleteClient()
    {
        if (!CheackAccessRight(clsBanckUser::enPermission::pDeleteClient))
        {
            return;
        }

        string Tiltle = "Delete CLient Screen";
        string Sub = "Deleting New Client";

        _DrawScreenHeader(Tiltle, Sub);
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }

};
 