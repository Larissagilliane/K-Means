#include <vector>
#include "pointers.h"

/**
* @details  Construtor parametrizado da classe Point.
* @param    id_point Número de identificação do ponto.
* @param    values Valores das coordenadas do ponto.
*/
Point::Point(int id_point, std::vector<float>& values)
{
	this->id_point = id_point;
	total_values = values.size();

	for(int i = 0; i < total_values; i++)
		this->values.push_back(values[i]);

	id_cluster = -1; /* Na inicialização ele não pertence a nenhum cluster */
}

/** @return   Número de identificação do ponto. */
int Point::getID()
{
	return id_point;
}

/**
* @brief    Modificador do atributo de identificaçãod do cluster.
* @param    id_cluster Identificador do cluster
*/
void Point::setCluster(int id_cluster)
{
	this->id_cluster = id_cluster;
}

/**
* @brief        Dá acesso ao atributo de identificação do cluster.
* @return       Número de identificação do cluster.
*/
int Point::getCluster()
{
	return id_cluster;
}

/**
* @brief    Dá acesso ao atributo com os valores das coordenadas do ponto.
* @param    index Índice referente a o valor de cada observação
* @return   Valores das coordenadas do ponto
*/
float Point::getValue(int index)
{
	return values[index];
}

/** @return   Quantidade de coordenadas do ponto. */
int Point::getTotalValues()
{
	return total_values;
}
