/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init-init_env_variable.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:07:26 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/23 12:17:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_variables *init_variable(char *name, char *value, int id)
{
    t_variables *var;

    var =  (t_variables *)malloc(sizeof(t_variables));
    if(!var)
        return(NULL);
        
    var -> index = -1;
    var -> id  = id;
    var  -> value = value;
    var -> next =  NULL;
    var -> previous =  NULL;
    return (var);    
}

t_adress *init_env(char **env_variable)
{
    t_adress *env;
    
    env = (t_adress *)malloc(sizeof(t_adress));
     if(!env)
            return(NULL);
    env ->verbose =  0;
    env -> error_parsing  = 0;
    env -> error_processing =  NULL;
    env -> env_vars =  NULL;
    env -> variable = NULL;
    env -> first_token = NULL;
    env -> first_line = NULL;  
}
