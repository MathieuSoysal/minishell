/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:30:55 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 17:13:55 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_INTERNAL_H
# define EXECUTOR_INTERNAL_H

# include "../structures/commande/commande.h"
# include <stdbool.h>

bool	is_builtin(t_commande *command);
int		execute_builtin(t_commande *command, char ***g_env);
bool	all_infiles_exist(t_commande *command);
bool	all_outfiles_have_permissions(t_commande *command);
void	create_all_outfiles(t_commande *command);

#endif // EXECUTOR_INTERNAL_H
