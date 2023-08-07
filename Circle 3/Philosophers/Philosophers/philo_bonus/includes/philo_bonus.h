#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
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
	pid_t			pid;
	int				id;
	int				dead_line;
	int				eat_count;
	int				finished;
}	t_philo;

typedef struct s_table
{
	int				philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start;
	t_philo			*philo;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*eaten;
	sem_t			*over_eaten;
	sem_t			*is_finished;
}	t_table;

/* main_bonus.c */
void	kill_philosopher(t_table *table);
int		print_errorno(int error_code, int thread);

/* initialize_bonus.c */
int		initialize(t_table *table, int argc, char *argv[]);
void	initialize_philo(t_table *table);
int		initialize_semaphore(t_table *table);

/* status_bonus.c */
int		start_simulation(t_table *table);
void	status(t_philo *philo);
void	eating(t_philo *philo, t_table *table);
void	check_finished_eating(t_philo *philo, t_table *table);
void	*monitoring(void *philosopher);

/* time_utils_bonus.c */
void	msleep(int time, t_table *table);
long	current_time_ms(void);
int		elapsed_time(t_table *table);

/* utils_bonus.c */
int		ft_atoi(char *str);
int		ft_strncmp(const char *str1, const char *str2, int length);
void	free_resource(t_table *table);
void	print_status(t_philo *philo, char *status);

#endif
