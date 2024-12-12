/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_all_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:07:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/12 12:11:32 by kahoumou         ###   ########.fr       */
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

void	error_all_cmd(int status)
{
	if (WIFEXITED(status) && g_sigint == 0)
	{
	
		set_exit_status(WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
	{
		
			
		if (WTERMSIG(status) == SIGINT)
			set_exit_status(0);
		else
		{
			handle_process_signal(status);
			set_exit_status(128 + WTERMSIG(status));
		}
	}
}
