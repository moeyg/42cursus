#include "../includes/philo.h"

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
		if (initialize(&table, argc, argv) == EXIT_FAILURE)
		{
			return (print_errorno(INITIALIZE_ERROR, 0));
		}
		if (start_simulation(&table) == EXIT_FAILURE)
		{
			return (print_errorno(SIMULATION_ERROR, 0));
		}
		if (free_resource(&table) == EXIT_FAILURE)
		{
			return (print_errorno(FREE_ERROR, 0));
		}
	}
	return (EXIT_SUCCESS);
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

int	print_errorno(int error_code, int thread)
{
	if (error_code == INITIALIZE_ERROR)
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
	{
		printf("Error: Failed to create thread: %d\n", thread);
	}
	return (EXIT_FAILURE);
}
