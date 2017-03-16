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
	char type;
	char priority;
	char name[50];
	char description[500];
	int userImpact = 0;
	static int idGenerator;

public:
	Ticket() {};
	Ticket(static int idGenerator, int iD);
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
		gets_s(name);
		cout << "What is the issue type? 0 = Server, 1 = Application, 2 = Access" << endl;
		cin >> typeID;
		if (typeID = 0) 
			type = 'Ser';
		if (typeID = 1)
			type = 'App';
		if (typeID = 2)
			type = 'Acc';
		cout << "Description of issue?" << endl;
		gets_s(description);
		cout << "How many users are impacted?" << endl;
		cin >> userImpact;
		if (userImpact < 10)
			priority = 'LOW';
		if (userImpact >= 10 && userImpact < 50)
			priority = 'MED';
		if (userImpact > 50)
			priority = 'HIGH';
		cin.clear();
		cin.ignore();
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

