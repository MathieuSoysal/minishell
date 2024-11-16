/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:39:00 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/14 07:09:09 by hsoysal          ###   ########.fr       */
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
	rl_on_new_line();
	rl_redisplay();
	close(0);
}

void	signal_sigint(int sig)
{
	char	*prompt;

	(void)sig;
	get_exit_status(130);
	prompt = get_prompt();
	rl_set_prompt(prompt);
	rl_replace_line("", 0);
	write(1, "\n", 1);
	free(prompt);
	rl_on_new_line();
	rl_redisplay();
	get_exit_status(130);
	g_sigint = SIGINT;
}

void	signal_handler_wrapper(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGQUIT)
		signal_sigquit(sig);
	else if (sig == SIGINT)
		signal_sigint(sig);
}

void	setup_sigint(void)
{
	struct sigaction	sa;
	struct termios		oldt;

	tcgetattr(STDIN_FILENO, &oldt);
	oldt.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	sa.sa_flags = 0;
	sa.sa_sigaction = signal_handler_wrapper;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	signal(SIGINT, signal_sigint);
}
