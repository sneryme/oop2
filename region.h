#ifndef REGION_H
#define REGION_H
#include <QString>


class Region
{
public:
    Region();
    Region(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization);
    void setYear(const int &value );
    int getYear() const;
    void setRegion(const QString &value );
    QString getRegion() const;
    void setNpg(const double &value );
    double getNpg() const;
    void setbirth_rate(const double &value );
    double getbirth_rate() const;
    void setdeath_rate(const double &value );
    double getdeath_rate() const;
    void setGdw(const double &value );
    double getGdw() const;
    void seturbanization(const double &value );
    double geturbanization() const;
    double getString(QString stolb) const;
private:
    int _year;
    QString _region;
    double _npg;
    double _birth_rate;
    double _death_rate;
    double _gdw;
    double _urbanization;
};


#endif // REGION_H
