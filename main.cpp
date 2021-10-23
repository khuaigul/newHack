#include <bits/stdc++.h>
#include "classes.h"
using namespace std;


int main()
{
	static_input("data_set/AirCraftClasses_Public.csv", &Aircraft_Classes::parse);
	static_input("data_set/Handling_Time_Public.csv", &Handling_Time::parse);
	static_input("data_set/Handling_Rates_Public.csv", &Taxes::parse);
	vector<Stand> Stands;
	input("data_set/Aircraft_Stands_Public.csv", Stands);
	vector<Plane> Planes;
	input("data_set/Timetable_Public.csv", Planes);
	sort(Planes.begin(), Planes.end());
	output("data_set/Timetable_Public.csv", solve(Stands, Planes));

}