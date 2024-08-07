/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:40:20 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 19:18:14 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"
#include "../../structures/commande/commande.h"

int	check_args(t_commande *cmd)
{
	if (!cmd->args[1])
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd(cmd->args[1], 1);
		return (1);
	}
	return (0);
}

int	check_flag(t_commande *cmd)
{
	//TODO 
	return (1);
}

int	echo(t_commande *cmd)
{
	if (false == check_args(cmd))
	{
		return (0);
	}
	if (false == check_flag(cmd))
	{
		return (0);
	}
	return (0);
}
