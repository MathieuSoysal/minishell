/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:51:13 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/10 19:29:02 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../structures/commande/commande.h"

/**
 * @brief Parse the command line and create a array of commandes,
	the array is NULL terminated
 * @param command_line The command line to parse
 * @return The list of commandes
 */
t_commande	**parse_command_line(char *command_line);

#endif // PARSER_H
