/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:37:06 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/24 17:48:30 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int export(t_cmd *cmd,  t_adress *env)
{
    char *name;
    char *value;
    int id;

    if(!cmd->arg){
     print_all_adress_fd(env, cmd->fd_out);
        return(0);
    }
    name =  get_export_variable_name(cmd->arg);
    if(!name)
    {
        ft_putstr_fd("export : not a valid identifier\n", 1);
        return(1);
    }
     value =  get_env_variable_value(cmd -> arg);
     id =  assign_env_var_id(value);
     change_or_create_var(env, name, value, id);
    
    return(0);
}