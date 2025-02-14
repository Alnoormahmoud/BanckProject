#pragma once

#include <iostream>
 #include "clsInputValidate.h"

class clsUpdateClient:private clsScreen
{
	 
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter The New First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter The New Last Name Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter The New Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter The NewPhone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter The New Pin Code: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter The New Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();


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
		cout << "\nAccNumber   : " << Client.AccountNumber();
		cout << "\nPinCode     : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:

	static void UpdateClient()
	{
		if (!CheackAccessRight(clsBanckUser::enPermission::pUpdateClients))
		{
			return;
		}

		_DrawScreenHeader("Update Client");

		cout << "Please Enter Client Account Number : ";

		string AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "Account Number You've Entered is Not Valid, Please Enter A Correct One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		_ReadClientInfo(Client1);

		clsBankClient::enSaveResults SvSuccessful;
		SvSuccessful = Client1.Save();

		switch (SvSuccessful)
		{
			case clsBankClient::svFaildEmptyObject:
			cout << "\nError Account Was Not Saved Because It Was Empty ): \n";
			break;

			case clsBankClient::svSucceeded:
			cout << "\nClient Updated Successfully (: \n";
			_PrintClient(Client1);

			break;

		}
	}

 
};

