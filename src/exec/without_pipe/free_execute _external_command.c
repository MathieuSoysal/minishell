/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_execute _external_command.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:09:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/11 23:07:51 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../utils/mini_libft/mini_libft.h"
#include"../../structures/env/env.h"
#include "internal.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


void free_args(char **args)
{
    if (!args)
        return;
    int i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

void free_in(t_infile **infiles)
{
    if (!infiles)
        return;
    int i = 0;
    while (infiles[i])
    {
        free(infiles[i]);
        i++;
    }
    free(infiles);
}

void free_out(t_outfile **outfiles)
{
    if (!outfiles)
        return;
    int i = 0;
    while (outfiles[i])
    {
        free(outfiles[i]);
        i++;
    }
    free(outfiles);
}

void commands_free(t_commande *command)
{
    
    if (!command)
        return;

    free(command->name);
    free(command->path);
    free_args(command->args);
    free_in(command->infiles);
    free_out(command->outfiles);
    free(command);
}

