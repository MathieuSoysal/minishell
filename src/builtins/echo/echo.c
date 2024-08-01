/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:40:20 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:00:11 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int check_args(t_cmd  *cmd)
{
        if(!cmd ->arg)
        {
            ft_putstr_fd("\n", cmd-> fd_out);
            return(0);
            
        }
        else
        {
            ft_putstr_fd(cmd -> arg, cmd -> fd_out);
            return(1);
        }
        return(0);     
}

int check_flag(t_cmd  *cmd)
{
        if(!cmd ->flags) 
        {
            ft_putstr_fd("\n", cmd -> fd_out);
            return(0);
        }
        return(1);
}

int echo(t_cmd *cmd)
{
    if(false ==  check_args(cmd))
    {
        return(0);
    }
    if(false ==  check_flag(cmd))
    {
        return(0);
    }
    return(0);             
}

