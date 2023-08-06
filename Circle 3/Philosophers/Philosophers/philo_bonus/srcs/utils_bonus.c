#include "../includes/philo_bonus.h"

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

void	free_resource(t_table *table)
{
	sem_close(table->forks);
	sem_close(table->print);
	sem_close(table->eaten);
	sem_close(table->over_eaten);
	sem_close(table->is_finished);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eaten");
	sem_unlink("/over_eaten");
	sem_unlink("/is_finished");
	free(table->philo);
}

void	print_status(t_philo *philo, char *status)
{
	sem_wait(philo->table->print);
	printf("%d %d %s\n", elapsed_time(philo->table), philo->id + 1, status);
	sem_post(philo->table->print);
}
