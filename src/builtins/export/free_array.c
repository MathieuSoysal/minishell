/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:33:14 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:06:19 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"


void free_array(char **array) 
{
    int i;

    if (!array)
        return;

    i = 0;
    while (array[i]) {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    free(array);
}
