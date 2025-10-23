#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct SalesRecord {
    string month;
    float amount;
};

const int NUM_MONTHS = 12;
const string FILENAME = "sales_data.txt";

void readSalesData(SalesRecord records[]) {
    cout << "--- Enter Sales Data for 12 Months ---\n";
    
    for (int i = 0; i < NUM_MONTHS; ++i) {
        records[i].month = "Month" + to_string(i + 1); 
        cout << "Enter sales amount for " << records[i].month << ": Rs. ";
        cin >> records[i].amount;
    }
}

void writeDataToFile(const SalesRecord records[]) {
    ofstream outFile(FILENAME);

    if (outFile.is_open()) {
        for (int i = 0; i < NUM_MONTHS; ++i) {
            outFile << records[i].month << " " << records[i].amount << endl;
        }
        outFile.close();
        cout << "\n[File Operation] Successfully wrote "<<NUM_MONTHS<< " records to '" << FILENAME << "'.\n";
    } else {
        cout << "\n[Error] Unable to open file for writing: " << FILENAME << endl;
    }
}

void analyzeSalesFromFile() {
    ifstream inFile(FILENAME);
    SalesRecord records[NUM_MONTHS]; 
    float totalSales = 0.0f;
    int recordCount = 0;

    if (!inFile.is_open()) {
        cout << "\n[Error] Unable to open file for reading: " << FILENAME << ". Cannot perform analysis." << endl;
        return;
    }

    cout << "\n[File Operation] Reading data back from file...\n";
    while (inFile >> records[recordCount].month >> records[recordCount].amount) {
        totalSales += records[recordCount].amount;
        recordCount++;
        if (recordCount >= NUM_MONTHS) break;
    }
    inFile.close();

    if (recordCount != NUM_MONTHS) {
        cout << "[Warning] Expected " << NUM_MONTHS << " records but read " << recordCount << ". Analysis may be incomplete.\n";
        if (recordCount == 0) return;
    }

    float yearlyAverage = totalSales / recordCount;
    
    cout << "\n--- Sales Analysis ---\n";
    cout << "Total Sales: Rs. " << totalSales << endl;
    cout << "Yearly Average Sales: Rs. " << yearlyAverage << endl;
    cout << "----------------------\n";
    cout << "Months with sales above the yearly average (Rs. " << yearlyAverage << "):" << endl;
    
    bool foundAboveAverage = false;
    for (int i = 0; i < recordCount; ++i) {
        if (records[i].amount > yearlyAverage) {
            cout << records[i].month << ": Rs. " << records[i].amount << endl;
            foundAboveAverage = true;
        }
    }
    
    if (!foundAboveAverage) {
        cout << "No months recorded sales above the yearly average." << endl;
    }
}

int main() {
    
    SalesRecord monthlySales[NUM_MONTHS];
    readSalesData(monthlySales);
    writeDataToFile(monthlySales);
    analyzeSalesFromFile();
    cout << "\nProgram finished." << endl;
    return 0;
}
