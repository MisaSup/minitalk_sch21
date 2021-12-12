/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:15:20 by wcarlos           #+#    #+#             */
/*   Updated: 2021/12/12 18:15:22 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# include <signal.h>
# include <unistd.h>
# define MINITALK_H

int		parsenum(char *str);
int		checkbit(const int value, const int position);
void	todec(int *binary);
void	handler(int st, siginfo_t *siginfo, void *code);
void	ft_putnbr(long nbr, int base_len, char *base);
void	send_sig(char ch, pid_t pid);

#endif
