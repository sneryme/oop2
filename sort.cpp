#include "sort.h"

Sort::Sort()
{

}

void Sort::read_stolb(QString stolb, QList<Region>* list){
    for(int i=0;i<list->size();i++){
        sort_list.append(list->at(i).getString(stolb));
    }
    sort(sort_list.begin(),sort_list.end());
    min = sort_list.at(0);
    max = sort_list.at(sort_list.size()-1);
    if (sort_list.size()%2 == 1)
        median = sort_list.at(sort_list.size()/2);
    else
        median = (sort_list.at(sort_list.size() / 2)+ sort_list.at((sort_list.size() / 2)+1))/2;
}

double Sort::getMin(){
    return min;
}

double Sort::getMax(){
    return max;
}

double Sort::getMedian(){
    return median;
}
