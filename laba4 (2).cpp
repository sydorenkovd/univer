#include <iostream>

#define Min(a, b) ((a < b) ? a : b)

using namespace std;


unsigned short fix(const int * f, const unsigned short fSize, const int * s, const unsigned short sSize, int * r) {
  unsigned short
    i,
    j,
    count = 0;

  for (i = 0; i < fSize; i++)
    for (j = 0; j < sSize; j++)
      if (f[i] == s[j])
        r[count++] = f[i];

  return count;
}

int main() {
  int
    * firstSet = NULL,
    * secondSet = NULL,
    * resultSet = NULL;
  unsigned short
    i,
    firstCount = 0,
    secondCount = 0,
    resultCount = 0;

  cout << "Enter sets dimensions razmer_set: ";
  cin >> firstCount >> secondCount;
  resultCount = Min(firstCount, secondCount);

  if (firstCount && secondCount) {
    firstSet = new int [firstCount];
    secondSet = new int [secondCount];
    resultSet = new int [resultCount];

    cout << "\nVvedite first set\n";
    for (i = 0; i < firstCount; i++)
      cin >> firstSet[i];

    cout << "\nVvedite second set\n";
    for (i = 0; i < secondCount; i++)
      cin >> secondSet[i];

    resultCount = fix(firstSet, firstCount, secondSet, secondCount, resultSet);

    cout << "\n---Getted set peresechenie_set---\n";
    for (i = 0; i < resultCount; i++)
      cout << resultSet[i] << " ";

    if (firstSet)
      delete [] firstSet;
    if (secondSet)
      delete [] secondSet;
    if (resultSet)
      delete [] resultSet;
  }

  //---
  cout << "\n\n\tPress any key for exit...";

  getchar();
  return 0;
};
