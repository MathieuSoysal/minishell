/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:09:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/11 17:12:17 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exec/with_pipes/execution.h"
#include "../../libft/libft.h"
#include "../../minishell.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../builtins.h"
#include <stdlib.h>
#include <unistd.h>

static void	print_error(char *arg)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static bool	is_numeric_argument(const char *arg)
{
	if (!arg || !*arg)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		arg++;
	}
	return (true);
}

static void	close_all_fds(void)
{
	int	fd;

	fd = 3;
	while (fd < 1024)
	{
		close(fd);
		fd++;
	}
}

static void	free_all_resources(t_commande **commands)
{
	if (commands)
		free_commands(commands);
	free_env(NULL);
}

int	bultin_exit(t_commande *cmd)
{
	int	exit_code;

	write(2, "exit\n", 5);
	if (cmd->args[1])
	{
		if (is_numeric_argument(cmd->args[1]))
		{
			exit_code = ft_atoi(cmd->args[1]);
			free_all_resources(NULL);
			close_all_fds();
			free_cmds(cmd);
		}
		else
		{
			print_error(cmd->args[1]);
			free_all_resources(NULL);
			close_all_fds();
			free_cmds(cmd);
			exit(2);
		}
	}
	free_all_resources(NULL);
	close_all_fds();
	free_cmds(cmd);
	exit(get_exit_status(_LAST_STATUS));
}
