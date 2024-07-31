/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:26 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 15:45:49 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commande.h"
#include <stdio.h>
#include <stdlib.h>

t_commande	*commande_create(char *name, char **args, t_infile **infiles,
		char **outfile_names)
{
	t_commande	*new_commande;

	new_commande = (t_commande *)malloc(sizeof(t_commande));
	if (new_commande == NULL)
		return (NULL);
	new_commande->name = name;
	new_commande->args = args;
	new_commande->infiles = infiles;
	new_commande->outfile_names = outfile_names;
	return (new_commande);
}

bool	commande_has_infile(t_commande *commande)
{
	return (commande->infiles != NULL);
}

bool	commande_has_outfile(t_commande *commande)
{
	return (commande->outfile_names != NULL);
}



void	print_commande(t_commande *commande)
{
}
