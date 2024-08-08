/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:48:05 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 12:02:57 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	execute_command(t_commande *command, char ***g_env)
{
	if (is_builtin(command))
		execute_builtin(command, g_env);
}