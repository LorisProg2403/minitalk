/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:02:17 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/22 14:23:17 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit = -1;
	static unsigned char	c;
	
	if (bit < 0)
		bit = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0 && c)
	{
		ft_printf("%c", c);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Server failed to send SIGUSR1");
}

static void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Sigaction for SIGUSR2 failed");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Sigaction for SIGUSR2 failed");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n", pid);
	while (1)
		config_signals();
	return (0);
}
