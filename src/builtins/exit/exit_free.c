/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:04:50 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/24 12:40:38 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exec/with_pipes/execution.h"
#include "../../libft/libft.h"
#include "../../minishell.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../builtins.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_out_f(t_outfile **outfiles)
{
	int	i;

	i = -1;
	if (outfiles == NULL)
		return ;
	while (outfiles[++i])
	{
		free(outfiles[i]->file_name);
		outfiles[i]->file_name = NULL;
		free(outfiles[i]);
		outfiles[i] = NULL;
	}
}

static void	free_str(char **strings)
{
	int	i;

	i = -1;
	if (strings == NULL)
		return ;
	while (strings[++i])
	{
		free(strings[i]);
		strings[i] = NULL;
	}
}

void	free_cmds(t_commande *commande)
{
	if (commande == NULL)
		return ;
	free_str(commande->args);
	free(commande->args);
	commande->args = NULL;
	if (commande->name != NULL)
		free(commande->name);
	commande->name = NULL;
	free_infiles(commande->infiles);
	commande->infiles = NULL;
	free_out_f(commande->outfiles);
	free(commande->outfiles);
	commande->outfiles = NULL;
	free(commande->path);
	commande->path = NULL;
	free(commande);
	commande = NULL;
}
