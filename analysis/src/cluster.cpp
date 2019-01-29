#include <vector>
#include "pointers.h"
#include "cluster.h"

/**
* @details  Construtor parametrizado da classe Cluster.
* @param    id_cluster Número de idenficação do cluster.
* @param    point Objeto da classe Point.
*/
Cluster::Cluster(int id_cluster, Point point)
{
	this->id_cluster = id_cluster;

	int total_values = point.getTotalValues();

	for(int i = 0; i < total_values; i++)
		central_values.push_back(point.getValue(i));

	points.push_back(point);
}

/** @brief Adiciona um ponto ao cluster.
*   @param point
*   @return void
*/
void Cluster::addPoint(Point point)
{
	points.push_back(point);
}

/** @brief Remove um ponto do cluster através do seu identificador, caso seja encontrado.
*   @param id_point
*   @return void
*/
bool Cluster::removePoint(int id_point)
{
	int total_points = points.size();

	for(int i = 0; i < total_points; i++)
	{
		if(points[i].getID() == id_point)
		{
			points.erase(points.begin() + i);
			return true;
		}
	}
	return false;
}
	
/** @param index
*   @return Valor do centro do cluster.
*/
float Cluster::getCentralValue(int index)
{
	return central_values[index];
}
	
/** @brief Altera o valor do centro do cluster.
*   @param index
*   @param value
*   @return void
*/
void Cluster::setCentralValue(int index, float value)
{
	central_values[index] = value;
}
	
/** @return Número de identificação do ponto. 
*   @param index
*/
Point Cluster::getPoint(int index)
{
	return points[index];
}

/** @return Quantidade de pontos do cluster. */
int Cluster::getTotalPoints()
{
	return points.size();
}

/** @return Número de identificação do cluster. */
int Cluster::getID()
{
	return id_cluster;
}
