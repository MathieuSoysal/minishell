/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:09:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/10 11:16:45 by kahoumou         ###   ########.fr       */
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

// void	close_all_file_descriptors(t_fd *fds)
// {
// 	if (fds->fd_infile > 0)
// 		close(fds->fd_infile);
// 	if (fds->fd_outfile > 0)
// 		close(fds->fd_outfile);
// 	if (fds->fd[0] > 0)
// 		close(fds->fd[0]);
// 	if (fds->fd[1] > 0)
// 		close(fds->fd[1]);
// }

// static void	print_error(char *arg)
// {
// 	ft_putstr_fd("exit: ", 2);
// 	ft_putstr_fd(arg, 2);
// 	ft_putstr_fd(": numeric argument required\n", 2);
// }

// static bool	is_all_numeric(char *arg)
// {
// 	int	i;

// 	i = -1;
// 	while (arg[++i])
// 		if (!ft_isalnum(arg[i]))
// 			return (false);
// 	return (true);
// }

// // int	bultin_exit(t_commande *cmd)
// // {
// // 	write(2, "exit\n", 5);
// // 	if (cmd->args[1])
// // 	{
// // 		if (is_all_numeric(cmd->args[1]))
// // 			exit(ft_atoi(cmd->args[1]));
// // 		print_error(cmd->args[1]);
// // 		exit(2);
// // 	}
// // 	free_env(NULL);
// // 	exit(get_exit_status(_LAST_STATUS));
// // }

static void	free_out_f(t_outfile **outfiles)
{
	int	i;

	i = -1;
	if (outfiles == NULL)
		return ;
	while (outfiles[++i])
	{
		free(outfiles[i]->file_name);
		outfiles[i]->file_name = NULL;
		free(outfiles[i]);
		outfiles[i] = NULL;
	}
}

static void	free_str(char **strings)
{
	int	i;

	i = -1;
	if (strings == NULL)
		return ;
	while (strings[++i])
	{
		free(strings[i]);
		strings[i] = NULL;
	}
}

void	free_cmds(t_commande *commande)
{
	if (commande == NULL)
		return ;
	free_str(commande->args);
	free(commande->args);
	commande->args = NULL;
	if (commande->name != NULL)
		free(commande->name);
	commande->name = NULL;
	free_infiles(commande->infiles);
	commande->infiles = NULL;
	free_out_f(commande->outfiles);
	free(commande->outfiles);
	commande->outfiles = NULL;
	free(commande->path);
	commande->path = NULL;
	free(commande);
	commande = NULL;
}

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
	for (int fd = 3; fd < 1024; fd++)
		close(fd);
}

static void	free_all_resources(t_commande **commands)
{
	if (commands)
		free_commands(commands);
	free_env(NULL);
}

int	bultin_exit(t_commande *cmd, char ***g_env)
{
	int	exit_code;

	(void)g_env;
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
