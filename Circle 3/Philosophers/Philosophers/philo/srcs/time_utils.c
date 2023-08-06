#include "../includes/philo.h"

void	msleep(int time, t_table *table)
{
	long	end_time;

	end_time = elapsed_time(table);
	while (!table->is_finished)
	{
		if (elapsed_time(table) - end_time >= time)
			break ;
		usleep(50);
	}
}

long	currunt_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	elapsed_time(t_table *table)
{
	int	elapsed_time;

	elapsed_time = (int)(currunt_time_ms() - table->start);
	return (elapsed_time);
}
