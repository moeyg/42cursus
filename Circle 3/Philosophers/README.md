# **Philosophers**

> [![dogpark's 42 Philosophers Score](https://badge42.vercel.app/api/v2/clam4rmh700350fjk8ctdih83/project/3222006)](https://github.com/JaeSeoKim/badge42)

> 🔗 [Philosopher](https://dogpark-42cursus.notion.site/Philosophers-cc98022753a34b909cd60de86377ae73?pvs=4)

##### I never thought philosophy would be so deadly

##### _Summary : In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes._

##### _Version : 10_

<br>

### 📄 Assignment

> 🔗 [Assignment discription](https://dogpark-42cursus.notion.site/Assignment-7d3bc0b222cd4959b6826b4068eda975?pvs=4)

### 📌 Reference

> 🔗 [Reference](https://dogpark-42cursus.notion.site/Reference-c2aaf925d6214714b873778d42fc83ac?pvs=4)

<br>

# ✲ Introduction

##### _Here are the things you need to know if you want to succeed this assignment:_

- ##### _One or more philosophers sit a round table.<br>Ther is a large bowl of spaghetti in the middle of the table._

- ##### _The philosophers alternatively `eat`, `think`, or `sleep`.<br>While they are eating, they are not thinking nor sleeping;<br>while thinkg, they are not eating nor sleeping;<br>and, of course, while sleeping, they are not eating nor thinking._

- ##### _There are also forks on the table. There are `as many forks as philosophers`._

- ##### _Becuase serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand._

- ##### _When a philosopher has finished eating, they put their forks back on the table and start sleeping Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation._

- ##### _Every philosopher needs to eat and should never starve._

- ##### _Philosophers don't speak with each other._

- ##### _Philosophers don't know if another philospher is about to die._

- ##### _No need to say that philosophers should avoid dying!_

<br>

# ✲ Global Rules

##### _You have to write a program for the mandatory part and another one for the bonus part (if you decide to do the bonus part). They both have to comply with the following rules:_

- ##### _Global variables are forbidden!_

- ##### _Your(s) program(s) should take the following arguments: <br>`number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`_

  - ##### _`number_of_philosophers`: The number of philosophers and also the number of forks._

  - ##### _`time_to_die`(in milliseconds): If a philosopher didn't start eating `time_to_die` milliseconds the beginning of the simulation, they die._

  - ##### _`time_to_eat`(in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks._

  - ##### _`time_to_sleep`(in milliseconds): The time the philosopher will spend sleeping._

  - ##### _`number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies._

- ##### _Each philosopher has a number ranging frome `1` to `number_of_philosophers`._

- ##### _Philosopher number 1 sits next to philosopher number `number_of_philosophers`. Any other philosopher number N sits between philsopher number N - 1 and philsopher number N + 1._

##### _About the logs of your program:_

- ##### _Any state change of a philosopher must be formatted as follows:_

  - ##### _timestamp_in_ms X has taken a fork_
  - ##### _timestamp_in_ms X is eating_
  - ##### _timestamp_in_ms X is sleeping_
  - ##### _timestamp_in_ms X is thinking_
  - ##### _timestamp_in_ms X died_

  ##### _Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number._

- ##### _A displayed state message should not be mixed up with another message._

- ##### _A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher._

- ##### _Again, philosophers should avoid dying!_

> ⚠️ <br>
>
> ##### _Your program must not have any `data races`._

<br>

# ✲ Mandatory Part - Philosopher

| **Program name**     | `philo`                                                                                                                                                                                       |
| :------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Turn in files**    | philo/ `Makefile`, `_.h`, `_.c`,                                                                                                                                                              |
| **Makefile**         | `all, clean, fclean, re`                                                                                                                                                                      |
| **Arguments**        | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]                                                                                      |
| **External functs.** | memset, printf, malloc, free, write, usleep, gettimeofday, pthtread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
| **Libft 사용여부**   | No                                                                                                                                                                                            |
| **Description**      | Philosophers with threads and mutexes                                                                                                                                                         |

##### _The specific rules for the mandatory part are:_

- ##### _Each philosopher should be a thread._

- ##### _There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table._

- ##### _To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them._

<br>

# ✲ Bonus Part

| **Program name**     | `philo_bonus`                                                                                                                                                                          |
| :------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Turn in files**    | philo_bonus/ `Makefile`, `*.h`, `*.c`                                                                                                                                                  |
| **Makefile**         | `all, clean, fclean, re`                                                                                                                                                               |
| **Arguments**        | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]                                                                               |
| **External functs.** | memset, printf, malloc, free, write, fork, kill, exit, pthtread_create, pthread_detach, pthread_join, usleep, ettimeofday waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink |
| **Libft 사용여부**   | No                                                                                                                                                                                     |
| **Descriptio**       | Philosophers with processes and semaphores                                                                                                                                             |

##### _The program of the bonus part takes the ame arguments as the mandatory program. It has to comply with the requirements of the Global rules chapter._

##### _The specific rules for the bonus part are:_

- ##### _All the forks are put int the middle of the table._

- ##### _They have no states in memory but the number of available forks is represented by a semaphore._

- ##### _Each philosopher should be a process. But the main process should not be a philosopher._

> ⚠️ <br>
>
> ##### _The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
