/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:09:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/24 13:50:28 by kahoumou         ###   ########.fr       */
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
	int	i;

	i = 0;
	if (!arg || !*arg)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		if (i > 20)
			return (false);
		arg++;
		i++;
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
	if (cmd->args[1] && cmd->args[2] != 0)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd("too many arguments\n", 2);
		get_exit_status(1);
	}
	if (cmd->args[1] && !cmd->args[2])
	{
		if (ft_atoi(cmd->args[1]) > 255)
			get_exit_status(0);
		if (is_numeric_argument(cmd->args[1]))
			get_exit_status(ft_atoi(cmd->args[1]));
		else
		{
			print_error(cmd->args[1]);
			get_exit_status(2);
		}
	}
	write(2, "exit\n", 5);
	free_all_resources(NULL);
	close_all_fds();
	commande_free(cmd);
	exit(get_exit_status(_LAST_STATUS));
}
