/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signt_for_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:04:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/10 14:16:46 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../minishell.h"
#include "sigint.h"
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void	signal_command_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(130);
}

void	signal_command_sigquit(int sig)
{
	(void)sig;
	write(1, "Quit (core dumped)\n", 19);
	exit(131);
}

void	setup_command_signals(void)
{
	struct sigaction	sa;

	printf("pass\n");
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_command_sigint;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = signal_command_sigquit;
	sigaction(SIGQUIT, &sa, NULL);
}
