/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:25:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/18 12:12:35 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "execution.h"

char	*build_error_message(char *command_name)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin("minishell: ", command_name);
	result = ft_strjoin(tmp, ": command not found\n");
	free(tmp);
	return (result);
}

void	exec_cmd(t_commande **commands, t_commande *command, char ***g_env)
{
	int		status;
	char	*print;
	
	status = execute_command(command, g_env);
	if (status == -1)
	{
		
		print = build_error_message(command->name);
		ft_putstr_fd(print, 2);
		free(print);
		free_commands(commands);
		free_env(*g_env);
		exit(127);
	}
	free_commands(commands);
	free_env(*g_env);
	exit(1);
}

void	ft_exec(t_commande **commands, int i, char ***envp)
{
	
	exec_cmd(commands, commands[i], envp);
	exit(EXIT_FAILURE);

}
