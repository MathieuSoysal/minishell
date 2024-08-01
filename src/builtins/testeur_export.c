/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:44:24 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 14:53:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "builtins.h"

void test_export_built_in() {
    t_adress env;
    t_cmd cmd;
    char *arg1 = "TEST1=value1";
    char *arg2 = "TEST2=value2";

   
    env.variable = NULL;
    env.verbose = 0;
    env.error_parsing = 0;
    env.error_processing = 0;
    env.env_vars = NULL;
    env.first_line = NULL;
    env.first_token = NULL;

  
    cmd.arg = arg1;
    cmd.fd_out = 1;  

    
    printf("Testing export function for TEST1=value1...\n");
    export(&cmd, &env);

 
    t_variables *var1 = get_env_var_with_name(&env, "TEST1");
    if (var1 && strcmp(var1->value, "value1") == 0) {
        printf("Test passed: Variable 'TEST1' with value 'value1' added successfully.\n");
    } else {
        printf("Test failed: Variable 'TEST1' was not added correctly.\n");
    }


    cmd.arg = arg2;


    printf("Testing export function for TEST2=value2...\n");
    export(&cmd, &env);


    t_variables *var2 = get_env_var_with_name(&env, "TEST2");
    if (var2 && strcmp(var2->value, "value2") == 0) {
        printf("Test passed: Variable 'TEST2' with value 'value2' added successfully.\n");
    } else {
        printf("Test failed: Variable 'TEST2' was not added correctly.\n");
    }

    
    free(var1->name);
    free(var1->value);
    free(var1);
    free(var2->name);
    free(var2->value);
    free(var2);
}
