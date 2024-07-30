/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:45:19 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/30 15:02:54 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIBFT_H
# define MINI_LIBFT_H

# include "../../structures/double_linked_list/double_linked_list.h"
# include <aio.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strndup(const char *s, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
bool	equals(const char *s1, const char *s2);
int		ft_strlen(const char *s);
char	*concatenate(t_double_linked_list *list);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_word_until(char const *command_line, size_t *i,
			char const delimiter);
char	*get_from_env(char **env, char *word);
char	*ft_get_next_line(int fd);

#endif // MINI_LIBFT_H
