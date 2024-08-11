/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_exec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:09:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/11 03:21:30 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLE_EXEC_H
# define SINGLE_EXEC_H

# include "../../structures/commande/commande.h"

void	execute_single_command(t_commande *command, char ***g_env);
bool	is_single_command(t_commande **commands);

#endif // SINGLE_EXEC_H
