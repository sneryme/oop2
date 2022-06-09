#include "read_file.h"

read_file::read_file(string file_path, string region, QList<Region>* list)
{
    this->lists = list;
    this-> file_path = file_path;
    this-> region = region;
}

read_file::~read_file(){
    delete lists;
}

int read_file::Read_file() {
    fstream file(file_path);
    if (file.is_open()){
        int j=0;
            string str, str_shapka;
            getline(file, str_shapka, '\n');
            string inregion;
            while (getline(file, str, '\n')) {
                stringstream inputt(str);
                string mas[7];
                int i = 0;
                while (getline(inputt, mas[i], ','))
                    i++;
                if (mas[0] != "" && mas[1] != "" && mas[2] != "" && mas[3] != "" && mas[4] != "" && mas[5] != "" && mas[6] != "" && mas[1] == region)
                    lists->append({stoi(mas[0]),QString::fromStdString(mas[1]),stod(mas[2]),stod(mas[3]),stod(mas[4]),stod(mas[5]),stod(mas[6])});
                else
                    qDebug("обнаружено неверное значение");
            }
        //    sort();
        }else
          return -1;
    file.close();

    return 0;
}


/*
void read_file::sort() {
    string stolb;

    vector<double> vector_stolb;
    for (size_t i = 0; i < lists.size(); i++)
    {
        switch (stoi(stolb))
        {
        case(3): {
            vector_stolb.push_back(getNpg());
            break;
        }
        case(4): {
            vector_stolb.push_back(lists[i]._birth_rate);
            break;
        }
        case(5): {
            vector_stolb.push_back(lists[i]._death_rate);
            break;
        }
        case(6): {
            vector_stolb.push_back(lists[i]._gdw);
            break;
        }
        case(7): {
            vector_stolb.push_back(lists[i]._urbanization);
            break;
        }
        default:
            exit(1);
            break;
        }
    }
    for (int i = 0; i < vector_stolb.size(); i++)
        cout << vector_stolb[i]<<endl;
    double* mas=mediana_min_max(vector_stolb);
    cout << mas[0] << " " << mas[1] << " " << mas[2] << " ";
}

double* mediana_min_max(vector <double> vector_sort) {
    sort(vector_sort.begin(), vector_sort.end());
    double mas[3];
    mas[0] = vector_sort[0];
    mas[1] = vector_sort[vector_sort.size()-1];
    if(vector_sort.size()%2==1)
        mas[2] = vector_sort[vector_sort.size()/2];
    else
        mas[2] = (vector_sort[(vector_sort.size() / 2)]+ vector_sort[(vector_sort.size() / 2)+1])/2;
    return mas;
}
*/
