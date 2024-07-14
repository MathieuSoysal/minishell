
#ifndef TEST_CHECKER_OUTFILE_H
# define TEST_CHECKER_OUTFILE_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

void	test_check_syntax_outfile(void)
{
	t_syntax_error	error;

	error = check_syntax("> > > >\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_OUTFILE);
	error = check_syntax("cat >> > >> << >>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_OUTFILE);
}

void	test_check_syntax_outfile_all(void)
{
	test_check_syntax_outfile();
}

#endif // TEST_CHECKER_OUTFILE_H
