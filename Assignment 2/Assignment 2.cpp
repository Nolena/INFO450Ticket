// Assignment 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;






int main()
{

	}

class Ticket
{
private:
	int iD;
	char status;
	char type;
	int priority;
	string name[100];
	string description[1000];
	int userImpact;

public:

	Ticket(int i, char s, char t, int p, char n, char d, int u)
	{
		iD = i, status = s, type = t, priority = p, name = n, description = d, userImpact = u;

	}
	void CaptureTicket()
	{
		char ticketQuestion;

		cout << "Open new ticket? (Y)es or (N)o?" << endl;
		cin >> ticketQuestion;

		switch (ticketQuestion)
		{
		default:
			cout << "Invalid response! Please try again." << endl;
			break;

		case 'Y':
		case 'y':
			cout << "What is the name of the caller?" << endl;
			gets_s(name);
			cout << "What is the issue type? (S)erver, (A)pplication, a(C)cess" << endl;
			switch (type)
			{
			default:
				cout << "Invalid response! Please try again." << endl;
				break;

			case 'S':
			case 's':
				type = 's';
				break;

			case 'A':
			case 'a':
				type = 'a';
				break;

			case 'C':
			case 'c':
				type = 'c';
				break;
			}
			cout << "Description of issue?" << endl;
			getline (description);
			cout << "How many users are impacted?" << endl;
			cin >> userImpact
			break;
		case 'N':
		case 'n':

			break;

		}
		void ShowTicket();
		void CloseTicket();
	}
};