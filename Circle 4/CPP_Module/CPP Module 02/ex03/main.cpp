#include "Point.hpp"

int	main(void)
{
	Point a(1, 2);
	Point b(0, 0);
	Point c(2, 0);
	Point p(1, 1);

	std::cout << (p - a) * (b - a) << std::endl;
	std::cout << (p - b) * (c - b) << std::endl;
	std::cout << (p - c) * (a - c) << std::endl;
	std::cout << bsp(a, b, c, p) << std::endl;
	return (0);
}