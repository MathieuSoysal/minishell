/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:40:20 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/04 15:21:32 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../structures/commande/commande.h"
#include "echo_internal.h"
#include <unistd.h>

int	echo(t_commande *cmd)
{
	bool	option_n;
	
	option_n = has_option_n(cmd->args);
	if (option_n)
		remove_option_from_args(cmd->args);
	if(cmd->args[1])
			print_args(cmd->args);
	if (!option_n)
		write(1, "\n", 1);
	return (0);
}
