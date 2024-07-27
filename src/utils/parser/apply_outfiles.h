/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_outfiles.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:04:52 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/25 14:07:59 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_OUTFILES_H
# define APPLY_OUTFILES_H

# include <stdbool.h>

char	**extract_outfiles(char **command_line);
bool	has_outfiles(char **command_line);
bool	has_outfiles_append(char **command_line);

#endif // APPLY_OUTFILES_H
