#include "../includes/philo.h"

static int	parse_arguments(int argc, char *argv[]);
static void	print_usage(void);

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	else
	{
		if (parse_arguments(argc, argv) == EXIT_FAILURE)
			return (print_errorno(PARAMETER_ERROR, 0));
		if (initialize(&table, argc, argv) == EXIT_FAILURE)
			return (print_errorno(INITIALIZE_ERROR, 0));
		if (start_simulation(&table) == EXIT_FAILURE)
			return (print_errorno(SIMULATION_ERROR, 0));
		if (free_resource(&table) == EXIT_FAILURE)
			return (print_errorno(FREE_ERROR, 0));
	}
	return (EXIT_SUCCESS);
}

static int	parse_arguments(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (EXIT_FAILURE);
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	print_errorno(int error_code, int thread)
{
	if (error_code == PARAMETER_ERROR)
	{
		printf("Error: Invalid arguments.\n");
	}
	else if (error_code == INITIALIZE_ERROR)
	{
		printf("Error: Failed to initialize structure.\n");
	}
	else if (error_code == SIMULATION_ERROR)
	{
		printf("Error: Failed to start status.\n");
	}
	else if (error_code == FREE_ERROR)
	{
		printf("Error: Failed to release memory.\n");
	}
	else if (error_code == MALLOC_ERROR)
	{
		printf("Error: Failed to allocate memory.\n");
	}
	else if (error_code == THREAD_ERROR)
		printf("Error: Failed to create thread: %d\n", thread);
	print_usage();
	return (EXIT_FAILURE);
}

static void	print_usage(void)
{
	printf("Usage: ./philo ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosoper_must_eat]\n");
}
