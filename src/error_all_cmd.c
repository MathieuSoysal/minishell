/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_all_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:07:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/12 16:55:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/all_executors/executor.h"
#include "exec/with_pipes/execution.h"
#include "exec/without_pipe/single_exec.h"
#include "minishell.h"
#include "signals/sigint/sigint.h"
#include "structures/commande/commande.h"
#include "structures/env/env.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	error_all_cmd(int status, t_commande *cmd)
{
	if (WIFEXITED(status) && g_sigint == 0)
		set_exit_status(WEXITSTATUS(status));
	if (ft_strcmp(cmd->args[0], "sleep") == 0 && status == 2)
	{
		set_exit_status(128 + WTERMSIG(status));
		handle_process_signal(status);
	}
	if (WTERMSIG(status) == SIGINT)
		set_exit_status(0);
	if (status > 10)
		set_exit_status(127);
	else if (WIFSIGNALED(status))
	{
		handle_process_signal(status);
		set_exit_status(128 + WTERMSIG(status));
	}
}
