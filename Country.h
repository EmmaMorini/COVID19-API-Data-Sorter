/*
 * Header file for Country class. Declares data members and methods.
 * Country class represents a country from the Covid-19 API.
 * The data associated with the Country is stored in its private data members.
 * 10-07-2020
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

class Country {
private:
    std::string name;
    std::string countryCode;
    int newConfirmed;
    int newDeaths;
    int newRecovered;
    int totalConfirmed;
    int totalDeaths;
    int totalRecovered;

public:
    //Constructor
    Country(std::string name, std::string code, int inpNewConfirmed, int inpNewDeaths, int inpNewRecovered,
            int inpTotalConfirmed, int inpTotalDeaths, int inpTotalRecovered);

    //Setter methods
    void setName(std::string newName);
    void setCountryCode(std::string newCode);
    void setNewConfirmed(int countryNewConf);
    void setNewDeaths(int countryNewDeaths);
    void setNewRecovered(int countryNewRecovered);
    void setTotalConfirmed(int countryTotalConf);
    void setTotalDeaths(int countryTotalDeaths);
    void setTotalRecovered(int countryTotalRecovered);

    //Getter methods
    std::string getName();
    std::string getCountryCode();
    int getNewConfirmed();
    int getNewDeaths();
    int getNewRecovered();
    int getTotalConfirmed();
    int getTotalDeaths();
    int getTotalRecovered();

    //Destructor
    ~Country();
};
#endif //COUNTRY_H
