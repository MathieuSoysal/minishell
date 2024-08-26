/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:35:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/26 15:08:38 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "execution.h"
#include "internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	dup_two_infile(int infile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2 failed for infile");
		exit(EXIT_FAILURE);
	}
	close(infile);
}

// void	dup_two_outfile(int outfile)
// {
// 	if (dup2(outfile, STDOUT_FILENO) == -1)
// 	{
// 		perror("dup2 failed for outfile");
// 		exit(EXIT_FAILURE);
// 	}
// 	close(outfile);
// }

void dup_two_outfile(int outfile)
{
    printf("dup_two_outfile: outfile = %d\n", outfile);
    if (outfile < 0)
    {
        perror("Invalid outfile descriptor");
        exit(EXIT_FAILURE);
    }

    if (dup2(outfile, STDOUT_FILENO) == -1)
    {
        perror("dup2 failed for outfile");
        exit(EXIT_FAILURE);
    }
    printf("dup_two_outfile: stdout redirigé vers outfile = %d\n", outfile);
    close(outfile);
}
void	dup_fd_one(int *fd)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed for fd[1]");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
}

void	pipe_fd(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
}


void ft_exec(t_commande **commands, int i, char ***envp)
{
    printf("ft_exec: executing command %d\n", i);
    // Vérification avant exec_cmd
    printf("Verifying redirections before exec_cmd...\n");
    exec_cmd(commands[i], envp);
    perror("exec_cmd failed");
    exit(EXIT_FAILURE);
}

// void	ft_exec(t_commande **commands, int i, char ***envp)
// {
// 	exec_cmd(commands[i], envp);
// 	perror("exec_cmd failed");
// 	exit(EXIT_FAILURE);
// }


void	ft_perror_fork(void)
{
	perror("fork failed");
	exit(EXIT_FAILURE);
}

void child_process(int infile, int outfile, int i, t_commande **commands, int *fd)
{
    printf("child_process: command %d\n", i);
    if (i > 0)
    {
        dup_two_infile(infile);
        printf("Redirection of stdin done for command %d\n", i);
    }

    if (commands[i + 1] != NULL)
    {
        dup_fd_one(fd);
        printf("Redirection of stdout to pipe done for command %d\n", i);
    }
    else
    {
        printf("outfile check for command %d: %d\n", i, outfile);
        if (outfile != -1 && outfile != STDOUT_FILENO)
        {
            dup_two_outfile(outfile);
            printf("Redirection of stdout to outfile done for command %d\n", i);
        }
        else
        {
            printf("No outfile redirection needed for command %d\n", i);
        }
    }

    if (commands[i + 1] != NULL)
    {
        close(fd[0]);
    }
}

// void	child_process(int infile, int outfile, int i, t_commande **commands,
// 		int *fd)
// {
// 	if (i > 0)
// 		dup_two_infile(infile);
// 	if (commands[i + 1] != NULL)
// 	{
// 		dup_fd_one(fd);
// 	}
// 	else if (outfile != -1 && outfile != STDOUT_FILENO)
// 	{
// 		dup_two_outfile(outfile);
// 	}
// 	if (commands[i + 1] != NULL)
// 	{
// 		close(fd[0]);
// 	}
// }

void	else_if_in_child_process(int *infile, t_commande **commands, int i,
		int *fd)
{
	if (*infile > 0)
	{
		close(*infile);
	}
	if (commands[i + 1] != NULL)
	{
		close(fd[1]);
		*infile = fd[0];
	}
}

void	ft_final_close(t_commande **commands, int i, int *fd)
{
	if (commands[i + 1] != NULL)
	{
		close(fd[0]);
	}
}
void	outfile_fcnlt(int outfile, t_fd *fds)
{
	outfile = fcntl(fds->fd_outfile, F_DUPFD, 10);
	if (outfile == -1)
	{
		perror("dup failed for outfile");
		exit(EXIT_FAILURE);
	}
	close(fds->fd_outfile);
}

void	process_commands(t_commande **commands, char ***envp, t_fd *fds)
{
	printf("pass in process_commands\n");
	pid_t	pid;
	int		fd[2];

	int i = 0;
	int infile = fds->fd_infile = command_get_fd_infile(*commands);
	int outfile = fds->fd_outfile = command_get_fd_outfile(*commands);
	// int infile = fds->fd_infile =  command_get_fd_infile(*commands);
	// int outfile = open("f1", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds->fd_outfile != STDOUT_FILENO)
		outfile_fcnlt(outfile, fds);
	else
		outfile = fds->fd_outfile;
	while (commands[i] != NULL)
	{
		if (commands[i + 1] != NULL)
			pipe_fd(fd);
		pid = fork();
		if (pid == 0)
		{
			child_process(infile, outfile, i, commands, fd);
			ft_exec(commands, i, envp);
		}
		else if (pid > 0)
			else_if_in_child_process(&infile, commands, i, fd);
		else
			ft_perror_fork();
		i++;
	}
	ft_final_close(commands, i, fd);
}


// void process_commands(t_commande **commands, char ***envp, t_fd *fds)
// {
//     pid_t pid;
//     int fd[2];
//     int i = 0;
//     int infile = fds->fd_infile;
//     int outfile;

//     // Configure outfile ici pour rediriger vers "f1"
//     outfile = open("f1", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (outfile == -1)
//     {
//         perror("open failed for outfile");
//         exit(EXIT_FAILURE);
//     }

//     printf("Initial infile: %d, outfile: %d\n", infile, outfile);

//     while (commands[i] != NULL)
//     {
//         if (commands[i + 1] != NULL)
//             pipe_fd(fd);

//         pid = fork();
//         if (pid == 0)
//         {
//             child_process(infile, outfile, i, commands, fd);
//             ft_exec(commands, i, envp);
//         }
//         else if (pid > 0)
//         {
//             else_if_in_child_process(&infile, commands, i, fd);
//         }
//         else
//         {
//             ft_perror_fork();
//         }
//         i++;
//     }
//     ft_final_close(commands, i, fd);
// }