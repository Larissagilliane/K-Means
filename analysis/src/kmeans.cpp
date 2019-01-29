#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <algorithm>
#include "pointers.h"
#include "cluster.h"
#include "kmeans.h"

/**
* @details  Função que busca o Id do centro mais próximo
* @param    point 
* @return   int  id_cluster_center
*/
int KMeans::getIDNearestCenter(Point point)
{
	double sum = 0.0, min_dist;
	int id_cluster_center = 0;

	for(int i = 0; i < total_values; i++)  /* Calcula a distancia pelo primeiro cluster para ter uma distancia minima*/
	{
		sum += pow(clusters[0].getCentralValue(i) -
				   point.getValue(i), 2.0);
	}

	min_dist = sqrt(sum);

	for(int i = 1; i < K; i++)  /* Calculo das demais distancias */
	{
		double dist;
		sum = 0.0;

		for(int j = 0; j < total_values; j++)
		{
			sum += pow(clusters[i].getCentralValue(j) -
					   point.getValue(j), 2.0);
		}

		dist = sqrt(sum);

		if(dist < min_dist)
		{
			min_dist = dist;
			id_cluster_center = i;
		}
	}

	return id_cluster_center;
}

/**
* @details  Construtor parametrizado da classe KMeans.
* @param    K Número do agrupamento.
* @param    total_points Quantidade de pontos pertencentes ao agrupamento.
* @param    total_values Quantidade de valores em cade ponto.
*/
KMeans::KMeans(int K, int total_points, int total_values)
{
	this->K = K;
	this->total_points = total_points;
	this->total_values = total_values;
}

/**
* @details  Execução do algoritmo de agrupamento KMeans.
* @param    points Vector com objetos da classe Point.
*/
void KMeans::run(std::vector<Point> & points)
{
	srand (time(NULL));
	if(K > total_points)
		return;

	std::vector<int> prohibited_indexes;

	// Escolhe K valores distintos para o centro do cluster
	for(int i = 0; i < K; i++)
	{
		while(true)
		{
			int index_point = rand() % total_points;

			if(std::find(prohibited_indexes.begin(), prohibited_indexes.end(),index_point) == prohibited_indexes.end())
			{
				prohibited_indexes.push_back(index_point);
				points[index_point].setCluster(i);
				Cluster cluster(i, points[index_point]);
				clusters.push_back(cluster);
				break;
			}
		}
	}

	int iter = 1;

	while(true)
	{
		bool done = true;

		// Associa cada ponto ao centro
		for(int i = 0; i < total_points; i++)
		{
			int id_old_cluster = points[i].getCluster();
			int id_nearest_center = getIDNearestCenter(points[i]);

			if(id_old_cluster != id_nearest_center)
			{
				if(id_old_cluster != -1)
					clusters[id_old_cluster].removePoint(points[i].getID());

				points[i].setCluster(id_nearest_center);
				clusters[id_nearest_center].addPoint(points[i]);
				done = false;
			}
		}

		// Recalcula o centro de cada cluster
		for(int i = 0; i < K; i++)
		{
			for(int j = 0; j < total_values; j++)
			{
				int total_points_cluster = clusters[i].getTotalPoints();
				double sum = 0.0;

				if(total_points_cluster > 0)
				{
					for(int p = 0; p < total_points_cluster; p++)
						sum += clusters[i].getPoint(p).getValue(j);
					clusters[i].setCentralValue(j, sum / total_points_cluster);
				}
			}
		}

		if(done == true || iter >= 100)
		{
			std::cout << "Break in iteration " << iter << "\n\n";
			break;
		}

		iter++;
	}

	// Mostra os elementos do cluster
	for(int i = 0; i < K; i++)
	{
		int total_points_cluster =  clusters[i].getTotalPoints();

		std::cout << "Cluster " << clusters[i].getID() + 1 << std::endl;
		for(int j = 0; j < total_points_cluster; j++)
		{
		/*	std::cout << "Point " << clusters[i].getPoint(j).getID() + 1 << ": ";
			for(int p = 0; p < total_values; p++)
				std::cout << clusters[i].getPoint(j).getValue(p) << " " << std::endl; */
		}

		std::cout << "Cluster values: ";

		for(int j = 0; j < total_values; j++)
			std::cout << clusters[i].getCentralValue(j) << " ";

		std::cout << "\n\n";
	}
}
