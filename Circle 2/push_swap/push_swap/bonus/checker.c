#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	{
		return (0);
	}
	initialize_stack(&stack_a);
	if (!argv[1][0])
	{
		print_error();
	}
	initialize_stack(&stack_b);
	check_operation(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
