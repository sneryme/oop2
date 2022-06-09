#include "region.h"

Region::Region()
{

}
Region::Region(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization){
    _year = year;
    _region = region;
    _npg = npg;
    _birth_rate = birth_rate;
    _death_rate = death_rate;
    _gdw = gdw;
    _urbanization = urbanization;
}

void Region::setYear(const int &value)
{
    _year = value;
}

int Region::getYear() const
{
    return _year;
}

void Region::setRegion(const QString &value)
{
    _region=value;
}

QString Region::getRegion() const
{
    return _region;
}

void Region::setNpg(const double &value)
{
    _npg=value;
}

double Region::getNpg() const
{
    return _npg;
}

void Region::setbirth_rate(const double &value)
{
    _birth_rate=value;
}

double Region::getbirth_rate() const
{
    return _birth_rate;
}

void Region::setdeath_rate(const double &value)
{
    _death_rate=value;
}

double Region::getdeath_rate() const
{
    return _death_rate;
}

void Region::setGdw(const double &value)
{
    _gdw=value;
}

double Region::getGdw() const
{
    return _gdw;
}

void Region::seturbanization(const double &value)
{
    _urbanization=value;
}

double Region::geturbanization() const
{
    return _urbanization;
}

double Region::getString(QString stolb) const{
    if(stolb.toLower()=="npg")
        return this->getNpg();
    else if(stolb.toLower()=="birth rate")
        return this-> getbirth_rate();
    else if(stolb.toLower()=="death rate")
        return this->getdeath_rate();
    else if(stolb.toLower()=="gdw")
        return this->getGdw();
    else if(stolb.toLower()=="urbanization")
        return this->geturbanization();
    else
        return -1;
}
