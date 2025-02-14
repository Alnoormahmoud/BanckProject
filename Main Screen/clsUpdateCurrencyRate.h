#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRate : private clsScreen
{
 
	static void _ReadNewCurrenyRate(clsCurrency& Currency)
	{
		cout << "\nUpdate Currency Rate : ";
		cout << "\n__________________________________";

		cout << "\n\nEnter The New Rate : ";

		Currency.UpdateRate(clsInputValidate::ReadFloatNumber());
	};

	static    void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n\t\t\t\t\Currency Info : ";
		cout << "\n\t\t\t___________________________________________\n";
		cout << "\n\t\t\t\tCountry     : " << Currency.Country();
		cout << "\n\t\t\t\tCode        : " << Currency.CurrencyCode();
		cout << "\n\t\t\t\tName        : " << Currency.CurrencyName();
		cout << "\n\t\t\t\tRate/(1$) = : " << Currency.Rate();
		cout << "\n\t\t\t___________________________________________\n";

	}

public:

	static void UpdateCurrencyRate()
	{
		_DrawScreenHeader("Update Currency Rate");

		cout << "\nPlease Enter Currency Country : ";

		string CurrencyCountry = clsInputValidate::ReadString();

		while (!(clsCurrency::IsCurrencyExistByCountry(CurrencyCountry)))
		{
			cout << "Country You've Entered is Not Valid, Please Enter A Correct One : ";
			CurrencyCountry = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCountry(CurrencyCountry);

		_PrintCurrency(Currency1);

		cout << "\nAre You Sure You Want Upadate The Rate Of Tis Currency ? Y/N : ";
		string UpdateMode = clsInputValidate::ReadString();

		if (UpdateMode == "y" || UpdateMode == "Y")
		{
			_ReadNewCurrenyRate(Currency1);
			 
			cout << "\Currency Rate Updated Successfully (: \n";
				 
			_PrintCurrency(Currency1);

		}
		else
		{

		}
		
	}


};

