#pragma once

#include <string>
#include <vector>

#include "Record.h"

class ProductRecord : Record {
private:
	std::string m_productID{};
	std::string m_name{};
	std::string m_description{};
	std::string m_price{};
	std::string m_quantity{};
	std::string m_status{};
	std::string m_supplierID{};

	static bool ValidateRecord();

public:
	ProductRecord(std::string productID, std::string name, std::string description, std::string price, std::string quantity, std::string status, std::string supplierID)
		: m_productID { productID }
		, m_name { name }
		, m_description { description }
		, m_price { price }
		, m_quantity { quantity }
		, m_status { status }
		, m_supplierID { supplierID }
	{
	}

	static std::vector<ProductRecord> CreateRecords(std::vector<std::vector<std::string>> productRecords);


	// getters
	std::string getProductID() const { return m_productID; }
	std::string getName() const { return m_name; }
	std::string getDescription() const { return m_description; }
	std::string getPrice() const { return m_price; }
	std::string getQuantity() const { return m_quantity; }
	std::string getStatus() const { return m_status; }
	std::string getSupplierID() const { return m_supplierID; }
};

inline bool ProductRecord::ValidateRecord() {

}

inline std::vector<ProductRecord> ProductRecord::CreateRecords(std::vector<std::vector<std::string>> productRecords) {

}