#include <bits/stdc++.h>
#include "classes.h"
using namespace std;


int main()
{
	static_input("data_set/AirCraftClasses_Private.csv", &Aircraft_Classes::parse);
	static_input("data_set/Handling_Time_Private.csv", &Handling_Time::parse);
	static_input("data_set/Handling_Rates_Private.csv", &Taxes::parse);
	vector<Stand> Stands;
	input("data_set/Aircraft_Stands_Private.csv", Stands);
	vector<Plane> Planes;
	input("data_set/Timetable_Private.csv", Planes);
	sort(Planes.begin(), Planes.end());
	output("data_set/Timetable_Private.csv", solve(Stands, Planes));

}