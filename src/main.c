/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:46:57 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/03 14:32:25 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/executor.h"
#include "structures/commande/commande.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <stdlib.h>
#include <unistd.h>

void	execute_command(t_commande *command, char **envp)
{
	if (is_builtin(command))
		execute_builtin(command, envp);
	else
		execute_external(command, envp);
}

int	main(int argc, char const *argv[], char const *envp[])
{
	char			*command_line;
	t_syntax_error	error;
	t_commande		**commands;
	int				i;

	while (1)
	{
		write(1, "minishell$ ", 11);
		command_line = ft_get_next_line(0);
		error = check_syntax(command_line);
		if (error != NO_ERROR)
			print_error(error);
		else if (command_line == NULL)
			return (0);
		else
		{
			commands = parse_command_line(command_line, (char **)envp);
			i = -1;
			while (commands[++i])
				print_commande(commands[i]);
			free_commands(commands);
		}
		free(command_line);
	}
	return (0);
}
