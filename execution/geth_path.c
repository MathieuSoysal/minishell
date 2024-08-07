/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geth_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:40:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:35 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char *get_path(char *cmd, char **env)
{
   t_variables var;
   
    var.path_env = find_road_for_env("PATH", env);
    if (!var.path_env)
        return (cmd);
    var.allpath = ft_split(var.path_env, ':');
    var.s_cmd = ft_split(cmd, ' ');
    if (!var.allpath || !var.s_cmd)
        return (cmd);
    var.i = -1;
    while (var.allpath[++var.i])
    {
        var.path_part = ft_strjoin(var.allpath[var.i], "/");
        var.exec = ft_strjoin(var.path_part, var.s_cmd[0]);
        free(var.path_part);
         if (access(var.exec, F_OK | X_OK) == 0)
        {
            free_in_path(var.allpath, var.s_cmd);
            return (var.exec);
        }
         free(var.exec);
    }
    return (cmd);
}
char *find_road_for_env(char *name, char **env)
{
    
    
    t_variables var;
    var.i = 0;
    while (env[var.i])
    {
        var.j = 0;
        while (env[var.i][var.j] && env[var.i][var.j] != '=')
            var.j++;
        var.sub = ft_substr(env[var.i], 0, var.j);
        if (ft_strncmp(var.sub, name, ft_strlen(name)) == 0)
        {
            free(var.sub);
            return (env[var.i] + var.j + 1);
        }
        free(var.sub);
        var.i++;
    }
    return (NULL);
}
