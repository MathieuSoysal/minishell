/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:52:34 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 18:28:07 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"


void	execute_external(t_commande *command, char **envp)
{
    char *temp = get_path(command->name, envp);
    free(command->name);
    command->name = temp;
    if (execve(command->name, command->args, envp) == -1)
    {
        ft_putstr_fd(command->name, 2);
        ft_putstr_fd(": command not found\n", 2);
        commande_free(command);
        exit(127);
    }
}