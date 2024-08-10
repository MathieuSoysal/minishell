/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:30:55 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 00:15:28 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../structures/commande/commande.h"
# include <stdbool.h>

int		execute_command(t_commande *command, char ***g_env);
bool	command_can_be_executed(t_commande *command);
bool	is_builtin(t_commande *command);
int		execute_builtin(t_commande *command, char ***g_env);

#endif // EXECUTOR_H
