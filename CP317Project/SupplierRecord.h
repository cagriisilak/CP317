#pragma once

#include <string>
#include <vector>

#include "Record.h"

class SupplierRecord : Record {
private:
	std::string m_ID{};
	std::string m_name{};
	std::string m_address{};
	std::string m_phone{};
	std::string m_email{};

	static bool ValidateRecord();

public:
	SupplierRecord(std::string ID, std::string name, std::string address, std::string phone, std::string email)
		: m_ID{ ID }
		, m_name{ name }
		, m_address{ address }
		, m_phone{ phone }
		, m_email{ email }
	{
	}


	static std::vector<SupplierRecord> CreateRecords(std::vector<std::vector<std::string>> supplierRecords);

	// getters
	std::string getID() const { return m_ID; }
	std::string getName() const { return m_name; }
	std::string getAddress() const { return m_address; }
	std::string getPhone() const { return m_phone; }
	std::string getEmail() const { return m_email; }
};

inline bool SupplierRecord::ValidateRecord() {

}

inline std::vector<SupplierRecord> SupplierRecord::CreateRecords(std::vector<std::vector<std::string>> supplierRecords) {

}