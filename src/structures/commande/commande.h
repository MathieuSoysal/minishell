/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:36:50 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/10 17:17:56 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDE_H
# define COMMANDE_H

# include <stdbool.h>

/**
 * @brief Structure representing a command
 * @param name The name of the command
 * @param args The arguments of the command, its NULL terminated
 * @param infile_name The name of the file to read from
 * @param outfile_name The name of the file to write to
 */
typedef struct s_commande
{
	char	*name;
	char	**args;
	char	*infile_name;
	char	*outfile_name;
}			t_commande;

t_commande	*commande_create(char *name, char **args, char *infile_name,
				char *outfile_name);

/**
 * @brief Check if a command has an infile
 * @param commande The command to check
 * @return true if the command has an infile, false otherwise
 */
bool		commande_has_infile(t_commande *commande);

/**
 * @brief Check if a command has an outfile
 * @param commande The command to check
 * @return true if the command has an outfile, false otherwise
 */
bool		commande_has_outfile(t_commande *commande);

/**
 * @brief Free a command
 * @param commande The command to free
 */
void		commande_free(t_commande *commande);

#endif // COMMANDE_H
