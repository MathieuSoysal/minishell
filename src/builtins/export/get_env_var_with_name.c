/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var_with_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:09:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:06:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

t_variables  *get_env_var_with_name(t_adress *env, char *name)
{
    t_variables  *var;
    
    var =  my_first_variable(env);
    if(!var)
    {
        return(NULL);
    }
        while(var)
        {
            if(ft_same_name(name, var -> name))
            {
                return(var);
            }
            var =  var -> next;
        }
        return(NULL);    
}
