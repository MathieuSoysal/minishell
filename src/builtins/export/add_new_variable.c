/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:45:19 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:05:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void add_new_env_variable(t_adress *env, t_variables *new) 
{
    t_variables *last_var;

    last_var = get_last_env_var(env);
    if (!last_var) 
    {
        env->variable = new;
    } 
    else
    {
        last_var->next = new;
        new->previous = last_var;
    }
    new->index = (last_var) ? last_var->index + 1 : 0;
    new->next = NULL;
}
