/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:30:55 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/07 19:28:46 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../structures/commande/commande.h"
# include <stdbool.h>

void	execute_command(t_commande *command, char **envp);
bool	is_builtin(t_commande *command);
void	execute_builtin(t_commande *command, char **envp);
void	execute_external(t_commande *command, char **envp);

#endif // EXECUTOR_H
