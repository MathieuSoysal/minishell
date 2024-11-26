/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompteur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:12:41 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/24 22:50:39 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../utils/mini_libft/mini_libft.h"
#include "internal.h"
#include <readline/readline.h>
#include <stdbool.h>
#include <unistd.h>




void	append_to_prompt(void *prompt, char *str)
{
	t_double_linked_list	*prompt_list;

	prompt_list = (t_double_linked_list *)prompt;
	double_linked_list_add_last(prompt_list, ft_strdup(str));
}

static void	append_pwd_to_prompt(void *prompt)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if(pwd != NULL)
	{
		append_to_prompt(prompt, pwd);
		free(pwd);
	}
}
void append_path_to_prompt(t_double_linked_list *prompt)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		append_pwd_to_prompt(prompt);
		free(cwd);
	}
	else
	{
		append_to_prompt(prompt, "(unknown)");
	}
}

char	*get_prompt(void)
{
	
	t_double_linked_list	*prompt;
	char					*path;

	prompt = double_linked_list_create();
	rl_set_screen_size(900, 900);
	if (get_exit_status(_LAST_STATUS) == 0)
		append_to_prompt(prompt, "\033[1;32m");
	else
		append_to_prompt(prompt, "\033[1;31m");
	append_to_prompt(prompt, "⇒ \033[1;36m");
	path = get_path_git_repo();
	if (path != NULL)
		append_git_prompt(prompt, path);
	else
	{
		append_path_to_prompt(prompt);
	}
	if (get_exit_status(_LAST_STATUS) == 0)
		append_to_prompt(prompt, "\033[1;32m");
	else
		append_to_prompt(prompt, "\033[1;31m");
	append_to_prompt(prompt, " ▷ \033[40;0m");
	return (concatenate(prompt));
}
