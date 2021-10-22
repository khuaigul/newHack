#ifndef CLASSES_H
#define CLASSES_H
#include <bits/stdc++.h>
using namespace std;

template<class T>
void input(string file, vector<T>& data)
{
	ifstream in_file(file);
	int sz = 0;
	string str;
	while(in_file >> str)
	{
//		cout << (int)str.size() << endl;
		if ((int)str.size() == 0)
			continue;
		data.push_back(T());
		data[sz++].parse(str);
	}	
	in_file.close();	
}

void static_input(string file, void (*parse)(string row));

struct Aircraft_Classes
{	
	static int regional;
	static int narrow;
	static int wide;

	static void parse(string row)
	{
		if (row[0] == 'A')
			return;
		bool id = 0;
		string name = "";
		string buf = "";
		for (int i = 0; i < (int)row.size(); i++)
		{
			if (row[i] == ',')
				id = 1;
			else if (id == 0)
			{
				name += row[i];	
			}
			else
			{
				buf += row[i];
			}
		}	
		if(name == "Regional") regional = stoi(buf);
		else if(name == "Narrow_Body") narrow = stoi(buf);
		else wide = stoi(buf);
	}
};

struct Handling_Time
{
	static int regional_jet;
	static int regional_away;
	static int narrow_jet;
	static int narrow_away;
	static int wide_jet;
	static int wide_away;

	static void parse(string row);
};

struct Taxes
{
	static int Bus_Cost_per_Minute;
	static int Away_Aircraft_Stand_Cost_per_Minute;
	static int JetBridge_Aircraft_Stand_Cost_per_Minute;
	static int Aircraft_Taxiing_Cost_per_Minute;

	static void parse(string row);
};

struct Plane_Type
{
	string name;
	int JetBridge_Handling_Time;
	int Away_Handling_Time;
};

struct Datatime
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;

	void parse(string row);
};

struct Plane
{
	char flight_AD;
	Datatime flight_datatime;
	string flight_AL_Synchron_code;
	int flight_number;
	char flight_ID;
	int flight_terminal;
	string flight_AP;
	string flight_AC_Synchron_code;
	int flight_AC_PAX_capacity_total;
	int flight_PAX;
	int Aircraft_Stand;
	Plane_Type plane_type;

	void parse(string row);
};

struct Stand
{
	int Aircraft_Stand;
	char JetBridge_on_Arrival;
	char JetBridge_on_Departure;
	int Time_To_Terminal[6];
	int Terminal;
	int Taxiing_Time;

	void parse(string row); 
};

#endif