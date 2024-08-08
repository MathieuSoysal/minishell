/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:09:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/08 15:08:08 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../builtins.h"
#include <stdlib.h>

static void	print_error(char *arg)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

static bool	is_all_numeric(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_isalnum(arg[i]))
			return (false);
	return (true);
}

int	bultin_exit(t_commande *cmd)
{
	write(2, "exit\n", 5);
	if (cmd->args[1])
	{
		if (is_all_numeric(cmd->args[1]))
			exit(ft_atoi(cmd->args[1]));
		print_error(cmd->args[1]);
		exit(2);
	}
	exit(0);
}
