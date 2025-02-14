#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsShowList.h"
#include "clsAddClient.h"
#include "clsDelete.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransactionScreen.h"
#include "clsManageUserMenue.h"
#include "clsLoggInHistory.h"
#include "clsCurrencyMenue.h"
 #include "global.h"
 #include "clsLoggInHistory.h"
 #include "clsPrintTime.h"
        

 
class clsMainScreen :protected clsScreen
{
private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, LoggInHistory = 8,CurrencyMenue = 9,eExit = 10
    };

    struct stclsBanckHistory
    {
        string _DateAndTime;
        string _UserName;
        string _Password;
        int _Permissions;
    };
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 10] ? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 10, "Enter Number between 1 to 10 ? ");
        return Choice;
    }

    static    void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAccNumber : " << Client.AccountNumber();
        cout << "\PinCode    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountNumber();
        cout << "\n___________________\n";

    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsShowList::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddClient::AddNewClient();
     }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClient::DeleteClient();
     }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClient::UpdateClient();
     }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionScreen::ShowTransactionMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUserMenue::ShowManageUserMenue();
    }

    static void _LoggInHistory()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    
    static void _Currency()
    {
      clsCurrencyMenue::ShowMCurrencyMenue();
    }

    static void _LoggOutScreeen()
    {
        CurrentUser = clsBanckUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::LoggInHistory:
            system("cls");
            _LoggInHistory();
            _GoBackToMainMenue();

             break; 
        case enMainMenueOptions::CurrencyMenue:
            system("cls");
            _Currency();
            _GoBackToMainMenue();
             break;

        case enMainMenueOptions::eExit:
            system("cls");
            _LoggOutScreeen();
             break;
        }

    }


public:
 
    static void ShowMainMenue()
    { 

        system("cls");
        _DrawScreenHeader("Main Screen");
 
        cout << "\t\t\t\t\t\t";
        clsPrintTime::HelloMessage();
        cout << CurrentUser.UserName;
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[01] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[02] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[03] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[04] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[05] Find Client.\n";
        cout << setw(37) << left << "" << "\t[06] Transactions.\n";
        cout << setw(37) << left << "" << "\t[07] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[08] LoggIns History.\n";
        cout << setw(37) << left << "" << "\t[09] Currency Manage.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

    }
 
};

