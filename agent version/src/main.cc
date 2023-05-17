#include <global.h>
#include <checkArgs.hpp>
#include <clock.h>

#include <agent.h>
#include <environment.h>


int main(int argc, char *argv [])
{
	uint32_t filas;
	uint32_t columnas;
	uint32_t iteraciones;
	float    probLive;
	uint32_t typeOfProc;
	uint32_t display;

	checkArgs* argumentos = new checkArgs(argc, argv);

	filas       = argumentos->getArgs().NROWS;
	columnas    = argumentos->getArgs().NCOLS;
	iteraciones = argumentos->getArgs().ITERATIONS;
	probLive    = argumentos->getArgs().PROBLIVE;
	typeOfProc	= argumentos->getArgs().TYPEOFPROC;
	display		= argumentos->getArgs().DISPLAY;

	// Crear el ambiente
	CoordXY  size_env = {columnas, filas};

	srand(1);
	Environment* universe = new Environment(size_env);
	
	universe->initEnvironment(probLive);

	Environment* universeVectorial{nullptr};
	if (typeOfProc == 1) {
		srand(1);
		universeVectorial = new Environment(size_env);
		universeVectorial->initEnvironment(probLive);
	}

	uint32_t sequentialProc {0};
	uint32_t vectorialProc {1};
	float sumSeq {}, sumVec {}, avgSeq {}, avgVec {};

	for(uint32_t it = 0; it < iteraciones; it++) {
		
		if (display) universe->displayBoard(it);

		sumSeq += measureTime([&](){universe->applyAgentsRules(sequentialProc);});

		if (typeOfProc) sumVec += measureTime([&](){universeVectorial->applyAgentsRules(vectorialProc);});

		universe->printDataSec(it);

		if (typeOfProc) universeVectorial->printDataVec();

		universe->updateAgents();

		if (typeOfProc) universeVectorial->updateAgents();

		usleep(100000);
	}

	auto calculateAvg = [&] (float sum){
		float avg {};
		avg = sum/iteraciones;
		return avg;
	};
	
	avgSeq = calculateAvg(sumSeq);

	if (typeOfProc) avgVec = calculateAvg(sumVec);

	std::cout <<"\n" << avgSeq << " ms";

	if (typeOfProc) std::cout << " : " <<avgVec << " ms\n";

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

	delete argumentos;
	delete universe;

	return(EXIT_SUCCESS);
}
