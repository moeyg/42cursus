#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	state[3];

	state[0] = ((point - a) * (b - a)) <= Fixed(0);
	state[1] = ((point - b) * (c - b)) <= Fixed(0);
	state[2] = ((point - c) * (a - c)) <= Fixed(0);
	if (state[0] == state[1] && state[1] == state[2] && state[2] == state[0])
		return (true);
	return (false);
}