/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:03:22 by wcarlos           #+#    #+#             */
/*   Updated: 2021/12/12 18:09:25 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_wait = 0;

int	checkbit(const int value, const int position)
{
	if ((value & (1 << position)) == 0)
		return (0);
	else
		return (1);
	return (-1);
}

void	goahead(int st)
{
	write(1, "Server got signal!\n", 19);
	g_wait = st;
}

void	send_sig(char ch, pid_t pid)
{
	int	i;

	i = 8;
	while (--i > -1)
	{
		g_wait = 0;
		if (checkbit(ch, i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_wait)
		{
		}
		usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	int					z;
	sigset_t			set;
	struct sigaction	act;
	pid_t				pid;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	act.sa_handler = goahead;
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (argc == 3)
	{
		pid = parsenum(argv[1]);
		z = -1;
		while (argv[2][++z])
			send_sig(argv[2][z], pid);
	}
	return (0);
}

int	parsenum(char *str)
{
	int	result;
	int	i;

	result = 0;
	if (str)
	{
		i = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
	}
	return (result);
}
