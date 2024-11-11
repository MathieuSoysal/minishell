/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:30:19 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/11 23:27:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../parser/parser.h"

void free_arguments(char **args)
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


void free_inf(t_infile **infiles)
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

void free_outf(t_outfile **outfiles)
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


void free_single_command(t_commande *command)
{
    if (!command)
        return;

    free(command->name);
    free(command->path);
    free_arguments(command->args);
    free_inf(command->infiles);
    free_outf(command->outfiles);
    free(command);
}





void free_parsed_commands(t_commande **commands)
{
   
    if (!commands)
        return;

    int i = 0;
    while (commands[i])
    {
        free_single_command(commands[i]);
        i++;    
    }
    free(commands);
}
