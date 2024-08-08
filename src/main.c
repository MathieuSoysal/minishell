/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:46:57 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 16:50:06 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/executor.h"
#include "structures/commande/commande.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char const *argv[], char *envp[])
{
	char			*command_line;
	t_syntax_error	error;
	t_commande		**commands;
	int				i;

	envp = ft_copy_array(envp);
	while (1)
	{
		write(1, "minishell$ ", 11);
		command_line = ft_get_next_line(0);
		if (command_line == NULL)
			return (0);
		error = check_syntax(command_line);
		if (error != NO_ERROR)
			print_error(error);
		else
		{
			commands = parse_command_line(command_line, (char **)envp);
			i = -1;
			while (commands[++i])
				execute_command(commands[i], &envp);
			free_commands(commands);
		}
		free(command_line);
	}
	return (0);
}
