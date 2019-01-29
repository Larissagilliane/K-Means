#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cassert>
#include "dataframe.h"
#include "hash.h"
#include "sets.h"
#include "pointers.h"
#include "cluster.h"
#include "kmeans.h"

int main (int argc, char * argv[])
{

  std::cout << "Testando a função de inserção no conjunto..." << std::endl;
  Set < std::vector <float> > A, B, C;
  std::vector <float> I1 = {1.0,2.2,3.5,4.1,5.9};
  std::vector <float> I2 = {1.3,2.3,3.3,42.1,5.9};
  std::vector <float> I3 = {4.3,7.3,8.3,24.1,9.9};
  A.insertion(I1);
  B.insertion(I1);
  assert(A.compare(B) == 1);
  A.insertion(I2);
  B.insertion(I3);
  assert(A.compare(B) == 0);
  A.insertion(I3);
  B.insertion(I2);
  assert(A.compare(B) == 1);
  std::cout << "Testando a função de remoção no conjunto..." << std::endl;
  A.clear(I1);
  B.clear(I1);
  assert(A.compare(B) == 1);
  A.clear(I2);
  B.clear(I3);
  assert(A.compare(B) == 0);
  A.clear(I3);
  B.clear(I2);
  assert(A.compare(B) == 1);
  std::cout << "Testando a função de pertinência no conjunto..." << std::endl;
  A.clear(I2);
  A.clear(I3);
  A.insertion(I1);
  assert(A.pertinancy(I1) == 1);
  assert(A.pertinancy(I2) == 0);
  assert(A.pertinancy(I3) == 0);
  A.insertion(I2);
  assert(A.pertinancy(I1) == 1);
  assert(A.pertinancy(I2) == 1);
  assert(A.pertinancy(I3) == 0);
  A.insertion(I3);
  assert(A.pertinancy(I1) == 1);
  assert(A.pertinancy(I2) == 1);
  assert(A.pertinancy(I3) == 1);
  std::cout << "Testando a função de união de conjuntos..." << std::endl;
  A.clear(I1);
  A.clear(I2);
  A.clear(I3);
  A.insertion(I1);
  A.insertion(I2);
  B.insertion(I1);
  B.insertion(I3);
  C.insertion(I1);
  C.insertion(I2);
  C.insertion(I3);
  Set < std::vector <float> > D = A.junction(B);
  assert(D.compare(C) == 1);
  D.clear(I3);
  assert(D.compare(C) == 0);
  C.clear(I3);
  assert(D.compare(C) == 1);
  std::cout << "Testando a função de diferença de conjuntos..." << std::endl;
  A.insertion(I3);
  B.clear(I1);
  Set < std::vector <float> > E = A.difference(B);
  assert(E.compare(C) == 1);
  E.clear(I1);
  assert(E.compare(C) == 0);
  C.clear(I1);
  assert(E.compare(C) == 1);
  std::cout << "Testando a função de intersecção de conjuntos..." << std::endl;
  C.clear(I2);
  C.insertion(I3);
  Set < std::vector <float> > F = A.intersection(B);
  assert(F.compare(C) == 1);
  return 0;

}
