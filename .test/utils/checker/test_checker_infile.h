
#ifndef TEST_CHECKER_INFILE_H
# define TEST_CHECKER_INFILE_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

void	test_check_syntax_infile(void)
{
	t_syntax_error	error;

	error = check_syntax("echo > <\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_INFILE);
	error = check_syntax("echo hola < < bonjour\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_INFILE);
	error = check_syntax("echo hola <<< bonjour\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_INFILE);
}

void	test_check_syntax_infile_all(void)
{
	test_check_syntax_infile();
}

#endif // TEST_CHECKER_INFILE_H
