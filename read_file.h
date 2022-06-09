#ifndef READ_FILE_H
#define READ_FILE_H
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "region.h"
#include "model.h"

using namespace std;
class read_file
{
public:
    read_file(string file_path, string region, QList<Region>* list);
    ~read_file();
    int Read_file();
private:
    QList<Region>* lists;
    string file_path;
    string region;
    //void sort();
   // double* mediana_min_max(vector <double> vector_sort);
};

#endif // READ_FILE_H

