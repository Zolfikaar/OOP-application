#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{

private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "\nClient Card\n";
        cout << "\n______________________________________\n" << endl;
        cout << "Full Name : " << Client.FullName() << endl;
        cout << "Acc Number: " << Client.AccountNumber() << endl;
        cout << "Balance   : " << Client.AccountBalance << endl;
        cout << "\n______________________________________\n" << endl;
    }

    static void _CheckClientAndPrintInfo(string AccountNumber, clsBankClient Client)
    {
        if (clsBankClient::IsClientExist(AccountNumber))
        {
            _PrintClientCard(Client);
        }
        else {
            cout << "\nClient with account number: " << AccountNumber << " does not exist";
            cout << "\n______________________________________\n" << endl;
        }
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t  Transfer Screen");

        cout << "Please Enter Account Number to Transfer from: ";
        string FromAccount = clsInputValidate::ReadString();
        clsBankClient FromClient = clsBankClient::Find(FromAccount);
        _CheckClientAndPrintInfo(FromAccount, FromClient);

        cout << "Please Enter Account Number to Transfer to: ";
        string ToAccount = clsInputValidate::ReadString();
        clsBankClient ToClient = clsBankClient::Find(ToAccount);

        while(FromAccount == ToAccount) {
            cout << "\nEnter A Different Account Number: ";
            ToAccount = clsInputValidate::ReadString();
            ToClient = clsBankClient::Find(ToAccount);
        }

        _CheckClientAndPrintInfo(ToAccount, ToClient);


        cout << "Enter Transfer Amount: ";
        double Amount = clsInputValidate::ReadDblNumber();

        while (Amount > FromClient.AccountBalance)
        {
            cout << "Amount Exceeds the availabe balance,";
            cout << "Enter another amount: ";
            Amount = clsInputValidate::ReadDblNumber();
        } 

        cout << "\nAre you sure that you want to perform this operation? y/n: ";
        char Answer = clsInputValidate::ReadConfermUserOption();

        if (Answer == 'Y' || Answer == 'y')
        {

            if (FromClient.Transfer(Amount, ToClient, CurrentUser.UserName))
            {
                cout << "\nTransfer Done Successfully!" << endl;
                _PrintClientCard(FromClient);
                _PrintClientCard(ToClient);
            }
            else {
                cout << "\nTransfer Failed" << endl;
            }
                       
        }

        else if (Answer == 'N' || Answer == 'n')
        {
            cout << "\nTransfer Canceled" << endl;
        }
        else {
            cout << "\nSomthing went wrong!\n";
            return;
        }
        
    }

};



