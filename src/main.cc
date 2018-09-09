#include "global.h"
#include "check_args.h"

#include "agent.h"
#include "environment.h"


int main(int argc , char *argv []) {

	uint32_t filas;
	uint32_t columnas;
	uint32_t iteraciones;
	float    probLive;
	
		
	struct args_t  parametros;
	
	check argumentos = check(argc, argv);
	
	parametros = argumentos.check_args();
	
	filas       = parametros.NROWS;
	columnas    = parametros.NCOLS;
	iteraciones = parametros.ITERATIONS;
	probLive    = parametros.PROBLIVE;
	
	// Crear el ambiente
	CoordXY  size_env = {columnas, filas};
	Environment* universe = new Environment(size_env);
	
	//Crear los agentes	
	// Cada agente se agrega al ambiente, con sus respectivas
	// coordenadas (x,y). Se agregan por filas.
	//srand(time(NULL));
	std::vector<Agent*> agents;
	for(uint32_t id = 0; id < universe->getCapacityAgents(); id++){
		Agent* foo;
		foo = new Agent(id, probLive);
		agents.push_back(foo);
	}
	
	universe->addAgent(agents);
	
	universe->setNeighborsAgents();

	for(uint32_t it = 0; it < iteraciones; it++){
		puts ("\033[H\033[J");
		universe->showAgents(it);
		universe->applyAgentsRules();
		universe->updateAgents();		
		//getchar();
		usleep(100000);
	}
	
	/* 
	============PRUEBAS DE CONCEPTO BEGIN============
	//Crear ambiente de 20 columnas y 10 filas
	CoordXY  size_env = {20, 10};
	Environment* universe = new Environment(size_env);
	
	uint32_t total_agentes;
	total_agentes = universe->getTotalAgents();
	std::cout << total_agentes << std::endl;
	
	//Mostrar info del ambiente
	std::cout << universe << std::endl;
	
	//Acceder al agente id=6
	std::cout << universe->getAgent(6) << std::endl;
	
	//Acceder al agente (x,y)=(1,4)
	CoordXY  cfoo = {1,4};
	std::cout << universe->getAgent(cfoo) << std::endl;
	
	//Determinar cantidad de vecinos vivos del
	//agente (x,y)=(1,4)
	CoordXY  cfoo;
	uint32_t vecinos;
	
	cfoo = {1,4};
	vecinos = universe->livingNeighborsOf( universe->getAgent(cfoo) );
	
	std::cout << universe->getAgent(cfoo) << std::endl;
	std::cout << vecinos << std::endl;
	
	============PRUEBAS DE CONCEPTO END  ============
	*/
	
	
	return(EXIT_SUCCESS);
}