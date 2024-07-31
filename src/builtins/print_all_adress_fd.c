/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_adress_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:19:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/31 13:29:09 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"



t_variables  *my_first_variable(t_adress  *env)
{
    if(env -> variable)
        return(env -> variable);
            return(NULL);
}

void print_env_var_fd(t_variables  *var, int fd)
{
    if(!var || !var -> name)
        return;
    if(!var -> value)
        ft_printf_fd(fd, "%s\n", var->name);
    else    
        ft_printf_fd(fd, "%s=%s\n", var ->name, var-> value);
}


void print_all_adress_fd(t_adress *env, int fd)
{
    t_variables  *var  = my_first_variable(env); 
   
    if(!var)  
        return;
    while(var)
    {
        print_env_var_fd(var, fd);
            var =  var ->next;
    }
}

