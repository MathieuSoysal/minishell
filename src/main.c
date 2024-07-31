/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:46:57 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 18:33:30 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures/commande/commande.h"
#include "utils/checker/checker.h"
#include "utils/mini_libft/mini_libft.h"
#include "utils/parser/parser.h"
#include <stdlib.h>
#include <unistd.h>

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
		else
		{
			commands = parse_command_line(command_line, (char **)envp);
			if (!commands)
				return (1);
			i = 0;
			while (commands[i])
			{
				print_commande(commands[i]);
				commande_free(commands[i]);
				i++;
			}
			free(commands);
			commands = NULL;
		}
		free(command_line);
		command_line = NULL;
	}
	return (0);
}
