/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_change_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:12:41 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/30 14:25:34 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"



char *take_adresse_of_path(t_adress *adress)
{
    adress->adress_absolu = getcwd(NULL, 0);
    if (adress->adress_absolu == NULL)
        perror("getcwd() Error\n");
    return (adress->adress_absolu);
}

char *take_adress_of_new_path(t_adress *adress)
{
    adress->adress_for_new_path = take_var_for_adress(adress, "PWD");
    adress->adress_for_path = mem_malloc_str(adress->adress_for_new_path);
    return (adress->adress_for_path);
}

char *take_var_for_adress(t_adress *adress, char *name)
{
    t_variables *variable = take_var_for_next_value(adress, name);
    if (variable)
    {
        return variable->value;
    }
    return NULL;
}

t_variables *take_var_for_next_value(t_adress *adress, char *name)
{
    t_variables *variables_env = adress->variable;

    while (variables_env)
    {
        if (ft_strcmp(name, variables_env->name) == 0)
        {
            return variables_env;
        }
        variables_env = variables_env->next;
    }
    return NULL;
}

void changing_var_name(t_adress *adresse, char *name, char *value)
{
    t_variables *variable = take_var_for_next_value(adresse, name);

    if (variable)
    {
        free(variable->value);
        variable->value = ft_strdup(value);
    }
    else
    {
        variable = malloc(sizeof(t_variables));
        variable->name = ft_strdup(name);
        variable->value = ft_strdup(value);
        variable->next = adresse->variable;
        adresse->variable = variable;
    }
}





