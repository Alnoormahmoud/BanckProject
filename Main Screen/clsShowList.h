#pragma once

#include <iostream>
#include "clsBanckClients.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsShowList
{
   static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }
public:

 
   static  void ShowClientsList()
    {
       if (!clsScreen::CheackAccessRight(clsBanckUser::enPermission::pListClients))
       {
           return;
       }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Tiltle = "Client List Screen";
        string Sub = "("+ to_string(vClients.size()) + ") Client(s).";

        clsScreen::_DrawScreenHeader(Tiltle,Sub);
         cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};