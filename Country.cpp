/*
 * Country class represents a country and its associated data from the Covid-19 API.
 * Implements methods in Country.h
 * 10-07-2020
 */

#include "Country.h"
using namespace std;

//Constructor implementation
// Name: Country
// Input: 'inpName': a string - name of the country
//         'code': a string - country code
//         'inpNewConfirmed': an int - number of new confirmed cases
//         'inpNewDeaths': an int - number of new deaths
//         'inpNewRecovered': an int - number of new recovered cases
//         'inpTotalConfirmed': an int - number of total confirmed cases
//         'inpTotalDeaths': an int - number of total deaths
//         'inpTotalRecovered': an int - number of total recovered cases
// Effect: initialize member variables
// Output: N/A
Country::Country(string inpName, string code, int inpNewConfirmed, int inpNewDeaths, int inpNewRecovered,
        int inpTotalConfirmed, int inpTotalDeaths, int inpTotalRecovered) {
    Country::setName(inpName);
    Country::setCountryCode(code);
    Country::setNewConfirmed(inpNewConfirmed);
    Country::setNewDeaths(inpNewDeaths);
    Country::setNewRecovered(inpNewRecovered);
    Country::setTotalConfirmed(inpTotalConfirmed);
    Country::setTotalDeaths(inpTotalDeaths);
    Country::setTotalRecovered(inpTotalRecovered);
}

//Setter methods implementations

// Name: setName
// Input: 'newName': string - name of Country
// Effect: sets 'name' to equal 'newName'
// Output: void
void Country::setName(string newName) {
    Country::name = newName;
}

// Name: setCountryCode
// Input: 'newCode': string - Country code
// Effect: sets 'countryCode' to equal 'newCode'
// Output: void
void Country::setCountryCode(string newCode) {
    Country::countryCode = newCode;
}

// Name: setNewConfirmed
// Input: 'countryNewConf': int - number of new confirmed cases
// Effect: sets 'newConfirmed' to equal 'countryNewConf'
// Output: void
void Country::setNewConfirmed(int countryNewConf) {
    Country::newConfirmed = countryNewConf;
}

// Name: setNewDeaths
// Input: 'countryNewDeaths': int - number of new deaths
// Effect: sets 'newDeaths' to equal 'countryNewDeaths'
// Output: void
void Country::setNewDeaths(int countryNewDeaths) {
    Country::newDeaths = countryNewDeaths;
}

// Name: setNewRecovered
// Input: 'countryNewRecovered': int - new recovered cases
// Effect: sets 'newRecovered' to equal 'countryNewRecovered'
// Output: void
void Country::setNewRecovered(int countryNewRecovered) {
    Country::newRecovered = countryNewRecovered;
}

// Name: setTotalConfirmed
// Input: 'countryTotalConf': int - total confirmed cases
// Effect: sets 'totalConfirmed' to equal 'countryTotalConf'
// Output: void
void Country::setTotalConfirmed(int countryTotalConf) {
    Country::totalConfirmed = countryTotalConf;
}

// Name: setTotalDeaths
// Input: 'countryTotalDeaths': int - total deaths
// Effect: sets 'totalDeaths' to equal 'countryTotalDeaths'
// Output: void
void Country::setTotalDeaths(int countryTotalDeaths) {
    Country::totalDeaths = countryTotalDeaths;
}

// Name: setTotalRecovered
// Input: 'countryTotalRecovered': int - total recovered cases
// Effect: sets 'totalRecovered' to equal 'countryTotalRecovered'
// Output: void
void Country::setTotalRecovered(int countryTotalRecovered) {
    Country::totalRecovered = countryTotalRecovered;
}

//Getter methods implementations

// Name: getName
// Input: N/A
// Effect: get Country name
// Output: 'name': string - name of Country
string Country::getName() {
    return Country::name;
}

// Name: getCountryCode
// Input: N/A
// Effect: get Country code
// Output 'countryCode': string - Country code
string Country::getCountryCode() {
    return Country::countryCode;
}

// Name: getNewConfirmed
// Input: N/A
// Effect: get number of new confirmed cases
// Output: 'newConfirmed': int - number of new confirmed cases
int Country::getNewConfirmed() {
    return Country::newConfirmed;
}

// Name: getNewDeaths
// Input: N/A
// Effect: get number of new deaths
// Output: 'newDeaths': int - number of new deaths
int Country::getNewDeaths() {
    return Country::newDeaths;
}

// Name: getNewRecovered
// Input: N/A
// Effect: get number of new recovered cases
// Output: 'newRecovered': int - number of new recovered cases
int Country::getNewRecovered() {
    return Country::newRecovered;
}

// Name: getTotalConfirmed
// Input: N/A
// Effect: get number of total confirmed cases
// Output: 'totalConfirmed': int - number of total confirmed cases
int Country::getTotalConfirmed() {
    return Country::totalConfirmed;
}

// Name: getTotalDeaths
// Input: N/A
// Effect: get number of total deaths
// Output: 'totalDeaths': int - number of total deaths
int Country::getTotalDeaths() {
    return Country::totalDeaths;
}

// Name: getTotalRecovered
// Input: N/A
// Effect: get number of total recovered cases
// Output: 'totalRecovered': int - number of total recovered cases
int Country::getTotalRecovered() {
    return Country::totalRecovered;
}


//Destructor implementation
// Name: Country
// Input: N/A
// Effect: Destroys the Country object
// Output: N/A
Country::~Country() {}
