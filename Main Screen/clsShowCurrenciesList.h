 #pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsShowCurrenciesList
{
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
 
    }
public:


    static  void ShowCurrenciesList()
    {
  
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        string Tiltle = "Currencies List Screen";
        string Sub = "(" + to_string(vCurrency.size()) + ") Currencies.";

        clsScreen::_DrawScreenHeader(Tiltle, Sub);

         cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};