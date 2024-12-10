/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:26:28 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/07 16:16:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commande/commande.h"
#include "commandes.h"
#include <stdlib.h>

unsigned int	list_commandes_get_nb_commandes(t_list_commandes *commandes)
{
	return (commandes->size);
}

t_commande	**list_commandes_to_array(t_list_commandes *commandes)
{
	t_commande	**array;
	size_t		i;

	array = (t_commande **)malloc(sizeof(t_commande *) * (commandes->size + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < commandes->size)
	{
		array[i] = list_commandes_pop(commandes);
		i++;
	}
	array[i] = NULL;
	list_commandes_free(commandes);
	return (array);
}
