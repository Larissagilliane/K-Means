/**
 * @file    sets.h
 * @brief   Definição dos atributos e protótipos dos métodos da classe Set.
 * @author  Eric Andrade Siqueira, Larissa Gilliane Melo De Moura, Luan Santos De Carvalho, Luís Eduardo Anunciado Silva, Renan Bezerra Kimura
 * @since   25/05/2017
 * @date    27/06/2017
 */
#ifndef __SETS_H__
#define __SETS_H__

#include "pointers.h"

/**
 * @class   Set sets.h
 * @brief   Classe usada para para fazer a leitura e conversão dos dataframes recebidos
 * @details O atributo é: us do tipo unordered_set
 */
template <typename T> class Set
{
private:
  /* Classe "unordered_set" encapsulada. */
  std::unordered_set <T> us;
public:
  Set();
  ~Set();
  void print();
  void insertion(T data);
  void clear(T data);
  bool pertinancy(T data);
  Set <T> junction(Set A);
  Set <T> difference(Set A);
  Set <T> intersection(Set A);
  bool compare(Set A);
  std::vector <Point> conversion();
};

/* Construtor e destrutor da classe. */
template <typename T>
Set<T>::Set() { }
template <typename T>
Set<T>::~Set() { }

/** @brief Impressão de cada vector
*   @return void
*/
template <typename T>
void Set<T>::print()
{
  for(const T & x: us)
  {
    for(size_t i = 0; i < x.size(); i++) std::cout << x[i] << "\t";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

/** @brief Inserção das observações no conjunto
*   @param data Observação
*   @return void
*/
template <typename T>
void Set<T>::insertion(T data)
{
	us.insert(data);
}

/** @brief Remoção das observações no conjunto
*   @param data Observação
*   @return void
*/
template <typename T>
void Set<T>::clear(T data)
{
	us.erase(data);
}

/** @brief Confere ser a observação está presente no conjunto
*   @param data Observação
*   @return bool , true se ele estiver e false caso se ele não estiver
*/
template <typename T>
bool Set<T>::pertinancy(T data)
{
  typename std::unordered_set<T>::const_iterator got = us.find(data);
  if (got == us.end()) return false;
  return true;
}

/** @brief Será feito a união entre o conjunto A e B
*   @param A Conjunto dado
*   @return Set , Retorna o conjunto com a união
*/
template <typename T>
Set <T> Set<T>::junction(Set <T> A)
{
  Set <T> B;
  B.us.insert(A.us.begin(), A.us.end());
  B.us.insert(us.begin(), us.end());
  return B;
}

/** @brief Será feito a diferença entre o conjunto A e B
*   @param A Conjunto dado
*   @return Set , Retorna o conjunto com a diferença
*/
template <typename T>
Set <T> Set<T>::difference(Set <T> A)
{
  Set <T> B;
  B.us.insert(us.begin(), us.end());
  for(const T & x: A.us) B.us.erase(x);
  return B;
}

/** @brief Será feito a intersecção entre o conjunto A e B
*   @param A Conjunto dado
*   @return Set , Retorna o conjunto com a intersecção
*/
template <typename T>
Set <T> Set<T>::intersection(Set <T> A)
{
  Set <T> B;
  for(const T & x: A.us)
  {
    if (us.find(x) != us.end()) B.us.insert(x);
  }
  return B;
}

/** @brief Será feito a comparação de igualdade 
*   @param A Conjunto dado
*   @return bool , true caso seja igual e false caso contrário
*/
template <typename T>
bool Set<T>::compare(Set <T> A)
{
  for(const T & x: A.us)
  {
    if (us.find(x) == us.end()) return false;
  }
  return true;
}

/** @brief Faz a conversão do unordered_set para um vector de Point
*   @return vector , com a conversão
*/
template <typename T>
std::vector <Point> Set<T>::conversion()
{
  std::vector <Point> output (us.begin(), us.end());
  return output;
}

#endif /* __SETS_H__ */
