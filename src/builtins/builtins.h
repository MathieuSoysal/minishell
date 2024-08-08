/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:22:32 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/08 12:02:13 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../structures/commande/commande.h"

int	echo(t_commande *cmd);
int	cd(t_commande *cmd, char **envp);
int	export(t_commande *cmd, char ***g_env);
int	unset(t_commande *cmd, char ***g_env);
int	env(t_commande *cmd, char **envp);

#endif
