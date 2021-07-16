/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:42:15 by stakaki           #+#    #+#             */
/*   Updated: 2021/07/16 22:12:37 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void	my_handler(int sigsum);
void	put_pid(void);
void	put_message(void);

static int	g_count;
static int	g_binary_num;

int	main(void)
{
	put_pid();
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
	{
		if (g_count == 7)
			put_message();
	}
	return (0);
}

void	my_handler(int sigsum)
{
	if (sigsum == SIGUSR1)
	{
		g_binary_num = g_binary_num * 10 + 1;
		g_count++;
	}
	else if (sigsum == SIGUSR2)
	{
		g_binary_num *= 10;
		g_count++;
	}
}

void	put_pid(void)
{
	pid_t	i_pid;
	pid_t	tmp;
	int		digits;
	char	*c_pid;

	i_pid = getpid();
	tmp = i_pid;
	digits = 0;
	while (tmp != 0)
	{
		tmp /= 10;
		digits++;
	}
	c_pid = (char *)malloc(digits + 1);
	c_pid[digits] = '\0';
	digits--;
	while (i_pid != 0)
	{
		c_pid[digits] = i_pid % 10 + '0';
		i_pid /= 10;
		digits--;
	}
	write(1, c_pid, 5);
	write(1, "\n", 1);
}

void	put_message(void)
{
	int	decimal_num;
	int	base;

	decimal_num = 0;
	base = 1;
	while (g_binary_num > 0)
	{
		decimal_num = decimal_num + (g_binary_num % 10) * base;
		g_binary_num /= 10;
		base *= 2;
	}
	write(1, &decimal_num, 1);
	g_count = 0;
	g_binary_num = 0;
	decimal_num = 0;
	base = 1;
}
