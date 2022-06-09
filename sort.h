#ifndef SORT_H
#define SORT_H
#include <vector>
#include <string>
#include "region.h"
#include <stdlib.h>
#include <sort.h>
#include <QList>
#include <algorithm>
#include <QString>

using namespace std;
class Sort
{
public:
    Sort();
    double getMin();
    double getMax();
    double getMedian();
    void read_stolb(QString stolb, QList<Region>* list);
    QList<double> sort_list;
private:
    double min = 0;
    double max = 0;
    double median = 0;
};

#endif // SORT_H
