#ifndef _CHECK_ARGS_H_
#define _CHECK_ARGS_H_

#include "global.h"

struct args_t{
	int32_t NROWS;
	int32_t NCOLS;
	int32_t ITERATIONS;
	float   PROBLIVE;
};


class check {
private:
	
	struct args_t  parametros;
	
	int argc;
	char **argv;

	
public:
	check(int _argc , char **_argv);
	~check();
	struct args_t check_args();
	
private:
	void print_usage(char* name);
	
	
};

#endif
