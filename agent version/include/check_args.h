#ifndef _CHECK_ARGS_H_
#define _CHECK_ARGS_H_

#include "global.h"


class checkArgs {
private:
	// 1) Modificar esta sección
	const std::string optString = "r:c:i:s:h";
	
	const std::string opciones = "-r NROWS -c NCOLS -i ITERATIONS -s PROBLIVE [-h]";

	const std::string descripcion  = "Descripción:\n"
		                             "\t-r   Número de filas\n"
									 "\t-c   Número de columnas\n"
									 "\t-i   Número de iteraciones\n"
									 "\t-s   Probabilidad incial de que una célula esté viva\n";
	
	typedef struct args_t{
		int32_t NROWS;
		int32_t NCOLS;
		int32_t ITERATIONS;
		float   PROBLIVE;
	} args_t;
	
	// 2) Modificar constructor
	// 2) Modificar ciclo "getopt" en método ::getArgs()
	
	args_t  parametros;
	
	int argc;
	char **argv;

	
public:
	checkArgs(int _argc , char **_argv);
	~checkArgs();
	args_t getArgs();;
	
private:
	void printUsage();
	
	
};

#endif
