/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_varible_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:39:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/24 14:45:20 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char *get_env_variable_value (char *variable)
{
    int i =  0;
    int start;
    int end;
    
    if(!variable)
        return(NULL);
    while(variable[i])
    {
        if(variable[i] == '=' && !(is_blank(variable[i + 1])))
        {
            start =  i + 1;
            end =  ft_strlen(variable);
            return malloc_substrcpy(variable, start, end);
            
        }
        i ++;
    }
    return(NULL);   
}
