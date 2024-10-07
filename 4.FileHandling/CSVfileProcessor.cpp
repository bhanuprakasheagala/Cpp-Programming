/*
a program that can read a CSV (Comma-Separated Values) file, parse its contents, and perform some 
simple operations on the data, such as calculating the sum or average of a column.
In this example, Assume that the CSV file contains numeric values in each column.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& input, char delimeter){
    std::vector<std::string> result;
    std::istringstream stream(input);
    std::string token;
    while(std::getline(stream, token, delimeter)){
        result.push_back(token);
    }

    return result;
}

int main(){
    std::string fileName = "data.csv";
    int columnToCalculate = 1;  // Column to perform operations, zero-indexed
    
    // Open the csv file for reading
    std::ifstream file(fileName);

    if(!file.is_open()){
        std::cerr<<"Failed to open the CSV file: " << fileName << std::endl;
        return 1;
    }

    std::string line;
    double sum = 0.0;
    int rowCount = 0;

    // Read each line from CSV file
    while(std::getline(file, line)){

        // Split the line into columns based on comma delimeter
        std::vector<std::string> columns = split(line, ',');

        // Check if the specified column exists
        if(columnToCalculate >= 0 && columnToCalculate <= columns.size()){

            // Convert the value in the specified column to a double
            double value;
            std::istringstream(columns[columnToCalculate]) >> value;

            // Accumulatet the sum
            sum += value;

            // Increment the row count
            rowCount++;
        }
    } 

    // Calculate the average
    double avg = (rowCount > 0) ? (sum/rowCount) : 0.0;

    // Close the file
    file.close();

    std::cout << "Sum of column " << columnToCalculate << ": " << sum << std::endl;
    std::cout << "Avg of column " << columnToCalculate << ": " << avg << std::endl;

    return 0;
}