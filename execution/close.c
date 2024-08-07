/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:07:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:20 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




void	ft_dup_two(t_pipex *pipex, char *in_out, int zero_one)
{
	if (0 == ft_intcmp(zero_one))
	{
		dup2(pipex->p_fd[0], 0);
		close(pipex->p_fd[0]);
	}
	if (1 == ft_intcmp(zero_one))
	{
		dup2(pipex->p_fd[1], 1);
		close(pipex->p_fd[1]);
	}
	if (!ft_strcmp(in_out, "in"))
	{
		dup2(pipex->fd_in, 0);
		close(pipex->fd_in);
	}
	if (!ft_strcmp(in_out, "out"))
	{
		dup2(pipex->fd_out, 1);
		close(pipex->fd_out);
	}
}

void	ft_close(t_pipex *pipex, char *fd_in_out, int fd_zero_one)
{
	if (!ft_strcmp(fd_in_out, "in"))
		close(pipex->fd_in);
	if (!ft_strcmp(fd_in_out, "out"))
		close(pipex->fd_out);
	if (!ft_intcmp(fd_zero_one))
		close(pipex->p_fd[0]);
	if (ft_intcmp(fd_zero_one))
		close(pipex->p_fd[1]);
}

