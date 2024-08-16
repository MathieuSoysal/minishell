/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:10:13 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 19:35:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "../../structures/commande/commande.h"

void	execute_external_command(t_commande *command, char ***g_env);
int		execute_builtins_without_fork(t_commande *command, char ***g_env);

#endif // INTERNAL_H
