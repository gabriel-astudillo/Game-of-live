#include "global.h"
#include "check_args.h"

extern char *optarg;
extern int optind, opterr, optopt;

checkArgs::checkArgs(int _argc , char **_argv){
	parametros.NROWS        = 0;
	parametros.NCOLS        = 0;
	parametros.ITERATIONS   = 0;
	parametros.PROBLIVE     = 0.0;
	
	argc = _argc;
	argv = _argv;
	
}

checkArgs::~checkArgs(){
	
}

checkArgs::args_t checkArgs::getArgs(){
	int opcion;
	
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
					printUsage();
					exit(EXIT_FAILURE);
		}
	}

	if ( parametros.NROWS <=0 ||
		 parametros.NCOLS <= 0 ||
		 parametros.ITERATIONS <= 0 ||
	     parametros.PROBLIVE <= 0.0 || parametros.PROBLIVE > 1.0) {
		printUsage();
		exit(EXIT_FAILURE);
	}
	
	return(parametros);
}

void checkArgs::printUsage(){
	printf("Uso: %s %s\n%s\n", argv[0], opciones.c_str(), descripcion.c_str());
}


