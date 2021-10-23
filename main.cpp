#include <bits/stdc++.h>
#include "classes.h"
using namespace std;


int main()
{
	static_input("N:\\@text_files\\хакатон\\newHack\\data_set\\Aircraft_Classes_Private.csv", &Aircraft_Classes::parse);
	static_input("N:\\@text_files\\хакатон\\newHack\\data_set\\Handling_Time_Private.csv", &Handling_Time::parse);
	static_input("N:\\@text_files\\хакатон\\newHack\\data_set\\Handling_Rates_Private.csv", &Taxes::parse);
	vector<Stand> Stands;
	input("N:\\@text_files\\хакатон\\newHack\\data_set\\Aircraft_Stands_Private.csv", Stands);
	vector<Plane> Planes;
	input("N:\\@text_files\\хакатон\\newHack\\data_set\\Timetable_private.csv", Planes);
	sort(Planes.begin(), Planes.end());
	output("N:\\@text_files\\хакатон\\newHack\\data_set\\Timetable_private.csv", solve(Stands, Planes));

}