/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:39:00 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/30 14:19:00 by kahoumou         ###   ########.fr       */
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

void	signal_sigquit(int sig)
{
	(void)sig;
	g_sigint = SIGQUIT;
	get_exit_status(131);
	rl_replace_line("", 0);
	rl_done = 1;
}

void	signal_sigint(int sig)
{
	(void)sig;
	g_interrupt = 1;
	get_exit_status(130);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	rl_done = 0;
}

void	setup_sigint(void)
{
	struct sigaction	sa;
	struct termios		oldt;

	tcgetattr(STDIN_FILENO, &oldt);
	oldt.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	sa.sa_flags = 0;
	sa.sa_handler = signal_sigint;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = signal_sigquit;
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_interrupt_in_loop(void)
{
	char	*prompt;

	if (g_interrupt)
	{
		g_interrupt = 0;
		prompt = get_prompt();
		rl_set_prompt(prompt);
		free(prompt);
	}
}
