#include "../includes/philo.h"

int	start_simulation(t_table *table)
{
	int	i;

	table->start = currunt_time_ms();
	i = 0;
	while (i < table->philos)
	{
		if (pthread_create(&table->philo[i].thread, 0,
				status, &table->philo[i]) != 0)
			return (print_errorno(THREAD_ERROR, i));
		i++;
		usleep(10);
	}
	check_finished_eating(table);
	i = 0;
	while (i < table->philos)
	{
		pthread_detach(table->philo[i].thread);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	*status(void *param)
{
	t_philo		*philo;
	t_table		*table;
	pthread_t	monitor;

	philo = (t_philo *)param;
	table = philo->table;
	if (philo->id % 2 || philo->id + 1 == table->philos)
		msleep(table->time_to_eat, table);
	if (pthread_create(&monitor, 0, monitoring, philo) != 0)
	{
		table->is_finished = 1;
		return (NULL);
	}
	while (!table->is_finished)
	{
		eating(philo);
		philo->eat_count++;
		print_status(philo, "is sleeping");
		msleep(table->time_to_sleep, table);
		print_status(philo, "is thinking");
		usleep(100);
	}
	pthread_detach(monitor);
	return (NULL);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	}
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->eaten);
	print_status(philo, "is eating");
	philo->dead_line = elapsed_time(philo->table) + philo->table->time_to_die;
	pthread_mutex_unlock(&philo->table->eaten);
	msleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
}

void	check_finished_eating(t_table *table)
{
	int	i;
	int	finished_eating;

	if (table->must_eat >= 0)
	{
		while (!table->is_finished)
		{
			i = 0;
			finished_eating = FAILURE;
			while (i < table->philos)
			{
				if (table->philo[i].eat_count < table->must_eat)
				{
					finished_eating = SUCCESS;
					break ;
				}
				i++;
			}
			if (finished_eating)
				table->is_finished = FAILURE;
		}
	}
	else
		while (!table->is_finished)
			;
}

void	*monitoring(void *param)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)param;
	table = philo->table;
	while (!table->is_finished)
	{
		pthread_mutex_lock(&table->eaten);
		if (elapsed_time(table) > philo->dead_line)
		{
			print_status(philo, "died");
			table->is_finished = FAILURE;
		}
		pthread_mutex_unlock(&table->eaten);
		usleep(100);
	}
	return (NULL);
}
