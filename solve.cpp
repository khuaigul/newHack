#include "classes.h"
using namespace std;

vector<int> solve(vector<Stand>& Stands, vector<Plane>& Planes)
{
	Plane tmp;
	tmp.flight_datatime.year = 0;
	tmp.flight_datatime.month = 0;
	tmp.flight_datatime.day = 0;
	tmp.flight_datatime.hour = 0;	
	tmp.flight_datatime.minute = 0;
	tmp.flight_datatime.second = 0;
	vector<Plane> was(Stands.size(), tmp);
	vector<int> ans(Planes.size());
	for(auto plane: Planes)
	{
		int mn = 1000000000;
		int poz = 0;
		int bestm;
		for(auto stand: Stands)
		{
			int minute = stand.Taxiing_Time;
			if(stand.Terminal == 0 && plane.plane_type.name == "regional") minute += Handling_Time::regional_away;
			if(stand.Terminal != 0 && plane.plane_type.name == "regional") minute += Handling_Time::regional_jet;				
			if(stand.Terminal == 0 && plane.plane_type.name == "narrow") minute += Handling_Time::narrow_away;
			if(stand.Terminal != 0 && plane.plane_type.name == "narrow") minute += Handling_Time::narrow_jet;
			if(stand.Terminal == 0 && plane.plane_type.name == "wide") minute += Handling_Time::wide_away;
			if(stand.Terminal != 0 && plane.plane_type.name == "wide") minute += Handling_Time::wide_jet;					
		//	if(plane.flight_AD == 'D') plane.flight_datatime.minute -= minute;
			plane.flight_datatime.minute += stand.Taxiing_Time;
		//	cout << was[stand.Aircraft_Stand].flight_datatime.minute << " " << plane.flight_datatime.minute << " " << cost(plane, stand) << " " << mn << endl;
			if(was[stand.Aircraft_Stand] < plane && cost(plane, stand) < mn
				&& !(plane.plane_type.name == "wide" && stand.Terminal != 0 &&
					 was[stand.Aircraft_Stand - 1].plane_type.name == "wide" && 
						was[stand.Aircraft_Stand - 1] < plane ) && 
						!(plane.plane_type.name == "wide" && stand.Terminal != 0 &&
					 was[stand.Aircraft_Stand + 1].plane_type.name == "wide" && 
						was[stand.Aircraft_Stand + 1] < plane ) )
			{
				bestm = minute;
				mn = cost(plane, stand);
				poz = stand.Aircraft_Stand;				
			}
		//	if(plane.flight_AD == 'D') plane.flight_datatime.minute += minute;
			plane.flight_datatime.minute -= stand.Taxiing_Time;		
		}
		plane.flight_datatime.minute += 2;
	//	if(plane.flight_AD == 'A')
		plane.flight_datatime.minute += bestm;		
		was[poz] = plane;		
	//	if(plane.flight_AD == 'A')
		plane.flight_datatime.minute -= bestm;
		ans[plane.id] = poz;
	}
	return ans;		
}
