/**
 * @file    hash.h
 * @brief   Definição dos atributos e protótipos dos métodos da classe Hash.
 * @author  Eric Andrade Siqueira, Larissa Gilliane Melo De Moura, Luan Santos De Carvalho, Luís Eduardo Anunciado Silva, Renan Bezerra Kimura
 * @since   25/05/2017
 * @date    27/06/2017
 */
#ifndef __HASH_H__
#define __HASH_H__

#include "pointers.h"

/*Especializando do vector de float */
namespace std 
{
  template<> struct hash < std::vector<float> >
  {
    std::size_t operator()(std::vector<float> const& v) const
    {
      std::size_t h1 (std::hash<float>{}(v[0]));
      std::size_t h2 = 0;
      for (size_t i = 1; i < v.size(); i++) {
        h2 = std::hash<float>()(v[i]);
        h1 = h1 ^ h2;
      }
      return h1 ^ (h2 << 1);
    }
  };

/*Especializando da classe Point e Cluster para unordered_set (só funciona se as classes tiverem método de igualdade) */
  template<> struct hash <Point>
  {
    std::size_t operator()(Point const& p) const
    {
      std::size_t const h1 ( std::hash<int>{}(p.id_point) );
      std::size_t const h2 ( std::hash<int>{}(p.id_cluster) );
      std::size_t const h3 ( std::hash<int>{}(p.total_values) );
      std::size_t const h4 ( std::hash< std::vector<float> >{}(p.values) );
      /* Combina os valores das hashs dos elementos internos da classe usando a operação XOR
      e logo após é feito um deslocamento de bits, para determinar o valor da hash na tabela de dispersão*/
      return h1 ^ h2 ^ h3 ^ (h4 << 1);

    }
  };
}

#endif /* __HASH_H__ */
