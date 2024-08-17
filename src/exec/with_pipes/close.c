/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:07:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/16 21:46:35 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"

void	ft_dup_two(t_commande *commands, char *in_out, int zero_one)
{
	if (0 == ft_intcmp(zero_one))
	{
		dup2(commands->fd[0], 0);
		close(commands->fd[0]);
	}
	if (1 == ft_intcmp(zero_one))
	{
		dup2(commands->fd[1], 1);
		close(commands->fd[1]);
	}
	if (!ft_strcmp(in_out, "in"))
	{
		dup2(commands->fd_infile, 0);
		close(commands->fd_outfile);
	}
	if (!ft_strcmp(in_out, "out"))
	{
		dup2(commands->fd_outfile, 1);
		close(commands->fd_outfile);
	}
}

void	ft_close(t_commande *command, char *fd_in_out, int fd_zero_one)
{
	if (!ft_strcmp(fd_in_out, "in"))
		close(command->fd_infile);
	if (!ft_strcmp(fd_in_out, "out"))
		close(command->fd_outfile);
	if (!ft_intcmp(fd_zero_one))
		close(command->fd[0]);
	if (ft_intcmp(fd_zero_one))
		close(command->fd[1]);
}
