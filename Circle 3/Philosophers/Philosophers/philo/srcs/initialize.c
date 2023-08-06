#include "../includes/philo.h"

int	initialize(t_table *table, int argc, char *argv[])
{
	table->philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->must_eat = ft_atoi(argv[5]);
	}
	else
	{
		table->must_eat = -1;
	}
	table->is_finished = 0;
	table->philo = malloc(sizeof(t_philo) * table->philos);
	if (table->philo == NULL)
	{
		return (print_errorno(MALLOC_ERROR, 0));
	}
	initialize_philo(table);
	if (initialize_mutex(table))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	initialize_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		table->philo[i].id = i;
		table->philo[i].left_fork = i;
		table->philo[i].right_fork = (i + 1) % table->philos;
		table->philo[i].eat_count = 0;
		table->philo[i].dead_line = table->time_to_die;
		table->philo[i].table = table;
		i++;
	}
}

int	initialize_mutex(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos);
	if (table->forks == NULL)
	{
		return (print_errorno(MALLOC_ERROR, 0));
	}
	i = 0;
	while (i < table->philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&table->print, NULL) != 0)
	{
		return (EXIT_FAILURE);
	}
	if (pthread_mutex_init(&table->eaten, NULL) != 0)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
