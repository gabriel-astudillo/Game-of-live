#include "global.h"
#include "check_args.h"

extern char *optarg;
extern int optind, opterr, optopt;


/*
 *		Funcion que imprime en stdout el uso
 *		del programa.
 */


check::check(int _argc , char **_argv){
	parametros.NROWS        = 0;
	parametros.NCOLS        = 0;
	parametros.ITERATIONS   = 0;
	parametros.PROBLIVE      = 0.0;
	
	argc = _argc;
	argv = _argv;
	
}

check::~check(){
	
}

struct args_t check::check_args(){
	int opcion;
	std::string optString = "r:c:i:s:h";
	
	while ((opcion = getopt (argc, argv, optString.c_str())) != -1){
		switch (opcion) {
			case 'r':
					parametros.NROWS = atoi(optarg);
					break;
			case 'c':
					parametros.NCOLS = atoi(optarg);
					break;
			case 'i':
					parametros.ITERATIONS = atoi(optarg);
					break;
			case 's':
					parametros.PROBLIVE = atof(optarg);
					break;
			case 'h':
			default:
					print_usage(argv[0]);
					exit(EXIT_FAILURE);
		}
	}

	if ( parametros.NROWS <=0 ||
		 parametros.NCOLS <= 0 ||
		 parametros.ITERATIONS <= 0 ||
	     parametros.PROBLIVE <= 0.0 || parametros.PROBLIVE > 1.0) {
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}
	
	return(parametros);
}

void check::print_usage(char* name){
	char opciones[] = "-r NROWS -c NCOLS -i ITERATIONS -s PROBLIVE [-h]\n";

	char descripcion[] = "Descripción:\n"
	                     "\t-r   Número de filas\n"
	                     "\t-c   Número de columnas\n"
					     "\t-i   Número de iteraciones\n"
					     "\t-s   Probabilidad incial de que una célula esté viva\n";

	printf("Uso: %s %s\n%s\n", name, opciones, descripcion);
}


