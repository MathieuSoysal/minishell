/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:39:00 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 19:12:06 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigint.h"
#include "../../libft/libft.h"
#include "../../minishell.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	signal_handler_wrapper(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGINT)
	{
		get_exit_status(_EXIT_QUIT);
		write(1, "\n", 1);
		prompt();
	}
}

void	setup_sigint(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler_wrapper;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
