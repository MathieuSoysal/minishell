
#ifndef TEST_CHECKER_ALL_H
# define TEST_CHECKER_ALL_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

static void	test_check_syntax(char **strs)
{
	t_syntax_error	error;

	for (int i = 0; strs[i]; i++)
	{
		error = check_syntax(strs[i]);
		TEST_CHECK(error == NO_ERROR);
		if(error != NO_ERROR)
			dprintf(2, "\033[31m		Error:\033[0m %s\n", strs[i]);
	}
}

void	test_check_syntax_no_error(void)
{
	t_syntax_error	error;

	test_check_syntax((char *[]){                                          //
									"ls -l",                                  //
									"ls echo \"|||| hola ceta\" | cat | cat\n", //
									"ls | cat | cat\n",                         //
									"export A=a B=b C=c\necho $A $B $C\n",                       //
									"export $HOLA=bonjour\nenv\n",                       //
									"export HOLA=\"bonjour      \"\necho $HOLA | cat -e\n",                       //
									"export HOLA=\"   -n bonjour   \"\necho $HOLA\n",                       //
									"export HOLA=\"bonjour   \"/\necho $HOLA\n",                       //
									"export HOLA=\'\"\'\necho \" $HOLA \" | cat -e\n",                       //
									"echo oui | echo non | echo hola | grep oui\n",                       //
									"echo hola|cat\n",                       //
									"echo hola > hello\necho hola >> hello >> hello >> hello\necho hola >> hello\ncat < hello\n",                       //
									"export A=a B=b C=c\necho $A $B $C",                       //
									"export A=a B=b C=c\necho $A $B $C",                       //
									"export A=a B=b C=c\necho $A $B $C",                       //
									NULL});
}

void	test_check_syntax_no_error_all(void)
{
	test_check_syntax_no_error();
}

#endif // TEST_CHECKER_ALL_H
