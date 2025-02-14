#pragma once
#include <iostream>
using namespace std;


class clsEncripAndDecript
{

public:

	static string Encrypt(string text,int Key)
	{
		string encrypted = "";
		for (int i = 0; i < text.length(); i++)
			encrypted += (text[i] + Key);
		return encrypted;
	}

	static string Decrypt(string text,int Key)
	{
		string decrypted = "";
		for (int i = 0; i < text.length(); i++)
			decrypted += (text[i] - Key);
		return decrypted;
	}
};

