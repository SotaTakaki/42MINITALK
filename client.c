/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:02:24 by stakaki           #+#    #+#             */
/*   Updated: 2021/07/16 22:04:17 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
int		ft_atoi(char *str);
char	*decimal_to_binary(int decimal_num);
void	signal_to_server(char *binary_num, pid_t pid);

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;
	int		decimal_num;
	char	*binary_num;

	pid = ft_atoi(argv[1]);
	i = 0;
	binary_num = NULL;
	if (pid < 100 || pid > 99998)
		kill(pid, 0);
	while (argv[2][i] != '\0')
	{
		decimal_num = argv[2][i];
		binary_num = decimal_to_binary(decimal_num);
		signal_to_server(binary_num, pid);
		i++;
	}
	return (0);
}

char	*decimal_to_binary(int decimal_num)
{
	int		i;
	char	*binary_num;

	i = 6;
	binary_num = (char *)malloc(8);
	binary_num[7] = '\0';
	while (decimal_num > 0)
	{
		if (decimal_num % 2 == 1)
			binary_num[i] = '1';
		else
			binary_num[i] = '0';
		decimal_num /= 2;
		i--;
	}
	while (i >= 0)
	{
		binary_num[i] = '0';
		i--;
	}
	return (binary_num);
}

void	signal_to_server(char *binary_num, pid_t pid)
{
	int	i;

	i = 0;
	while (binary_num[i] != '\0')
	{
		usleep(50);
		if (binary_num[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	answer;

	i = 0;
	answer = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		answer = answer * 10;
		answer += str[i] - '0';
		i++;
	}
	return (answer);
}
