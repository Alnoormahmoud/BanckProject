 #pragma once
#include<iostream>
#include"clsBanckClients.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;


class clsTransfare : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n________________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n________________________\n";

    }

    static string _ReadSenderAccountNumber()
    {
        string AccountNumber;
        cout << "\nEnter Account Number To Transfare From : ";
        cin >> AccountNumber;

        return AccountNumber;
    } 
    
    static string _ReadResivererAccountNumber()
    {
        string AccountNumber;
        cout << "\nEnter Account Number To Transfare To : ";
        cin >> AccountNumber;

        return AccountNumber;
    }

public:
  
    static void Transfare()
    {
        _DrawScreenHeader("Transfare Screen");


        string SenderAccountNumber = _ReadSenderAccountNumber();

        while (!(clsBankClient::IsClientExist(SenderAccountNumber)))
        {
            cout << "\nSorrry, Account [" << SenderAccountNumber << "] Is Not Exist, ";
            SenderAccountNumber = _ReadSenderAccountNumber();
        };
        clsBankClient SenderClient = clsBankClient::Find(SenderAccountNumber);
        _PrintClient(SenderClient);



        string ResiverAccountNumber = _ReadResivererAccountNumber();

        while (!(clsBankClient::IsClientExist(ResiverAccountNumber)))
        {
            cout << "\nSorrry, Account [" << ResiverAccountNumber << "] Is Not Exist, ";
            ResiverAccountNumber = _ReadResivererAccountNumber();
        };

        if (ResiverAccountNumber == SenderAccountNumber)
        {
            cout << "\nSorry, Can't Send To This Account Number Sender And Resiver Is The Same \n";
            return;
        }

        clsBankClient ResiverClient = clsBankClient::Find(ResiverAccountNumber);
        _PrintClient(ResiverClient);

        int Amount;

        cout << "\nPlease Enter Amount Bigger Than 0 And Less Than " << SenderClient.AccountBalance << " : ";
        Amount = clsInputValidate::ReadDblNumberBetween(1, SenderClient.AccountBalance, "\nSorry, Cant't Transfare Amount,Please Enter The Amount Bigger Than 0 And Less Than Your Cirrent Amount : ");


        char Permission;
        cout << "\nAre You Sure You Want To Performe This Operation : ";
        cin >> Permission;
        if (Permission == 'Y' || Permission == 'y')
        {
            if (SenderClient.Transfare(Amount, ResiverClient, CurrentUser.UserName))
            {
                cout << "\nAmount Was Tranfared Successfuly From (" << SenderAccountNumber << ") Account Number To (" << ResiverAccountNumber << ") Account Number (: \n";
                cout << "\nYour New Balance Is : \n";

                cout << "\nSender : \n";
                _PrintClient(SenderClient);

                cout << "\nResiver : \n";
                _PrintClient(ResiverClient);
              }
            else
            {
                cout << "\nTransfair Falied ): \n";
            }
        }
        else
        {
            cout << "\nOperation Was Canceled ): \n";

        }

    }

};

