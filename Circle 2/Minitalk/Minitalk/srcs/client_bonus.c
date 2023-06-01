/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:31:57 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/02 02:33:41 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void receive_acknowledgement(int signal_number);
static void	send_message(int pid, char *message);
static void	send_termination_signal(int pid);
static void	send_signal(int pid, int bit);

int main(int argc, char *argv[])
{
    int pid;

	signal(SIGUSR1, receive_acknowledgement);
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ", 1);
		write(1, argv[0], ft_strlen(argv[0]));
		ft_putstr_fd(" PID MESSAGE\n", 1);
		exit(0);
	}
    pid = ft_atoi(argv[1]);
	if (pid <= 100 || pid > 99999)
	{
		ft_putstr_fd("PID must be in the range of 101 to 99999\n", 1);
		exit(0);
	}
	send_message(pid, argv[2]);
	sleep(1);
	ft_putstr_fd("Timeout over 1 second\n", 1);
	return (0);
}

static void receive_acknowledgement(int signal_number)
{
    if (signal_number == SIGUSR1)
    {
        ft_putstr_fd("ACK REVEICED!\n", 1);
    }
    exit(0);
}

static void	send_message(int pid, char *message)
{
    unsigned char   bit_mask;

    while (*message)
    {
        bit_mask = 0x80;
        while(bit_mask)
        {
            send_signal(pid, bit_mask & *message);
            bit_mask >>= 1;
            usleep(100);
        }
        message++;
    }
    send_termination_signal(pid);
}

static void	send_termination_signal(int pid)
{
	unsigned char	bit_position;

	bit_position = 0x80;
	while (bit_position)
	{
		send_signal(pid, 0);
		bit_position >>= 1;
		usleep(100);
	}
}

static void	send_signal(int pid, int bit)
{
	if (bit)
    {
		kill(pid, SIGUSR1);
    }
	else
    {
		kill(pid, SIGUSR2);
    }
}