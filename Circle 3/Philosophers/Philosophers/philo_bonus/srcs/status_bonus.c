#include "../includes/philo_bonus.h"

int	start_simulation(t_table *table)
{
	int	i;

	table->start = current_time_ms();
	i = 0;
	while (i < table->philos)
	{
		table->philo[i].pid = fork();
		if (table->philo[i].pid < 0)
		{
			return (EXIT_FAILURE);
		}
		if (table->philo[i].pid == 0)
		{
			status(&table->philo[i]);
		}
		i++;
		usleep(5);
	}
	msleep(5 * table->philos, table);
	return (0);
}

void	status(t_philo *philo)
{
	t_table		*table;
	pthread_t	monitor;

	table = philo->table;
	sem_wait(table->over_eaten);
	sem_wait(table->is_finished);
	philo->dead_line = table->time_to_die;
	if (pthread_create(&monitor, 0, monitoring, philo) != 0)
		exit(1);
	while (1)
	{
		eating(philo, table);
		philo->eat_count++;
		print_status(philo, "is sleeping");
		msleep(table->time_to_sleep, table);
		print_status(philo, "is thinking");
		usleep(100);
	}
	pthread_join(monitor, 0);
}

void	eating(t_philo *philo, t_table *table)
{
	sem_wait(table->forks);
	sem_wait(table->forks);
	print_status(philo, "has taken a fork");
	sem_wait(table->eaten);
	print_status(philo, "is eating");
	philo->dead_line = elapsed_time(table) + table->time_to_die;
	sem_post(table->eaten);
	msleep(table->time_to_eat, table);
	sem_post(table->forks);
	sem_post(table->forks);
}

void	check_finished_eating(t_philo *philo, t_table *table)
{
	if (table->must_eat >= 0)
	{
		if (philo->finished == SUCCESS && philo->eat_count >= table->must_eat)
		{
			sem_post(table->is_finished);
			sem_post(table->over_eaten);
			philo->finished = FAILURE;
		}
	}
}

void	*monitoring(void *philosopher)
{
	t_philo		*philo;
	t_table		*table;
	int			i;

	philo = (t_philo *)philosopher;
	table = philo->table;
	while (1)
	{
		sem_wait(table->eaten);
		if (elapsed_time(table) > philo->dead_line)
		{
			sem_wait(philo->table->print);
			printf("%d %d %s\n", \
				elapsed_time(philo->table), philo->id + 1, "died");
			sem_post(table->is_finished);
			i = 0;
			while (i++ < table->philos)
				sem_post(table->over_eaten);
			exit(0);
		}
		sem_post(table->eaten);
		check_finished_eating(philo, table);
		usleep(100);
	}
	return (NULL);
}
