#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define PARAMETER_ERROR	0
# define INITIALIZE_ERROR	1
# define SIMULATION_ERROR	2
# define FREE_ERROR			3
# define MALLOC_ERROR		4
# define THREAD_ERROR		5

# define SUCCESS			0
# define FAILURE			1

typedef struct s_philo
{
	struct s_table	*table;
	int				id;
	int				left_fork;
	int				right_fork;
	int				dead_line;
	int				eat_count;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	int				philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_finished;
	long			start;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eaten;
}	t_table;

/* main.c */
int		print_errorno(int error_code, int thread);

/* initialize.c */
int		initialize(t_table *table, int argc, char *argv[]);
void	initialize_philo(t_table *table);
int		initialize_mutex(t_table *table);

/* status.c */
int		start_simulation(t_table *table);
void	*status(void *philosopher);
void	eating(t_philo *philo);
void	check_finished_eating(t_table *table);
void	*monitoring(void *philosopher);

/* time_utils.c */
void	msleep(int time, t_table *table);
long	currunt_time_ms(void);
int		elapsed_time(t_table *table);

/* utils.c */
int		ft_atoi(char *str);
int		ft_strncmp(const char *str1, const char *str2, int length);
int		free_resource(t_table *table);
void	print_status(t_philo *philo, char *status);

#endif
