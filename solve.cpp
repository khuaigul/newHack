#include "classes.h"
using namespace std;

vector<int> solve(vector<Stand>& Stands, vector<Plane>& Planes)
{
	vector<Plane> was(Stands.size(), 0);
	vector<int> ans(Planes.size());
	for(auto plane: Planes)
	{
		int mn = 1000000000;
		int poz = 0;
		for(auto stand: Stands)
		{
			if(was[stand.Aircraft_Stand] < plane && cost(plane, stand) < mn)
			{
				mn = cost(plane, stand);
				poz = stand.Aircraft_Stand;				
			}
		}
		was[poz] = plane;
		ans[plane.id] = poz;
	}
	return ans;		
}
