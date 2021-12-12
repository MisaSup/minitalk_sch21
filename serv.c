/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:14:13 by wcarlos           #+#    #+#             */
/*   Updated: 2021/12/12 18:14:52 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_buf[8];

void	todec(int *binary)
{
	int		set;
	char	res;
	int		i;

	set = 128;
	res = 0;
	i = 0;
	while (set >= 1)
	{
		res += *(binary + i) * set;
		set /= 2;
		i++;
	}
	write(1, &res, 1);
}

void	handler(int st, siginfo_t *siginfo, void *code)
{
	static int	i = 0;

	(void)code;
	kill(siginfo->si_pid, st);
	g_buf[i] = st & 1;
	i++;
	if (i & 8)
	{
		i = 0;
		todec(g_buf);
	}
}

void	ft_putnbr(long nbr, int base_len, char *base)
{
	if (nbr >= base_len)
		ft_putnbr(nbr / base_len, base_len, base);
	write(1, &base[nbr % base_len], 1);
}

int	main(void)
{
	sigset_t			set;
	struct sigaction	act;

	ft_putnbr(getpid(), 10, "0123456789");
	write(1, "\n", 1);
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
	}
	return (0);
}
