/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:42:49 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/18 04:59:31 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_PARSER_H
# define INTERNAL_PARSER_H

# include "../../structures/double_linked_list/double_linked_list.h"
# include <aio.h>

char	**split_by_pipe(char const *command_line);
char	**split_by_space(char const *command_line);
char	**double_linked_list_to_array(t_double_linked_list *list);
char	*get_word(char const *command_line, size_t *i, char const delimiter);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
char	*get_from_env(char **env, char *word);
char	*concatenate(t_double_linked_list *list);
char	*apply_dollars(char *command_line, char **env);

#endif // INTERNAL_PARSER_H
