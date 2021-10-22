#include <bits/stdc++.h>
#include "classes.h"
using namespace std;

int Aircraft_Classes::regional;
int Aircraft_Classes::narrow;
int Aircraft_Classes::wide;
int Handling_Time::regional_jet;
int Handling_Time::regional_away;
int Handling_Time::narrow_jet;
int Handling_Time::narrow_away;
int Handling_Time::wide_jet;
int Handling_Time::wide_away;
int Taxes::Bus_Cost_per_Minute;
int Taxes::Away_Aircraft_Stand_Cost_per_Minute;
int Taxes::JetBridge_Aircraft_Stand_Cost_per_Minute;
int Taxes::Aircraft_Taxiing_Cost_per_Minute;

int main()
{
	static_input("data_set/AirCraftClasses_Pablic.csv", &Aircraft_Classes::parse);
	static_input("data_set/Handling_Time_Public.csv", &Handling_Time::parse);
	static_input("data_set/Handling_Rates_Public.csv", &Taxes::parse);
	vector<Stand> Stands;
	input("data_set/Aircraft_Stands_Public.csv", Stands);
	vector<Plane> Planes;
	input("data_set/Timetable_Public.csv", Planes);

}