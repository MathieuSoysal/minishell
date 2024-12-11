/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:37:06 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/11 17:18:27 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../structures/commande/commande.h"
#include "export_internal.h"

void	export_cond_while(t_commande *cmd, char ***g_env, int i)
{
	while (cmd->args[++i])
	{
		if (is_valid_identifier(cmd->args[i]))
		{
			if (ft_strchr(cmd->args[i], '=') != NULL)
				apply_export_for_arg(cmd->args[i], g_env);
			else
			{
				if (0 == env_contains_var(*g_env, cmd->args[i]))
					env_add_var_for_export(g_env, cmd->args[i], "");
			}
		}
		else
			print_invalid_identifier_error(cmd->args[i]);
	}
}

int	export(t_commande *cmd, char ***g_env)
{
	int		i;
	bool	remove_export;

	remove_export = false;
	if (cmd->args[1] && ft_strcmp(cmd->args[1], "-n") == 0)
	{
		remove_export = true;
		i = 1;
	}
	else
		i = 0;
	if (cmd->args[i + 1] == NULL)
	{
		print_sorted_env(*g_env);
		return (0);
	}
	export_cond_while(cmd, g_env, i);
	return (0);
}
