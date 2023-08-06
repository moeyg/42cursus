#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int	index;
	int	num;

	index = 0;
	num = 0;
	while (str[index] && str[index] >= '0' && str[index] <= '9')
	{
		num *= 10;
		num += str[index] - '0';
		index++;
	}
	return (num);
}

int	ft_strncmp(const char *str1, const char *str2, int length)
{
	int				index;
	unsigned char	string1;
	unsigned char	string2;

	index = 0;
	while (index < length && (str1[index] != '\0' || str2[index] != '\0'))
	{
		string1 = str1[index];
		string2 = str2[index];
		if (string1 != string2)
		{
			return (string1 - string2);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

int	free_resource(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		if (pthread_mutex_unlock(&table->forks[i]) != 0)
			return (EXIT_FAILURE);
		if (pthread_mutex_destroy(&table->forks[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_unlock(&table->print) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&table->print) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_unlock(&table->eaten) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&table->eaten) != 0)
		return (EXIT_FAILURE);
	free(table->forks);
	free(table->philo);
	return (EXIT_SUCCESS);
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&(philo->table->print));
	if (!(philo->table->is_finished))
	{
		printf("%d %d %s\n", elapsed_time(philo->table), philo->id + 1, status);
	}
	if (ft_strncmp(status, "died", 4) != 0)
	{
		pthread_mutex_unlock(&(philo->table->print));
	}
}
