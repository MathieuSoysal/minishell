/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_malloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:26 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/11 18:20:44 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"builtins.h"

char *mem_malloc_str(char *tab_for_mlc)
{
    size_t i;
    char *str;

    str = malloc(sizeof(char) * (ft_strlen(tab_for_mlc) + 1));
    i = 0;
    while (tab_for_mlc[i])
    {
        str[i] = tab_for_mlc[i];
        i++;
    }
    str[i] = 0;
    return (str);
}