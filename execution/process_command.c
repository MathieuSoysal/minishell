/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:35:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	process_commands(char **av, t_pipex *pipex)
{
	pid_t	pid;
	int		i;

	pid = -1;
	i = op_ternary(pipex->here_doc, 3, 2);
	while (i < (op_ternary(pipex->here_doc, 4, av[i + 1] != NULL)))
	{
		ft_pid(pipex);
		if (0 == ft_fork(pid))
		{
			if (i != (op_ternary(pipex->here_doc, 3, 2)))
				ft_dup_two(pipex, "in", -1);
			if (NULL != av[i + 1])
				ft_dup_two(pipex, "no", 1);
			ft_close(pipex, "out", 0);
			exec_cmd(av[i], pipex);
		}
		ft_close(pipex, "in", 1);
		waitpid(pid, NULL, 0);
		pipex->fd_in = pipex->p_fd[0];
		i++;
	}
	ft_dup_two(pipex, "in", -1);
	ft_dup_two(pipex, "out", -1);
	exec_cmd(av[i], pipex);
}
