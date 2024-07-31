/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_outfiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:08:14 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 10:02:40 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_outfiles.h"
#include "../internal_parser.h"
#include <stdlib.h>

static inline void	move_cell_i_to_last(char **array, int i)
{
	free(array[i]);
	array[i] = array[i + 1];
	while (array[++i])
		array[i] = array[i + 1];
}

char	**extract_outfiles(char **command_line)
{
	int						i;
	t_double_linked_list	*outfiles;

	i = 0;
	outfiles = double_linked_list_create();
	while (command_line[i])
	{
		if (equals(command_line[i], ">") || equals(command_line[i], ">>"))
		{
			double_linked_list_add_last(outfiles, apply_strings(command_line[i
					+ 1]));
			move_cell_i_to_last(command_line, i);
			move_cell_i_to_last(command_line, i);
		}
		else
			i++;
	}
	return (double_linked_list_to_array(outfiles));
}

bool	has_outfiles(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], ">") || equals(command_line[i], ">>"))
			return (true);
		i++;
	}
	return (false);
}

bool	has_outfiles_append(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], ">>"))
			return (true);
		i++;
	}
	return (false);
}
