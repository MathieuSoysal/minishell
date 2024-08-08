/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:06:20 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 12:11:22 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"
#include "../utils/utils.h"

int	unset(t_commande *cmd, char ***g_env)
{
	int	i;

	i = 0;
	while (cmd->args[++i])
		if (env_contains_var(*g_env, cmd->args[i]))
			env_remove_var(g_env, cmd->args[i]);
	return (0);
}
