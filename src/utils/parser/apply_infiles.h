/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_infiles.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:04:52 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/27 11:28:07 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_INFILES_H
# define APPLY_INFILES_H

# include <stdbool.h>

char	**extract_infiles(char **command_line);
int		extract_heredoc(char **command_line);
bool	has_infiles(char **command_line);
bool	has_heredoc(char **command_line);

#endif // APPLY_INFILES_H
