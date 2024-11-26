/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:09:48 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/26 14:27:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../../utils/mini_libft/mini_libft.h"
#include "single_exec.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void manage_redirections(t_commande *command, t_commande **commands, char ***g_env)
{
    handle_input_redirection(command, commands, g_env);
    handle_output_redirection(command, commands, g_env);
}

void handle_input_redirection(t_commande *command, t_commande **commands, char ***g_env)
{
    if (command_get_fd_infile(command) != 0)
    {
        if (dup2(command_get_fd_infile(command), 0) == -1)
        {
            print_redirection_error(command->args[0]);
            free_commands(commands);
            free_env(*g_env);
            exit(1);
        }
    }
}

void handle_output_redirection(t_commande *command, t_commande **commands, char ***g_env)
{
    if (command_get_fd_outfile(command) != 1)
    {
        if (dup2(command_get_fd_outfile(command), 1) == -1)
        {
            print_redirection_error(command->args[0]);
            free_commands(commands);
            free_env(*g_env);
            exit(1);
        }
    }
}

void handle_execve_failure(t_commande **commands, t_commande *command, char ***g_env)
{
    (void)g_env;
    ft_putstr_fd("minishell: ", 2);
    ft_putstr_fd(command->args[0], 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(strerror(errno), 2);
    ft_putstr_fd("\n", 2);
    free_commands(commands);
    if (errno == EACCES)
        exit(126);
    else if (errno == ENOENT)
        exit(127);
    else
        exit(1);
}
void execute_external_command_bis(t_commande **commands, t_commande *command, char ***g_env)
{
    int status;

    manage_redirections(command, commands, g_env);

    status = execve(command->path, command->args, *g_env);
    free_env(*g_env);
    if (status == -1)
        handle_execve_failure(commands, command, g_env);

    free_commands(commands);
    free_env(*g_env);
    exit(status);
}

          
void print_redirection_error(char *cmd_name)
{
    ft_putstr_fd("minishell: ", 2);
    ft_putstr_fd(cmd_name, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(strerror(errno), 2);
    ft_putstr_fd("\n", 2);
}


void handle_wait(pid_t pid)
{
    int status;
    pid_t result;
    while (1)
    {
        result = waitpid(pid, &status, 0);
        if (result == -1)
        {
            if (errno == EINTR)
                continue;
            perror("waitpid failed");
            set_exit_status(1);
            return;
        }
        break;
    }
    if (WIFEXITED(status) && g_sigint == 0)
        set_exit_status(WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        set_exit_status(128 + WTERMSIG(status));
}

void handle_fork_error(void)
{
    ft_putstr_fd("minishell: fork failed\n", 2);
    set_exit_status(_EXIT_FORK);
}

void execute_external_command(t_commande **commands, t_commande *command, char ***g_env)
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
        execute_external_command_bis(commands, command, g_env);
    else if (pid > 0)
        handle_wait(pid);
    else
        handle_fork_error();
}



