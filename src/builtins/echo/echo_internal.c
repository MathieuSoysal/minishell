/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_internal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:55:55 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 13:22:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/mini_libft/mini_libft.h"
#include "echo_internal.h"
#include <stdbool.h>

bool	is_option_n(char *arg)
{
	bool	is_option;
	int		i;

	i = 2;
	is_option = (ft_strncmp(arg, "-n", 2) == 0);
	while (is_option && arg[i])
	{
		if (arg[i] != 'n')
			return (false);
		i++;
	}
	return (is_option);
}

bool	has_option_n(char **args)
{
	int	i;

	i = 0;
	while (args[++i])
		if (is_option_n(args[i]))
			return (true);
	return (false);
}

static inline void	move_cell(char **array, int i)
{
	free(array[i]);
	array[i] = array[i + 1];
	while (array[++i])
		array[i] = array[i + 1];
}

void	remove_option_from_args(char **args)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		if (is_option_n(args[i]))
		{
			move_cell(args, i);
			i--;
		}
	}
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
	}
}
