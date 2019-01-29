/**
 * @file    kmeans.h
 * @brief   Definição dos atributos e protótipos dos métodos da classe KMeans.
 * @author  Eric Andrade Siqueira, Larissa Gilliane Melo De Moura, Luan Santos De Carvalho, Luís Eduardo Anunciado Silva, Renan Bezerra Kimura
 * @since   25/05/2017
 * @date    27/06/2017
 */
#ifndef __KMEANS_H__
#define __KMEANS_H__

/**
 * @class 	KMeans KMeans.h
 * @brief 	Classe usada para executar o processo de análise de agrupamentos do tipo k-means
 * @details Os atributos de um objeto KMeans são: K, total_values, total_points, max_iterations, clusters
 */
class KMeans
{
private:
	int K;                         /**< Número de clusters. */
	int total_values;              /**< Número total de valores de cada ponto. */
	int total_points;              /**< Número total de pontos. */
	std::vector<Cluster> clusters; /**< Vector dos clusters */
	int getIDNearestCenter(Point point);
public:
	KMeans(int K, int total_points, int total_values);
	void run(std::vector<Point> & points);
};

#endif /* __KMEANS_H__ */
