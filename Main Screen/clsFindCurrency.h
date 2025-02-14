#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrency :public clsScreen
{

private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n\t\t\t\t\Currency Info: ";
        cout   << "\n\t\t\t___________________________________________\n";
        cout << "\n\t\t\t\tCountry     : " << Currency.Country();
        cout << "\n\t\t\t\tCode        : " << Currency.CurrencyCode();
        cout << "\n\t\t\t\tName        : " << Currency.CurrencyName();
        cout << "\n\t\t\t\tRate/(1$) = : " << Currency.Rate();
        cout << "\n\t\t\t___________________________________________";

    }

public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("Find Currency Screen");

        cout << "\n\nFind By [1] : Code Or [2] : CountryName : ";

        int FinBy = clsInputValidate::ReadDblNumberBetween(1, 2, "Enter Number 1 Or 2 : ");

        if (FinBy == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter Currency Code : ";

            CurrencyCode = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
            {
                cout << "\nCurrency is not found, choose another one: ";
                CurrencyCode = clsInputValidate::ReadString();
            }

            clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

            if (!Currency1.IsEmpty())
            {
                cout << "\nCurrency Found :-)\n";
            }
            else
            {
                cout << "\nCurrency Was not Found :-(\n";
            }

            _PrintCurrency(Currency1);
        }
        else
        {
            string CountryName;

            cout << "\nPlease Enter Country Name : ";

            CountryName = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyExistByCountry(CountryName))
            {
                cout << "\nCurrency is not found, choose another one: ";
                CountryName = clsInputValidate::ReadString();
            }

            clsCurrency Currency1 = clsCurrency::FindByCountry(CountryName);

            if (!Currency1.IsEmpty())
            {
                cout << "\nCurrency Found :-)\n";
            }
            else
            {
                cout << "\nCurrency Was not Found :-(\n";
            }

            _PrintCurrency(Currency1);
        }
    

    }

};

