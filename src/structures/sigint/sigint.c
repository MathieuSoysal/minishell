/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:39:00 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 05:50:46 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigint.h"
#include "../../libft/libft.h"
#include "../../minishell.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	free_env(char **env)
{
	int	i;

	i = -1;
	if (!env)
		return ;
	while (env[++i])
	{
		free(env[i]);
		env[i] = NULL;
	}
	free(env);
	env = NULL;
}

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

char	**copy_envp(char **envp)
{
	int		i;
	char	**new_envp;

	i = -1;
	while (envp[++i])
		;
	new_envp = malloc(sizeof(char *) * (i + 1));
	if (!new_envp)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		new_envp[i] = ft_strdup(envp[i]);
	}
	new_envp[i] = NULL;
	return (new_envp);
}

char	***get_envp(char **envp)
{
	static char	**envp_static;

	if (envp)
		envp_static = copy_envp(envp);
	return (&envp_static);
}
