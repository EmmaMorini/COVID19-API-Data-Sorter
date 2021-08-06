/*
 * Main function for the program.
 * Stores country objects in a vector, then sorts them and prints a graph based on user input.
 * 10-07-2020
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include "Country.h"

using namespace std;

/* ************************************************************ */
// Sorting methods declarations (sorting functions for Sort() function) - ascending
bool sortByNewConfA(Country lhs, Country rhs);
bool sortByNewDeathsA(Country lhs, Country rhs);
bool sortByNewRecovA(Country lhs, Country rhs);
bool sortByTotalConfA(Country lhs, Country rhs);
bool sortByTotalDeathsA(Country lhs, Country rhs);
bool sortByTotalRecovA(Country lhs, Country rhs);

// Sorting methods declarations (sorting functions for Sort() function) - descending
bool sortByNewConfD(Country lhs, Country rhs);
bool sortByNewDeathsD(Country lhs, Country rhs);
bool sortByNewRecovD(Country lhs, Country rhs);
bool sortByTotalConfD(Country lhs, Country rhs);
bool sortByTotalDeathsD(Country lhs, Country rhs);
bool sortByTotalRecovD(Country lhs, Country rhs);
/* ************************************************************ */

int main() {
    vector<Country> records;
    string fileName;        //Variable used to store the name of the file to be opened provided by the user
    string line;            //Line of text retrieved from the file
    ifstream file;          //ifstream variable for handling the file

    //Variables for tokenizing each line from the file
    string token;
    string formatToken;

    //Get name of file from user
    cout << "Input the name of the file you wish to open: ";
    getline(cin, fileName);         //Assign variable fileName to the file provided by the user

    //Open and parse file
    try {
        file.open(fileName);
        if (file.fail()) {
            cerr << "Could not open file." << endl;
            return 0;
        }

        if (file.is_open()) {
            getline(file, line);            //Get rid of first line of file (it contains no data)
            while (getline(file, line)) {   // Retrieve line from file
                stringstream ss(line);
                vector<string> tokens;

                // Tokenize the line retrieved from the file
                if (ss.get() == '"') {
                    // Retrieve country name (This accounts for country names that contain commas)
                    getline(ss, token, '"');
                    formatToken = '"' + token + '"';        // Add quotation marks back into country name
                    tokens.push_back(formatToken);          // Push country name token into this country's tokens vector
                    ss.get();                               // Get rid of space after country name that was just retrieved from line
                }

                // Tokenize the rest of the string (i.e. line from the file)
                while (getline(ss, token, ',')) {
                    tokens.push_back(token);
                }

                // Create country record
                Country countryRecord(tokens[0], tokens[1], stoi(tokens[3]),
                                      stoi(tokens[4]), stoi(tokens[5]),
                                      stoi(tokens[8]), stoi(tokens[9]), stoi(tokens[10]));

                records.push_back(countryRecord);   // Put country record in records vector

            }
        }

    }
        //If an exception occurs when attempting to open the file, catch it and print an error message
    catch (const ifstream::failure &e) {
        cerr << "Caught an ifstream::failure" << endl;
        cerr << "Explanatory string: " << e.what() << endl;
    }

    file.close();   // Close file

    // Set up menu to display to user
    string userInput;
    bool on = true;
    int userChoice;
    string dataField;   // Data field to sort by
    string order;       // Ascending or descending order

    // Choose which data field to sort by
    while (on) {
        cout << "********************" << endl;
        cout << "Which data field would you like to sort by?" << endl;
        cout << "1 - New confirmed cases" << endl;
        cout << "2 - New deaths" << endl;
        cout << "3 - New recovered cases" << endl;
        cout << "4 - Total confirmed cases" << endl;
        cout << "5 - Total deaths" << endl;
        cout << "6 - Total recovered cases" << endl;
        cout << "Enter your selection and press return: ";
        cin >> userInput;
        userChoice = stoi(userInput);

        switch (userChoice) {
            case 1:
                dataField = "newConfirmed";
                on = false;
                break;
            case 2:
                dataField = "newDeaths";
                on = false;
                break;
            case 3:
                dataField = "newRecovered";
                on = false;
                break;
            case 4:
                dataField = "totalConfirmed";
                on = false;
                break;
            case 5:
                dataField = "totalDeaths";
                on = false;
                break;
            case 6:
                dataField = "totalRecovered";
                on = false;
                break;
            default:
                // Handle any invalid input from user and prompt them to try again
                cout << "Not a valid selection. Please enter your selection." << endl;
                break;
        }

    }

    on = true;  // Reset bool variable

    // Choose whether to sort in ascending or descending order
    while (on) {
        cout << "********************" << endl;
        cout << "Would you like to sort the data in ascending or descending order?" << endl;
        cout << "1 - Ascending" << endl;
        cout << "2 - Descending" << endl;
        cout << "Enter your selection and press return: ";
        cin >> userInput;
        userChoice = stoi(userInput);

        switch (userChoice) {
            case 1:
                order = "ascending";
                on = false;

                // Sort vector in ascending order (based on data field chosen above)
                if (dataField == "newConfirmed") {
                    sort(records.begin(), records.end(), sortByNewConfA);
                } else if (dataField == "newDeaths") {
                    sort(records.begin(), records.end(), sortByNewDeathsA);
                } else if (dataField == "newRecovered") {
                    sort(records.begin(), records.end(), sortByNewRecovA);
                } else if (dataField == "totalConfirmed") {
                    sort(records.begin(), records.end(), sortByTotalConfA);
                } else if (dataField == "totalDeaths") {
                    sort(records.begin(), records.end(), sortByTotalDeathsA);
                } else if (dataField == "totalRecovered") {
                    sort(records.begin(), records.end(), sortByTotalRecovA);
                }
                break;
            case 2:
                order = "descending";
                on = false;

                // Sort vector in descending order (based on data field chosen above)
                if (dataField == "newConfirmed") {
                    sort(records.begin(), records.end(), sortByNewConfD);
                } else if (dataField == "newDeaths") {
                    sort(records.begin(), records.end(), sortByNewDeathsD);
                } else if (dataField == "newRecovered") {
                    sort(records.begin(), records.end(), sortByNewRecovD);
                } else if (dataField == "totalConfirmed") {
                    sort(records.begin(), records.end(), sortByTotalConfD);
                } else if (dataField == "totalDeaths") {
                    sort(records.begin(), records.end(), sortByTotalDeathsD);
                } else if (dataField == "totalRecovered") {
                    sort(records.begin(), records.end(), sortByTotalRecovD);
                }
                break;
            default:
                // Handle any invalid input from user and prompt them to try again
                cout << "Not a valid selection. Please enter your selection." << endl;
                break;
        }
    }

    // Print graph

    // Declare necessary variables
    int maxChars;       // Longest bar on graph
    int maxVal;         // Maximum data value on graph
    int casesPerChar;   // Number of cases/deaths each '#' represents
    int barLength;      // Number of '#' to print (i.e. length of each bar)
    string graphData;   // Data field graph is displaying (e.g. New confirmed cases)

    maxChars = 70;      // Longest bar in each graph will be 70 characters long

    if (dataField == "newConfirmed") {                  // Case 1: Display new confirmed cases

        if (order == "ascending") {                     // Ascending order
            maxVal = records[9].getNewConfirmed();      // Determine largest value represented on graph
            if (maxVal < 70) {      // If the largest value on the graph is less than 70
                casesPerChar = 1;   // Set each '#' to equal 1
                maxChars = maxVal;  // The longest bar in the graph will be equal to the largest data value (which is under 70)
            } else {
                casesPerChar = round((double) records[9].getNewConfirmed() / maxChars); // Set scale for graph bars
            }
        } else {                                        // Descending order
            maxVal = records[0].getNewConfirmed();      // Comments above apply here as well as to the next five cases
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[0].getNewConfirmed() / maxChars);
            }
        }

        for (size_t i = 0; i < 10; i++) {
            cout << records[i].getCountryCode() << " | ";
            barLength = round(((double) records[i].getNewConfirmed() / (double) maxVal) *
                              maxChars); // Calculate bar length for Country

            // Print bar
            for (int j = 0; j < barLength; j++) {
                cout << "#";
            }
            cout << endl;
        }
        graphData = "New Confirmed Cases; ";

    } else if (dataField == "newDeaths") {      // Case 2: Display new deaths
        if (order == "ascending") {             // Ascending order
            maxVal = records[9].getNewDeaths();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[9].getNewDeaths() / maxChars);
            }
        } else {                                // Descending order
            maxVal = records[0].getNewDeaths();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[0].getNewDeaths() / maxChars);
            }
        }

        for (size_t i = 0; i < 10; i++) {
            cout << records[i].getCountryCode() << " | ";
            barLength = round(((double) records[i].getNewDeaths() / (double) maxVal) *
                              maxChars); // Calculate how long to make bar of current Country

            // Print bar
            for (int j = 0; j < barLength; j++) {
                cout << "#";
            }
            cout << endl;
        }

        graphData = "New Deaths; ";

    } else if (dataField == "newRecovered") {      // Case 3: Display new recovered cases
        if (order == "ascending") {                // Ascending order
            maxVal = records[9].getNewRecovered();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[9].getNewRecovered() / maxChars);
            }
        } else {                                   // Descending order
            maxVal = records[0].getNewRecovered();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[0].getNewRecovered() / maxChars);
            }
        }

        for (size_t i = 0; i < 10; i++) {
            cout << records[i].getCountryCode() << " | ";
            barLength = round(((double) records[i].getNewRecovered() / (double) maxVal) *
                              maxChars); // Calculate how long to make bar of current Country

            // Print bar
            for (int j = 0; j < barLength; j++) {
                cout << "#";
            }
            cout << endl;
        }
        graphData = "New Recovered Cases; ";

    } else if (dataField == "totalConfirmed") {      // Case 4: Display total confirmed cases
        if (order == "ascending") {                 // Ascending order
            maxVal = records[9].getTotalConfirmed();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[9].getTotalConfirmed() / maxChars);
            }
        } else {                                    // Descending order
            maxVal = records[0].getTotalConfirmed();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[0].getTotalConfirmed() / maxChars);
            }
        }

        for (size_t i = 0; i < 10; i++) {
            cout << records[i].getCountryCode() << " | ";
            barLength = round(((double) records[i].getTotalConfirmed() / (double) maxVal) *
                              maxChars); // Calculate how long to make bar of current Country

            // Print bar
            for (int j = 0; j < barLength; j++) {
                cout << "#";
            }
            cout << endl;
        }
        graphData = "Total Confirmed Cases; ";

    } else if (dataField == "totalDeaths") {      // Case 5: Display total deaths
        if (order == "ascending") {               // Ascending order
            maxVal = records[9].getTotalDeaths();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[9].getTotalDeaths() / maxChars);
            }
        } else {                                  // Descending order
            maxVal = records[0].getTotalDeaths();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[0].getTotalDeaths() / maxChars);
            }
        }

        for (size_t i = 0; i < 10; i++) {
            cout << records[i].getCountryCode() << " | ";
            barLength = round(((double) records[i].getTotalDeaths() / (double) maxVal) *
                              maxChars); // Calculate how long to make bar of current Country

            // Print bar
            for (int j = 0; j < barLength; j++) {
                cout << "#";
            }
            cout << endl;
        }
        graphData = "Total Deaths; ";

    } else if (dataField == "totalRecovered") {      // Case 6: Display total recovered cases
        if (order == "ascending") {                  // Ascending order
            maxVal = records[9].getTotalRecovered();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[9].getTotalRecovered() / maxChars);
            }
        } else {                                    // Descending order
            maxVal = records[0].getTotalRecovered();
            if (maxVal < 70) {
                casesPerChar = 1;
                maxChars = maxVal;
            } else {
                casesPerChar = round((double) records[0].getTotalRecovered() / maxChars);
            }
        }

        for (size_t i = 0; i < 10; i++) {
            cout << records[i].getCountryCode() << " | ";
            barLength = round(((double) records[i].getTotalRecovered() / (double) maxVal) *
                              maxChars); // Calculate how long to make bar of current Country

            // Print bar
            for (int j = 0; j < barLength; j++) {
                cout << "#";
            }
            cout << endl;
        }
        graphData = "Total Recovered Cases; ";
    }

    for (int i = 0; i < 80; i++) {      // Print line between graph and legend
        cout << "-";
    }
    cout << endl;
    cout << graphData << "Each # is approx. " << casesPerChar << " cases" << endl;      // Print legend

    return 0;
}

/* ************************************************************ */
// Sorting methods implementations (sorting functions for Sort() function) - ascending

bool sortByNewConfA(Country lhs, Country rhs) {

    return lhs.getNewConfirmed() < rhs.getNewConfirmed();
}

bool sortByNewDeathsA(Country lhs, Country rhs) {
    return lhs.getNewDeaths() < rhs.getNewDeaths();
}

bool sortByNewRecovA(Country lhs, Country rhs) {
    return lhs.getNewRecovered() < rhs.getNewRecovered();
}

bool sortByTotalConfA(Country lhs, Country rhs) {
    return lhs.getTotalConfirmed() < rhs.getTotalConfirmed();
}

bool sortByTotalDeathsA(Country lhs, Country rhs) {
    return lhs.getTotalDeaths() < rhs.getTotalDeaths();
}

bool sortByTotalRecovA(Country lhs, Country rhs) {
    return lhs.getTotalRecovered() < rhs.getTotalRecovered();
}

// Sorting methods implementations (sorting functions for Sort() function) - descending
bool sortByNewConfD(Country lhs, Country rhs) {
    return lhs.getNewConfirmed() > rhs.getNewConfirmed();
}

bool sortByNewDeathsD(Country lhs, Country rhs) {
    return lhs.getNewDeaths() > rhs.getNewDeaths();
}

bool sortByNewRecovD(Country lhs, Country rhs) {
    return lhs.getNewRecovered() > rhs.getNewRecovered();
}

bool sortByTotalConfD(Country lhs, Country rhs) {
    return lhs.getTotalConfirmed() > rhs.getTotalConfirmed();
}

bool sortByTotalDeathsD(Country lhs, Country rhs) {
    return lhs.getTotalDeaths() > rhs.getTotalDeaths();
}

bool sortByTotalRecovD(Country lhs, Country rhs) {
    return lhs.getTotalRecovered() > rhs.getTotalRecovered();
}
/* ************************************************************ */
