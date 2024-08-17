/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:25:55 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/17 13:43:51 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"


void exec_cmd(t_commande **commands, char ***g_env)
{
    if (!(execute_command(*commands, g_env)))
    {
        ft_putstr_fd("pipex: command not found: ", 2);
        exit(127);
    }
    
}
