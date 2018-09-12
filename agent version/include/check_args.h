#ifndef _CHECK_ARGS_H_
#define _CHECK_ARGS_H_

#include "global.h"


class checkArgs {
private:
	
	typedef struct args_t{
		int32_t NROWS;
		int32_t NCOLS;
		int32_t ITERATIONS;
		float   PROBLIVE;
	}args_t;
	
	args_t  parametros;
	
	int argc;
	char **argv;

	
public:
	checkArgs(int _argc , char **_argv);
	~checkArgs();
	args_t getArgs();;
	
private:
	void printUsage(char* name);
	
	
};

#endif
