#pragma once

#include <vector>
#include <string>

#include "SupplierRecord.h"
#include "ProductRecord.h"

class InventoryRecord {
private:
	std::string m_productID{};
	std::string m_productName{};
	std::string m_quantity{};
	std::string m_price{};
	std::string m_status{};
	std::string m_supplierName{};

public:
	InventoryRecord(std::string productID, std::string productName, std::string quantity, std::string price, std::string status, std::string supplierName)
		: m_productID{ productID }
		, m_productName{ productName }
		, m_quantity{ quantity }
		, m_price{ price }
		, m_status{ status }
		, m_supplierName{ supplierName }
	{
	}

	static std::vector<InventoryRecord> CreateRecords(const std::vector<SupplierRecord> suppliers, const std::vector<ProductRecord> products);

	// getters
	std::string getProductID() const { return m_productID; }
	std::string getproductName() const { return m_productName; }
	std::string getQuantity() const { return m_quantity; }
	std::string getPrice() const { return m_price; }
	std::string getStatus() const { return m_status; }
	std::string getSupplierName() const { return m_supplierName; }
};

inline std::vector<InventoryRecord> InventoryRecord::CreateRecords(const std::vector<SupplierRecord> suppliers, const std::vector<ProductRecord> products) {

	std::vector<InventoryRecord> inventoryRecords;

	int supplierIndex = 0, productIndex = 0;

	while (supplierIndex < suppliers.size()) {
		while (productIndex < products.size()) {
			if (suppliers[supplierIndex].getID() == products[productIndex].getSupplierID()) {
				InventoryRecord record = {
					products[productIndex].getProductID(),
					products[productIndex].getName(),
					products[productIndex].getQuantity(),
					products[productIndex].getPrice(),
					products[productIndex].getStatus(),
					suppliers[supplierIndex].getName()
				};
				inventoryRecords.push_back(record);
				productIndex++;
			}
			else supplierIndex++;
		}
		supplierIndex++;
	}

	return inventoryRecords;
}