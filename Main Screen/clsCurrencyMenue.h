#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsShowCurrenciesList.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculator.h"

class clsCurrencyMenue : protected clsScreen
{

    enum enCurrency { ListCurrecy = 1, FindCurrency = 2, UpdateCurrencyRate = 3, CurrencyCalculator = 4, GoBack = 5 };

    static short _ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 5] ? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
        return Choice;
    }


    static void _ShowListCurrencyScreen()
    {
        clsShowCurrenciesList::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrency::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRate::UpdateCurrencyRate();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
    }
 
    static  void _GoBackToManageUserMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage User Menue...\n";

        system("pause>0");
        ShowMCurrencyMenue();
    }


    static void _PerfromCurrencyMenueOption(enCurrency ManegeUser)
    {
        switch (ManegeUser)
        {
        case enCurrency::ListCurrecy:
        {
            system("cls");
            _ShowListCurrencyScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case  enCurrency::FindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToManageUserMenue();
            break;
        }

        case enCurrency::UpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToManageUserMenue();
            break;
        }

        case  enCurrency::CurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enCurrency::GoBack:
        {

        }
        }

    }

   
public:

    static void ShowMCurrencyMenue()
    {
        ///*if (!CheackAccessRight(clsBanckUser::enPermission::pManageUsers))
        //{
        //    return;
        //}*/

        system("cls");

        _DrawScreenHeader("Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrencyge Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currency.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Go Back To Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyMenueOption((enCurrency)_ReadCurrencyMenueOption());
    }
};

