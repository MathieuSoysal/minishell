/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:22:32 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/10 11:15:58 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../structures/commande/commande.h"
# include <readline/readline.h>
int	echo(t_commande *cmd);
int	cd(t_commande *cmd, char **envp);
int	export(t_commande *cmd, char ***g_env);
int	unset(t_commande *cmd, char ***g_env);
int	env(t_commande *cmd, char **envp);
int	pwd(t_commande *cmd);
int	bultin_exit(t_commande *cmd, char ***g_env);
#endif
