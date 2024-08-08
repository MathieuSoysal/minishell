/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:45:31 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 16:36:21 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commande.h"
#include <stdio.h>
#include <stdlib.h>

static void	free_strings(char **infiles)
{
	int	i;

	i = -1;
	if (infiles == NULL)
		return ;
	while (infiles[++i])
	{
		free(infiles[i]);
		infiles[i] = NULL;
	}
}

void	commande_free(t_commande *commande)
{
	if (commande == NULL)
		return ;
	if (commande->name != NULL)
		free(commande->name);
	commande->name = NULL;
	free_strings(commande->args);
	free(commande->args);
	commande->args = NULL;
	free_infiles(commande->infiles);
	commande->infiles = NULL;
	free_strings(commande->outfile_names);
	free(commande->outfile_names);
	commande->outfile_names = NULL;
	free(commande->path);
	commande->path = NULL;
	free(commande);
	commande = NULL;
}

void	free_commands(t_commande **commands)
{
	int	i;

	i = -1;
	if (commands == NULL)
		return ;
	while (commands[++i])
	{
		commande_free(commands[i]);
		commands[i] = NULL;
	}
	free(commands);
}
