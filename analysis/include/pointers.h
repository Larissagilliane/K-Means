/**
 * @file    pointers.h
 * @brief   Definição dos atributos e protótipos dos métodos da classe Point.
 * @author  Eric Andrade Siqueira, Larissa Gilliane Melo De Moura, Luan Santos De Carvalho, Luís Eduardo Anunciado Silva, Renan Bezerra Kimura
 * @since   25/05/2017
 * @date    27/06/2017
 */
#ifndef __POINTERS_H__
#define __POINTERS_H__

/**
 * @class 	Point pointers.h
 * @brief 	Classe que representa um ponto.
 * @details Os atributos de um Point são: id_point, id_cluster, values, total_values
 */
class Point
{
public:
	int id_point;               /**< Numero de identificacao do ponto */
	int id_cluster;             /**< Numero de identificação do cluster em que o ponto se encontra */
	std::vector<float> values;  /**< Vector para armazenar os valores */
	int total_values;           /**< Numero de coordenadas que values armazena */
	Point(int id_point, std::vector<float>& values);
	int getID();
	void setCluster(int id_cluster);
	int getCluster();
	float getValue(int index);
	int getTotalValues();
	bool operator==(const Point &other) const /* Método necesário para a especialização */
  	{
		return (values == other.values) &&
			   (id_point == other.id_point) &&
			   (id_cluster == other.id_cluster) &&
			   (total_values == other.total_values);
  	}
};

#endif /* __POINTERS_H__ */
