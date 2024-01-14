/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:07:52 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/14 22:37:55 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/minitalk.h"

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error PID!\n", 12);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error PID!\n", 12);
				exit(0);
			}
		}
		c >>= 1;
		usleep(860);
		i++;
	}
}

void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send(pid, str[i]);
		i++;
	}
	ft_send(pid, '\0');
}

int	checkdigit(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	done(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Done !\n", 8);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Wrong Arguments!\n", 18);
		return (0);
	}
	if (checkdigit(argv[1]) == 1)
	{
		write(2, "Wrong PID!\n", 11);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Wrong PID!\n", 11);
		return (0);
	}
	signal(SIGUSR1, done);
	ft_send_str(pid, argv[2]);
	return (0);
}
