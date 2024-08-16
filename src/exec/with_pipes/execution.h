/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:11:16 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 22:43:46 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../../structures/commande/commande.h"
# include "../all_executors/executor.h"
# include "../without_pipe/single_exec.h"
# include <sys/types.h>
# include <unistd.h>

void	process_commands(t_commande **commands, char ***envp);
void	exec_cmd(t_commande *commands, char ***g_env);
void	ft_dup_two(t_commande *commands, char *in_out, int zero_one);

#endif // EXECUTION_H
