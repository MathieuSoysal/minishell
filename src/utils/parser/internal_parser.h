/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:42:49 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/15 21:47:14 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_PARSER_H
# define INTERNAL_PARSER_H

# include <aio.h>

char	**split_by_pipe(char const *command_line);
char	**split_by_space(char const *command_line);
char	**double_linked_list_to_array(t_double_linked_list *list);
char	*get_word(char const *command_line, size_t *i, char const delimiter);
char	*ft_strndup(const char *s, size_t n);

#endif // INTERNAL_PARSER_H
