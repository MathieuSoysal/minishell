
#ifndef TEST_CHECKER_DOUBLE_PIPE_H
# define TEST_CHECKER_DOUBLE_PIPE_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

void	test_check_syntax_double_pipe(void)
{
	t_syntax_error	error;

	error = check_syntax("||");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_DOUBLE_PIPE);
	error = check_syntax("|||||\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_DOUBLE_PIPE);
	error = check_syntax("|||||||||||||\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_DOUBLE_PIPE);
}

void	test_check_syntax_double_pipe_all(void)
{
	test_check_syntax_double_pipe();
}

#endif // TEST_CHECKER_DOUBLE_PIPE_H
