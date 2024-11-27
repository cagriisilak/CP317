#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#include "InventoryRecord.h"
#include "SupplierRecord.h"
#include "ProductRecord.h"

class FileHandler {
private:
	static std::vector<std::string> ParseLine(std::string line);
	static std::vector<std::vector<std::string>> ProcessFile(std::ifstream& file);

public:
	static void Merge(std::ifstream& supplierFile, std::ifstream& productFile, std::ofstream& inventoryFile);

};

inline void FileHandler::Merge(std::ifstream& supplierFile, std::ifstream& productFile, std::ofstream& inventoryFile) {

	// process 2 input files
	auto supplierRecords = ProcessFile(supplierFile);
	auto productRecords = ProcessFile(productFile);

	// convert to (Supplier/Product)Record array
	auto suppliers = SupplierRecord::CreateRecords(supplierRecords);
	auto products = ProductRecord::CreateRecords(productRecords);

	// sort supplier/product records based on supplierID in ascending order
	std::sort(supplierRecords.begin(), supplierRecords.end(), [](const SupplierRecord& a, const SupplierRecord& b) { return (a.getID() < b.getID()); });
	std::sort(productRecords.begin(), productRecords.end(), [](const ProductRecord& a, const ProductRecord& b) { return (a.getSupplierID() < b.getSupplierID()); });

	// merge supplier/product records to create inventory records
	auto inventoryRecords = InventoryRecord::CreateRecords(suppliers, products);

	// sort inventory records based off productID in ascending order
	std::sort(inventoryRecords.begin(), inventoryRecords.end(), [](const InventoryRecord& a, const InventoryRecord& b) { return (a.getProductID() < b.getProductID()); });

	// write inventory records to file
	for (auto& record : inventoryRecords) {
		inventoryFile
			<< record.getProductID() << ", "
			<< record.getproductName() << ", "
			<< record.getQuantity() << ", "
			<< record.getPrice() << ", "
			<< record.getStatus() << ", "
			<< record.getSupplierName()
			<< std::endl;
	}
}

inline std::vector<std::vector<std::string>> FileHandler::ProcessFile(std::ifstream& file) {

	std::vector<std::vector<std::string>> records;
	std::string line;
	std::vector<std::string> parsedLine;
	
	while (getline(file, line)) {
		parsedLine = ParseLine(line);
		records.push_back(parsedLine);
	}

	return records;
}

inline std::vector<std::string> FileHandler::ParseLine(std::string line) {
	std::vector<std::string> parsedLine;
	std::stringstream sstr(line);

	
	while (sstr.good())
	{
		std::string substr;

		// split by comma ','
		getline(sstr, substr, ',');

		substr.erase(0, substr.find_first_not_of(' ')); // remove leading spaces
		substr.erase(substr.find_last_not_of(' ') + 1); // remove trailing spaces

		parsedLine.push_back(substr);
	}

	return parsedLine;
}