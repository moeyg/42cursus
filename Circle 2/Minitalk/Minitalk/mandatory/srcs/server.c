/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:13:19 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/02 17:13:22 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal_num, siginfo_t *info, void *context);
static void	send_acknowledgement(int pid);

int	main(void)
{
	struct sigaction	s_sigaction;
	int					pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	s_sigaction.sa_sigaction = signal_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

static void	signal_handler(int signal_num, siginfo_t *info, void *context)
{
	static unsigned char	received_byte;
	static int				bit_count;

	(void)context;
	if (bit_count < 8)
	{
		received_byte <<= 1;
		if (signal_num == SIGUSR1)
		{
			received_byte |= 1;
		}
		bit_count++;
	}
	if (bit_count >= 8)
	{
		if (received_byte != 0)
		{
			write(1, &received_byte, 1);
		}
		else
			send_acknowledgement(info->si_pid);
		received_byte = 0;
		bit_count = 0;
	}
}

static void	send_acknowledgement(int pid)
{
	write(1, "\n", 1);
	kill(pid, SIGUSR1);
}
