#include <bits/stdc++.h>
#include "classes.h"
using namespace std;

void static_input(string file, void (*parse)(string row))
{
	ifstream in_file(file);
	string str;
	while(in_file >> str)
		parse(str);
	in_file.close();	
}

void Stand::parse(string row)
{
	if (row[0] == 'A')
		return;
	string buf = "";
	int num = 0;
	for (int i = 0; i < (int)row.size(); i++)
	{
		if(row[i] == ',')
		{
			if (num == 0)
				Aircraft_Stand = stoi(buf);
			else if (num == 1)
				JetBridge_on_Arrival = buf[0];
			else if (num == 2)
				JetBridge_on_Departure = buf[0];
			else if (num == 3)
				for (int j = 1; j <= 5; j++)
					Time_To_Terminal[j] = stoi(buf);
			else if (num == 4)
				Terminal = stoi(buf);
			buf = "";	
			num++;
		}
		else
		{
			buf += row[i];
		}
	}
	Taxiing_Time = stoi(buf);
}

void Plane::parse(string row)
{
	if (row[0] == 'f')
		return;
	string buf = "";
	int num = 0;
	for (int i = 0; i < (int)row.size(); i++)
	{
		if (row[i] == ',')
		{
			if (num == 0)
				flight_AD = buf[0];
			else if (num == 1)
				flight_datatime.parse(buf);
			else if (num == 2)
				flight_AL_Synchron_code = buf;
			else if (num == 3)
				flight_number = stoi(buf);
			else if (num == 4)
				flight_ID = buf[0];
			else if (num == 5)
				flight_terminal = stoi(buf);
			else if (num == 6)
				flight_AP = buf;
			else if (num == 7)
				flight_AC_Synchron_code = buf;
			else if (num == 8)
				flight_AC_PAX_capacity_total = stoi(buf);
			else if (num == 9)
				flight_PAX = stoi(buf);

			buf = "";
			num++;
		}
		else
			buf += row[i];
	}

	if (flight_AC_PAX_capacity_total <= Aircraft_Classes::regional)
	{
		plane_type.name = "regional";
		plane_type.JetBridge_Handling_Time = Handling_Time::regional_jet;
		plane_type.Away_Handling_Time = Handling_Time::regional_away;
	}
	else if (flight_AC_PAX_capacity_total <= Aircraft_Classes::narrow)
	{
		plane_type.name = "narrow";
		plane_type.JetBridge_Handling_Time = Handling_Time::narrow_jet;
		plane_type.Away_Handling_Time = Handling_Time::narrow_away;
	}
	else if (flight_AC_PAX_capacity_total <= Aircraft_Classes::wide)
	{
		plane_type.name = "wide";
		plane_type.JetBridge_Handling_Time = Handling_Time::wide_jet;
		plane_type.Away_Handling_Time = Handling_Time::wide_away;
	}
}

void Datatime::parse(string row)
{
	string buf = "";
	for (int i = 0; i < (int)row.size(); i++)
	{
		if (i == 4)
		{
			year = stoi(buf);
			buf = "";
		}
		else if (i == 7)
		{
			month = stoi(buf);
			buf = "";
		}
		else if (i == 10)
		{
			day = stoi(buf);
			buf = "";
		}
		else if (i == 13)
		{
			hour = stoi(buf);
			buf = "";
		}
		else if (i == 16)
		{
			minute = stoi(buf);
			buf = "";
		}
		else 
			buf = buf + row[i];
	}
	second = stoi(buf);
}


void Handling_Time::parse(string row)
{
	if(row[0] == 'A')
		return;
	bool id = 0;
	string name = "";
	string jet = "";
	string away = "";
	for (int i = 0; i < (int)row.size(); i++)
	{
		if (row[i] == ',')
			id = 1;
		else if (id == 0)
		{
			name += row[i];	
		}
		else if(id == 1)
		{
			jet += row[i];
		}
		else
			away += row[i];
	}	
	if(name == "Regional")
	{
		regional_jet = stoi(jet);
		regional_away = stoi(away);
	}
	else if(name == "Narrow_Body")
	{
		narrow_jet = stoi(jet);
		narrow_away = stoi(away);
	}
	else
	{
		wide_jet = stoi(jet);
		wide_away = stoi(away);
	}
}

void Taxes::parse(string row)
{
	if(row[0] == 'N')
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
	if(name == "Bus_Cost_per_Minute") Bus_Cost_per_Minute = stoi(buf);
	else if(name == "Away_Aircraft_Stand_Cost_per_Minute") 
		Away_Aircraft_Stand_Cost_per_Minute = stoi(buf);
	else if(name == "JetBridge_Aircraft_Stand_Cost_per_Minute")
		JetBridge_Aircraft_Stand_Cost_per_Minute = stoi(buf);
	else Aircraft_Taxiing_Cost_per_Minute = stoi(buf);
}