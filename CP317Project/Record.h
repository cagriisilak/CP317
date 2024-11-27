#pragma once

class Record {
protected:
	// functions to validate records go here
		// things like valid email, phone, ID, etc.

	virtual bool ValidateRecord() = 0;

};
