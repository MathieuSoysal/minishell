/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:26 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/22 02:43:33 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commande.h"
#include <stdlib.h>

t_commande	*commande_create(char *name, char **args, char *infile_name,
		char *outfile_name)
{
	t_commande	*new_commande;

	new_commande = (t_commande *)malloc(sizeof(t_commande));
	if (new_commande == NULL)
		return (NULL);
	new_commande->name = name;
	new_commande->args = args;
	new_commande->infile_names = infile_name;
	new_commande->outfile_names = outfile_name;
	return (new_commande);
}

bool	commande_has_infile(t_commande *commande)
{
	return (commande->infile_names != NULL);
}

bool	commande_has_outfile(t_commande *commande)
{
	return (commande->outfile_names != NULL);
}

void	commande_free(t_commande *commande)
{
	int	i;

	i = -1;
	free(commande->name);
	commande->name = NULL;
	if (commande->args != NULL)
	{
		while (commande->args[++i])
		{
			free(commande->args[i]);
			commande->args[i] = NULL;
		}
	}
	free(commande->args);
	commande->args = NULL;
	free(commande->infile_names);
	commande->infile_names = NULL;
	free(commande->outfile_names);
	commande->outfile_names = NULL;
	free(commande);
	commande = NULL;
}
