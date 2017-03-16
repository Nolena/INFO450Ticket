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
	char status;
	string type;
	char priority;
	string name;
	string description;
	int userImpact = 0;
	static int idGenerator;

public:
	Ticket() {};
	Ticket(static int idGenerator, int iD);
	Ticket(int i, char s, string t, char p, string n, string d, int u)
	{
		iD = i, status = s, type = t, priority = p, name = n, description = d, userImpact = u;
	}
	void ShowTicket();
	void CaptureTicket();
	void CloseTicket();
};

Ticket::Ticket( static int idGenerator, int iD) 
{
	idGenerator = 1;
	iD = idGenerator++;

}
	void Ticket::CaptureTicket()
	{
		int typeID;
		cout << "What is the name of the caller?" << endl;
		getline(cin, name);
		cout << "What is the issue type? 0 = Server, 1 = Application, 2 = Access" << endl;
		cin >> typeID;
		if (typeID = 0)
			type = "Server";
		if (typeID = 1)
			type = "Application";
		if (typeID = 2)
			type = "Access";
		cout << "Description of issue?" << endl;
		getline(cin, description);
		cout << "How many users are impacted?" << endl;
		cin >> userImpact;
		if (userImpact < 10)
			priority = 'LOW';
		if (userImpact >= 10 && userImpact < 50)
			priority = 'MED';
		if (userImpact > 50)
			priority = 'HIGH';
	}

	void Ticket::ShowTicket() 
	{
		cout << "----------------------" << endl;
		cout << "Ticket ID: " << iD << endl;
		cout << "Name: " << name << endl;
		cout << "Type of issue: " << type << endl;
		cout << "Description of issue: " << description << endl;
		cout << "Status: " << status << endl;
		cout << "Priority: " << priority << endl;
		cout << "----------------------" << endl;
	}

	void Ticket::CloseTicket() 
	{

	}



	int main()
	{
		const int MAX = 100;

		Ticket myTickets[MAX];

		for (int i = 0; i < MAX; i++)
		{
			myTickets[i].CaptureTicket();
		}

		for (int i = 0; i < MAX; i++)
		{
			myTickets[i].ShowTicket();
		}

		return 0;
		
	}

