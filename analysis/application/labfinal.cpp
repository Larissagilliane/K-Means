/**
 * @file    labfinal.cpp
 * @brief   Código fonte principal do projeto de "Análise de Agrupamentos" da disciplina LP
 * @author  Eric Andrade Siqueira, Larissa Gilliane Melo De Moura, Luan Santos De Carvalho, Luís Eduardo Anunciado Silva ,Renan Bezerra Kimura
 * @since   25/05/2017
 * @date    27/06/2017
 * @sa      cluster.h
 * @sa      dataframe.h
 * @sa      hash.h
 * @sa      kmeans.h
 * @sa      pointers.h
 * @sa      sets.h
 */
#include <iostream> //cin, cout
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <vector> //vector
#include <string> //string
#include <unordered_set> //unordered_set
#include <math.h> // pow, sum...
#include <stdlib.h> //sran, rand
#include <time.h> //time
#include <algorithm> //find
#include "dataframe.h"
#include "sets.h"
#include "pointers.h"
#include "cluster.h"
#include "kmeans.h"
#include "hash.h"

 /**
 * @brief Função main
 * @param argc um contador inteiro, das linhas de comando
 * @param argv um vetor como argumento das linhas de comando
 * @return um inteiro 0 exit_success
 */
int main(int argc, char * argv[])
{
    /* Um condição de encerramento do programa, caso não haja inserção de
    um data frame. */
    if(!argv[1])
    {
      std::cout << "Não houve entrada de data frame." << std::endl;
      return 0;
    }

	  /* Passado o arquivo o nome do arquivo de dataframe de entrada, será
    aberto o arquivo para leitura. */
    std::string stringDataframe(argv[1]);
    std::ifstream fileDataframe (stringDataframe, std::ios::in);

    /* Inicialização de váriável da classe Dataframe. */
    DataFrame <float> inputDataFrame;

    /* Leitura do dataframe de entrada. */
    fileDataframe >> inputDataFrame;

    /* Dependendo se a matriz for válida, ela será mostrada ou não.*/
	if(inputDataFrame.state() == true)
  {
      Set <Point> inputSet;
		  std::vector<float> values; // Vector de float
      size_t size_dt = inputDataFrame.size_DataFrameRow();
		  for(size_t i = 0; i < size_dt; i++)
		  {
				values = inputDataFrame.observation(i); //Observação
				Point p(i, values); //Atribui o numero do id_point para cada observação
				inputSet.insertion(p);
				values.clear();
		  }
      std::vector <Point> outputSet = inputSet.conversion();
		  int size_clusters = inputDataFrame.size_Clusters(); //Pega o último elemento da última linha
		  KMeans kmeans(size_clusters, (int) inputDataFrame.size_DataFrameRow(), (int) inputDataFrame.size_DataFrameCol()-1); //numero de clusters, quantidade de observações, quantidade de valores
		  kmeans.run(outputSet);//observações
	}
    else
    {
      /* Se a entrada da dataframe estiver errada, será avisado ao usuário.*/
      std::cout << "Entrada inválida de data frame." << std::endl;
    }
	/* Será fechado o arquivo de dataframe de entrada. */
  	fileDataframe.close();
  	return 0;
}
