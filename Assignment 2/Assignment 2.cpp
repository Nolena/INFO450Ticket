// Assignment 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


class Ticket
{
private:
	int iD;
	string status;
	char type;
	string priority;
	string name;
	string description;
	int userImpact = 0;
	static int idGenerator;

public:
	Ticket() 
	{
		iD = idGenerator;
		idGenerator++;
		status = "Open";
	};
	void ShowTicket();
	void CaptureTicket();
	void CloseTicket();
};

	int Ticket::idGenerator = 0;

	void Ticket::CaptureTicket()
	{
		cin.clear();
		cin.ignore();
		cout << "What is the name of the caller?" << endl;
		getline(cin,name);
		cout << "What is the issue type? (S)erver, (A)pplication, A(C)cess" << endl;
		cin >> type;
		cin.ignore();
		cout << "Description of issue?" << endl;
		getline(cin,description);
		cout << "How many users are impacted?" << endl;
		cin >> userImpact;
		cin.clear();
		cin.ignore();
		cout << "Issue ID: " << iD << endl;
	}

	void Ticket::ShowTicket() 
	{
		cout << "----------------------" << endl;
		cout << "Ticket ID: " << iD << endl;
		cout << "Type of issue: " << type << endl;
		switch (type) 
		{
		default:
			cout << "Unspecified" << endl;
			break;

		case 's':
		case 'S':
			cout << "Server" << endl;
			break;

		case 'a':
		case 'A':
			cout << "Application" << endl;
			break;

		case 'c':
		case 'C':
			cout << "Access" << endl;
			break;
		}
		cout << "Status: " << status << endl;
		cout << "Description of issue: " << description << endl;
		cout << "User: " << name << endl;
		cout << "Users Impacted: " << userImpact << endl;
		cout << "Priority: ";
		if (userImpact < 10) 
		{
			cout << "LOW" << endl;
		}
			
		else if (userImpact >= 10 && userImpact < 50) 
		{
			cout << "MEDIUM" << endl;
		}
		else if (userImpact >= 50) 
		{
			cout << "HIGH" << endl;
		}
		else 
		{
			cout << "NONE" << endl;
		}
		cout << "----------------------" << endl;
	}

	void Ticket::CloseTicket() 
	{
		status = "Closed";
		cout << "Ticket " << iD << " has been closed" << endl;
	}

	int main()
	{
		const int MAX = 100;
		char create;
		const char no = 'n';
		const char No = 'N';
		const char yes = 'y';
		const char Yes = 'Y';
		Ticket myTickets[MAX];
		int number = 0;

		do
		{
			cout << "Create new ticker? (Y)es or (N)o?" << endl;
			cin >> create;

			if (create == yes || create == Yes)
			{
				myTickets[number].CaptureTicket();
				++number;
			}

			else if (create == no || create == No)
			{
				for (int i = 0; i < number; ++i)
				{
					myTickets[i].ShowTicket();
					myTickets[0].CloseTicket();

					return 0;
				}
			}

			else
			{
				cout << "Invalid selection, please try again!" << endl;
			}
		} while (create != no || create != No);
	
	}

