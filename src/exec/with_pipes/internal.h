/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:40:23 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/16 22:16:08 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "execution.h"

int		ft_fork(pid_t pid);
void	ft_close(t_commande *commands, char *fd_in_out, int fd_zero_one);
void	ft_pipe(t_commande *commands);

#endif // INTERNAL_H
