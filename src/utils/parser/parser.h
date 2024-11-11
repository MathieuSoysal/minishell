/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:51:13 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/11 21:32:41 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../structures/commande/commande.h"

/**
 * @brief Parse the command line and create a array of commandes,
	the array is NULL terminated
 * @param command_line The command line to parse
 * @return The list of commandes
 */
t_commande	**parse_command_line(char *command_line, char **env);
			void free_parsed_commands(t_commande **commands);

#endif // PARSER_H
