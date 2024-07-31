/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:26 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 12:09:47 by hsoysal          ###   ########.fr       */
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

void	commande_free(t_commande *commande)
{
	int	i;

	i = -1;
	if (commande == NULL)
		return ;
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
	free_infiles(commande->infiles);
	commande->infiles = NULL;
	free(commande->outfile_names);
	commande->outfile_names = NULL;
	free(commande);
	commande = NULL;
}

void	print_commande(t_commande *commande)
{
	int	i;

	printf("Command: %s\n", commande->name);
	printf("Arguments: ");
	i = -1;
	while (commande->args[++i])
		printf("%s ", commande->args[i]);
	printf("\n");
	if (commande->infiles)
	{
		printf("Infiles: ");
		i = -1;
		while (commande->infiles[++i])
			printf("%s ", commande->infiles[i]->value.file_name_value);
		printf("\n");
	}
	if (commande->outfile_names)
	{
		printf("Outfiles: ");
		i = -1;
		while (commande->outfile_names[++i])
			printf("%s ", commande->outfile_names[i]);
		printf("\n");
	}
}
