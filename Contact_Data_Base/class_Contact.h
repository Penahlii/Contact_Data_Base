#pragma once

class Contact
{
	string name;
	string surname;
	string phone_number;
	string adress;
	string email;

public:

	// Constructors

	Contact() {}
	Contact(const string name, const string phone_number)
	{
		this->set_name(name);
		this->set_phone_number(phone_number);
	}

	Contact(const string name, const string surname, const string phone_number) : Contact(name, phone_number) { this->set_surname(surname); }

	Contact(const string name, const string surname, const string phone_number, const string adress) : Contact(name, surname, phone_number) { this->set_adress(adress); }
	
	Contact(const string name, const string surname, const string phone_number, const string adress, const string email) : Contact(name, surname, phone_number, adress) { this->set_email(email); }

	// Copy Constructor

	Contact(const Contact& other)
	{
		this->set_name(other.name);
		this->set_surname(other.surname);
		this->set_phone_number(other.phone_number);
		this->set_adress(other.adress);
		this->set_email(other.email);
	}

	// Copy Assigment Operator

	Contact& operator=(const Contact& other)
	{
		this->set_name(other.name);
		this->set_surname(other.surname);
		this->set_phone_number(other.phone_number);
		this->set_adress(other.adress);
		this->set_email(other.email);

		return *this;
	}

	// Set Methods

	void set_name(const string name)
	{
		if (name.length() >= 3 && name.length() <= 16)
			this->name = name;
		else
			throw InvalidArugmentException("Invalid Name (lenght must be at least 3 and max 16", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void set_surname(const string surname)

	{
		if (surname.length() >= 4 && surname.length() <= 16)
			this->surname = surname;
		else
			throw InvalidArugmentException("Invalid SurName (lenght must be at least 4 and max 16)", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void set_phone_number(const string phone_number)
	{
		if (phone_number.length() >= 8)
			this->phone_number = phone_number;
		else
			throw InvalidArugmentException("Invalid Phone Number (lenght must be more than 8)", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void set_adress(const string adress)
	{
		if (adress.length() >= 3)
			this->adress = adress;
		else
			throw InvalidArugmentException("Invalid Adress (lenght must be at least 3)", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void set_email(const string email)
	{
		if (email.length() >= 10)
			this->email = email;
		else
			throw InvalidArugmentException("Invalid Email (lenght must be at least 10 Digits)", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	// Get Methods

	inline const string get_name() const { return this->name; }
	inline const string get_surname() const { return this->surname; }
	inline const string get_phone_number() const { return this->phone_number; }
	inline const string get_adress() const { return this->adress; }
	inline const string get_email() const { return this->email; }

	// Show

	void show() const
	{
		cout << "Name: " << this->name << endl;
		cout << "Surname: " << this->surname << endl;
		cout << "Phone Number: " << this->phone_number << endl;
		cout << "Adress: " << this->adress << endl;
		cout << "Email: " << this->email << endl;
	}

	// cout

	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend ostream& operator<<(ostream& os, const Contact* contact);
};

// cout

ostream& operator<<(ostream& os, const Contact& contact)
{
	contact.show();

	return os;
}

ostream& operator<<(ostream& os, const Contact* contact)
{
	contact->show();

	return os;
}