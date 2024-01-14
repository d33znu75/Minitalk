/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:07:50 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/14 13:53:47 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/minitalk.h"

void	ft_print(int sig, siginfo_t *info, void *contx)
{
	static int	i;
	static char	c;
	static int	old;

	(void)contx;
	if (old != info->si_pid)
	{
		old = info->si_pid;
		i = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
			kill(info->si_pid, SIGUSR1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	write(1, "███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n\
████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n\
██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n\
██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n\
██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n\
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n", 929);
	write(1, "\t࿇ ══━━━━━━━━━━✥  Bonus Part  ✥━━━━━━━━━━══ ࿇\n", 103);
	write(1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "					by : rhmimchi\n\n", 20);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_print;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
