/**
 * @file    cluster.h
 * @brief   Definição dos atributos e protótipos dos métodos da classe Cluster.
 * @author  Eric Andrade Siqueira, Larissa Gilliane Melo De Moura, Luan Santos De Carvalho, Luís Eduardo Anunciado Silva, Renan Bezerra Kimura
 * @since   25/05/2017
 * @date    27/06/2017
 */
#ifndef __CLUSTER_H__
#define __CLUSTER_H__

/**
 * @class 	Cluster cluster.h
 * @brief 	Classe que representa um cluster (agrupamento)
 * @details Os atributos de um Cluster sao: id_cluster, central_values, points
 */
class Cluster
{
private:
	int id_cluster;                     /**< Numero de identificacao do cluster */
	std::vector<float> central_values;  /**< Coordenadas do centróide do cluster */
	std::vector<Point> points;          /**< Pontos pertencentes ao cluster */
public:
	Cluster(int id_cluster, Point point);
	void addPoint(Point point);
	bool removePoint(int id_point);
	float getCentralValue(int index);
	void setCentralValue(int index, float value);
	Point getPoint(int index);
	int getTotalPoints();
	int getID();
	bool operator==(const Cluster &other) const /* Método necesário para a especialização */
  	{
		return (central_values == other.central_values)
		&& (points == other.points)
		&& (id_cluster == other.id_cluster);
  	}
};

#endif /* __CLUSTER_H__ */
