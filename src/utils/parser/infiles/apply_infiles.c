/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_infiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:46:58 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/14 07:49:56 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../here_doc/here_doc.h"
#include "../internal_parser.h"
#include "apply_infiles.h"
#include <stdlib.h>

static inline void	move_cell_i_to_last(char **array, int i)
{
	free(array[i]);
	array[i] = array[i + 1];
	while (array[++i])
		array[i] = array[i + 1];
}

int	apply_infiles(char **command_line, int i, t_double_linked_list *infiles)
{
	int	fd;

	if (equals(command_line[i], "<<"))
	{
		fd = heredoc(command_line[i + 1]);
		if (fd == -1)
			return (-1);
		double_linked_list_add_last(infiles, create_infile_with_fd(fd));
	}
	else
		double_linked_list_add_last(infiles,
			create_infile_with_filename(command_line[i + 1]));
	move_cell_i_to_last(command_line, i);
	move_cell_i_to_last(command_line, i);
	return (0);
}

t_infile	**extract_infiles(char **command_line)
{
	int						i;
	t_double_linked_list	*infiles;

	i = 0;
	infiles = double_linked_list_create();
	while (command_line[i])
	{
		if (equals(command_line[i], "<") || equals(command_line[i], "<<"))
		{
			if (apply_infiles(command_line, i, infiles) == -1)
			{
				double_linked_list_free(infiles, (void *)free_infile);
				return (NULL);
			}
		}
		else
			i++;
	}
	if (infiles->size == 0)
		return (free(infiles), NULL);
	return (double_linked_list_to_array_infiles(infiles));
}

bool	has_infiles(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], "<"))
			return (true);
		i++;
	}
	return (false);
}

bool	has_heredoc(char **command_line)
{
	int	i;

	i = 0;
	while (command_line[i])
	{
		if (equals(command_line[i], "<<"))
			return (true);
		i++;
	}
	return (false);
}
