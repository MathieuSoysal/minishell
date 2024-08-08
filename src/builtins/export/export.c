/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:37:06 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/08 11:52:24 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../structures/commande/commande.h"
#include "export_internal.h"

int	export(t_commande *cmd, char ***g_env)
{
	int	i;

	i = 0;
	while (cmd->args[++i])
	{
		if (is_valid_identifier(cmd->args[i]))
			apply_export_for_arg(cmd->args[i], g_env);
		else
			print_invalid_identifier_error(cmd->args[i]);
	}
	return (0);
}
