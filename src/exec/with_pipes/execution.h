/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:11:16 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/17 13:43:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

#include<unistd.h>
#include <sys/types.h>
#include "../../structures/commande/commande.h"
#include "../without_pipe/single_exec.h"
#include "../all_executors/executor.h"
#include "../../libft/libft.h"

void	execute_commands(t_commande **command, char **g_env);
void	process_commands(t_commande  *commands, char ***envp);
void exec_cmd(t_commande **commands, char ***g_env);
void	ft_dup_two(t_commande *commands, char *in_out, int zero_one);
int	ft_fork(pid_t pid);
void clear_all(t_commande *commands);
void	ft_pid(t_commande *commands);
void	ft_close(t_commande *commands, char *fd_in_out, int fd_zero_one);


#endif // EXECUTION_H
