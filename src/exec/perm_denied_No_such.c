/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perm_denied_No_such.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:52:50 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/07 16:15:49 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "all_executors/executor_internal.h"
#include <unistd.h>

bool	permisson_denied(t_infile *infile)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(infile->value.file_name_value, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (false);
}

bool	no_such_file_or_directory(t_infile *infile)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(infile->value.file_name_value, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (false);
}
