/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_value_with_name.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:48:33 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/29 16:12:35 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

 void   change_env_value_with_name(t_adress *env, char *name, char *value)
  {
    t_variables  *var;
    
    var =  get_env_var_with_name(env, name);
    if(!var)
    {
        return;
    }
    change_env_var_value(var, value);
  }
  