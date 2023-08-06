#include "../includes/philo_bonus.h"

int	initialize(t_table *table, int argc, char *argv[])
{
	table->philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
	table->philo = malloc(sizeof(t_philo) * table->philos);
	if (table->philo == 0)
		return (EXIT_FAILURE);
	initialize_philo(table);
	if (initialize_semaphore(table))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	initialize_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		table->philo[i].id = i;
		table->philo[i].eat_count = 0;
		table->philo[i].finished = 0;
		table->philo[i].table = table;
		i++;
	}
}

int	initialize_semaphore(t_table *table)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/check_eat");
	sem_unlink("/over_eaten");
	sem_unlink("/is_finished");
	table->forks = sem_open("/forks", O_CREAT, S_IRWXU, table->philos);
	if (table->forks == SEM_FAILED)
		return (EXIT_FAILURE);
	table->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (table->print == SEM_FAILED)
		return (EXIT_FAILURE);
	table->eaten = sem_open("/check_eat", O_CREAT, S_IRWXU, 1);
	if (table->eaten == SEM_FAILED)
		return (EXIT_FAILURE);
	table->over_eaten = \
		sem_open("/over_eaten", O_CREAT, S_IRWXU, table->philos);
	if (table->over_eaten == SEM_FAILED)
		return (EXIT_FAILURE);
	table->is_finished = \
		sem_open("/is_finished", O_CREAT, S_IRWXU, table->philos);
	if (table->is_finished == SEM_FAILED)
		return (EXIT_FAILURE);
	return (0);
}
