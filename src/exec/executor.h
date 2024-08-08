/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:30:55 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 12:52:10 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../structures/commande/commande.h"
# include <stdbool.h>

void	execute_command(t_commande *command, char ***g_env);
bool	is_builtin(t_commande *command);
void	execute_builtin(t_commande *command, char ***g_env);
void	execute_external(t_commande *command, char **envp);

#endif // EXECUTOR_H
