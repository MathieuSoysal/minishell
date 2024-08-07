/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:08:28 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:32 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void clear_all(t_pipex *pipex) {
    if (pipex->fd_in >= 0)
        close(pipex->fd_in);
    if (pipex->fd_out >= 0)
        close(pipex->fd_out);
    if (pipex->here_doc)
        unlink(HEREDOC);
}

int	ft_fork(pid_t pid)
{
	pid = fork();
	if (-1 == pid)
	{
		perror("fork");
		exit(1);
	}
	return (pid);
}
void	ft_pid(t_pipex *pipex)
{
	if (-1 == pipe(pipex->p_fd))
	{
		perror("pipe");
		exit(1);
	}
}

