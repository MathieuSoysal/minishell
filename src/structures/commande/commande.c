/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:38:26 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 15:45:53 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commande.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

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

int	command_get_fd_infile(t_commande *commande)
{
	int	i;

	if (commande->infiles == NULL)
		return (0);
	i = 0;
	while (commande->infiles[i + 1] != NULL)
		i++;
	if (commande->infiles[i]->type == INFILE_TYPE_STRING)
		return (open(commande->infiles[i]->value.file_name_value, O_RDONLY));
	return (commande->infiles[i]->value.fd_value);
}

int	command_get_fd_outfile(t_commande *commande)
{
	int	i;

	if (commande->outfile_names == NULL)
		return (1);
	i = 0;
	while (commande->outfile_names[i + 1] != NULL)
		i++;
	return (open(commande->outfile_names[i], O_WRONLY | O_CREAT | O_TRUNC,
			0644));
}
