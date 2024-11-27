#include <iostream>
#include <fstream>

#include "FileHandler.h"

int main() {
	// initialize input and output files
	std::ifstream supplierFile, productFile;
	std::ofstream inventoryFile;

	// open SupplierFile and ProductFile for reading
	supplierFile.open("SupplierFile.txt");
	productFile.open("ProductFile.txt");

	// open InventoryFile for overwriting existing contents
	inventoryFile.open("InventoryFile.txt", std::ios::trunc);

	// merge supplierFile and productFile to inventoryFile
	FileHandler::Merge(supplierFile, productFile, inventoryFile);

	// close all files
	supplierFile.close();
	productFile.close();
	inventoryFile.close();
}