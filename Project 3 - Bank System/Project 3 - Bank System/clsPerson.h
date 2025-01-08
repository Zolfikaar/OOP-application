#pragma once
#include <iostream>
using namespace std;

class clsPerson
{

private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	// Constructor
	clsPerson( string firstName, string lastName, string email, string phone)
	{
		_FirstName = firstName;
		_LastName = lastName;
		_Email = email;
		_Phone = phone;
	}

	// Setter Methods
	void SetFirstName(string firstName)
	{
		_FirstName = firstName;
	}

	void SetLastName(string lastName)
	{
		_LastName = lastName;
	}

	void SetEmail(string email)
	{
		_Email = email;
	}

	void SetPhone(string phone)
	{
		_Phone = phone;
	}

	// Getter Methods

	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;


	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	void Print()
	{
		cout << "\nPerson Info:\n";
		cout << "------------------------";
		cout << "First Name: " << _FirstName << endl;
		cout << "Last Name: " << _LastName << endl;
		cout << "Full Name: " << FullName() << endl;
		cout << "Email: " << _Email << endl;
		cout << "Phone: " << _Phone << endl;
		cout << "------------------------";
	}

	/*void SendEmail(string Subject, string Body)
	{
		cout << "\n\nThe following message sent successfully to the email: " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
	}

	void SendSMS(string Message)
	{
		cout << "\nThe following SMS sent successfully to the phone number: " << _Phone << endl;
		cout << Message << endl;
	}*/
};

