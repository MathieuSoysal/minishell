/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:57:30 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 00:03:11 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "executor_internal.h"
#include <unistd.h>

bool	all_infiles_exist(t_commande *command)
{
	int			i;
	t_infile	*infile;

	i = 0;
	if (command->infiles == NULL)
		return (true);
	while (command->infiles[i])
	{
		infile = command->infiles[i];
		if (infile->type == INFILE_TYPE_STRING
			&& access(infile->value.file_name_value, F_OK) == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(infile->value.file_name_value, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	all_outfiles_have_permissions(t_commande *command)
{
	int	i;

	i = 0;
	if (command->outfile_names == NULL)
		return (true);
	while (command->outfile_names[i])
	{
		if (access(command->outfile_names[i], F_OK) != -1
			&& access(command->outfile_names[i], W_OK) == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(command->outfile_names[i], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

void	create_all_outfiles(t_commande *command)
{
	int	i;

	i = 0;
	if (command->outfile_names == NULL)
		return ;
	while (command->outfile_names[i])
	{
		if (access(command->outfile_names[i], F_OK) == -1)
			open(command->outfile_names[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		i++;
	}
}
