#include "push_swap.h"

int	compare_rotations(int a, int b, int a_loc, int b_loc)
{
	return (abs(a) + abs(b) > abs(a_loc) + abs(b_loc));
}

int	abs(int num)
{
	if (num > 0)
		return (num);
	else
		return (-num);
}
