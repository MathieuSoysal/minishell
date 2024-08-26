/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:07:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/19 16:25:05 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"

// void	execute_builtins_without_fork(t_commande *command, char ***g_env)
// {
// 	int	fd_in;
// 	int	fd_out;
// 	int	original_stdout;
// 	int	original_stdin;

// 	original_stdout = dup(1);
// 	original_stdin = dup(0);
// 	fd_in = command_get_fd_infile(command);
// 	fd_out = command_get_fd_outfile(command);
// 	if (fd_in != 0)
// 		dup2(fd_in, 0);
// 	if (fd_out != 1)
// 		dup2(fd_out, 1);	
// 	get_exit_status(execute_builtin(command, g_env));
// 	if (fd_in != 0)
// 		close(fd_in);
// 	if (fd_out != 1)
// 		close(fd_out);
// 	dup2(original_stdout, 1);
// 	dup2(original_stdin, 0);
// 	close(original_stdout);
// 	close(original_stdin);
// }

void ft_dup_two(t_commande *command, char *in_out, int zero_one, t_fd *fds)
{
    fds->fd_infile = command_get_fd_infile(command);
    fds->fd_outfile = command_get_fd_outfile(command);
    
    int ret;
    if(fds -> fd[1] == -1 || fds -> fd[0])
    {
        perror("fd failed on fd[0]");
    }
    if (0 == zero_one)
    {
        ret = dup2(fds -> fd[0], 0);
        if (ret == -1)
        {
            printf("fd[0] = %d\n", ret);
            perror("dup2 failed on fd[0]");
        }
        close(fds-> fd_infile);
    }
    if (1 == zero_one)
    {
        
        ret = dup2(fds -> fd[1], 1);
        if (ret == -1)
        {
             printf("fd[1] = %d\n", ret);
            perror("dup2 failed on fd[1]");
        }
        close(fds->fd_outfile);
    }
    if (!ft_strcmp(in_out, "in"))
    {
        ret = dup2(fds -> fd_infile, 0);
        if (ret == -1)
        {
            printf("fd_in =  %d\n", ret);
            perror("dup2 failed on fd_infile");
        }
        close(fds -> fd_infile);
    }
    if (!ft_strcmp(in_out, "out"))
    {
        ret = dup2(fds-> fd_outfile, 1);
        if (ret == -1)
        {
            printf("fd_out =  %d\n", ret);
            perror("dup2 failed on fd_outfile");
        }
        close(fds->fd_outfile);
    }
}

void ft_close(t_commande *command, char *fd_in_out, int fd_zero_one, t_fd *fds)
{
        command  =  NULL;
      if(fds -> fd[1] == -1 || fds -> fd[0])
    {
        perror("fd failed on fd[0]");
    }
    int ret;
    if (!ft_strcmp(fd_in_out, "in"))
    {
        ret = close(fds->fd_infile);
        if (ret == -1)
            perror("close failed on fd_infile");
    }
    if (!ft_strcmp(fd_in_out, "out"))
    {
        ret = close(fds->fd_outfile);
        if (ret == -1)
            perror("close failed on fd_outfile");
    }
    if (!ft_intcmp(fd_zero_one))
    {
        ret = close(fds->fd_infile);
        if (ret == -1)
            perror("close failed on fd[0]");
    }
    if (ft_intcmp(fd_zero_one))
    {
        ret = close(fds-> fd_infile);
        if (ret == -1)
            perror("close failed on fd[1]");
    }
}
