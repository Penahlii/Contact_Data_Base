#pragma once

class Data_Base
{
	Contact** contacts;
	int contacts_size;

public:

	// Constructors

	Data_Base() {}
	Data_Base(Contact** contacts , int size) {}

	           //  Copy Constructor

	Data_Base(const Data_Base& other) { this->set_contacts(other.contacts, other.contacts_size); }

			  // Move Constructor

	Data_Base(Data_Base&& other)
	{
		this->set_contacts(other.contacts, other.contacts_size);
		other.contacts = nullptr;
		other.contacts_size = 0;
	}

	// Copy Assigment Operator

	Data_Base& operator= (const Data_Base& other)
	{
		this->set_contacts(other.contacts, other.contacts_size);

		return *this;
	}

	// Move Assigment Operator

	Data_Base& operator=(Data_Base&& other)
	{
		this->set_contacts(other.contacts, other.contacts_size);
		other.contacts = nullptr;
		other.contacts_size = 0;

		return *this;
	}

	// Set Method

	void set_contacts(Contact** contacts , int size)
	{
		if (contacts == nullptr)
			throw InvalidArugmentException("NULL Data", __DATE__, __TIME__, __FILE__, __LINE__);
		if (this->contacts != nullptr)
		{
			for (size_t i = 0; i < this->contacts_size; i++)
				delete this->contacts[i];
			delete[] this->contacts;
		}
		this->contacts = new Contact * [size];
		for (size_t i = 0; i < size; i++)
			this->contacts[i] = new Contact(contacts[i]->get_name(), contacts[i]->get_surname(), contacts[i]->get_phone_number(), contacts[i]->get_adress(), contacts[i]->get_email());
		this->contacts_size = size;
	}

	// Get Method

	inline Contact** get_contacts() const { return this->contacts; }
	inline int get_contacts_size() const { return this->contacts_size; }

	// + Methods

	void Add_Contact(Contact* new_contact)
	{
		for (size_t i = 0; i < this->contacts_size; i++)
		{
			if (this->contacts[i]->get_name() == new_contact->get_name())
				throw DataBaseException("Contact Exists", __DATE__, __TIME__, __FILE__, __LINE__);
		}
		Contact** new_contacts = new Contact * [this->contacts_size + 1];
		for (size_t i = 0; i < this->contacts_size; i++)
			new_contacts[i] = this->contacts[i];
		new_contacts[this->contacts_size] = new_contact;
		this->contacts_size++;
		delete[] this->contacts;
		this->contacts = new_contacts;
	}

	void Delete_By_Name(const string name)
	{
		int index = -1;
		for (size_t i = 0; i < this->contacts_size; i++)
		{
			if (this->contacts[i]->get_name() == name)
				index = i;
		}
		if (index == -1)
			throw DataBaseException("Contact Name Does not Exist", __DATE__, __TIME__, __FILE__, __LINE__);
		Contact** new_contacts = new Contact * [this->contacts_size - 1];
		for (size_t i = 0; i < index; i++)
			new_contacts[i] = this->contacts[i];
		for (size_t i = index; i < this->contacts_size; i++)
			new_contacts[i] = this->contacts[i + 1];
		this->contacts_size--;
		delete[] this->contacts;
		this->contacts = new_contacts;
	}

	Contact* Search_By_Name(const string name)
	{
		for (size_t i = 0; i < this->contacts_size; i++)
		{
			if (this->contacts[i]->get_name() == name)
				return this->contacts[i];
		}
		throw DataBaseException("Name Does Not Exist in Contacts", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	Contact* Search_By_Phone_Number(const string phone_number)
	{
		for (size_t i = 0; i < this->contacts_size; i++)
		{
			if (this->contacts[i]->get_phone_number() == phone_number)
				return this->contacts[i];
		}
		throw DataBaseException("Phone Number Does Not Exist in Contacts", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	// Show

	void show() const
	{
		cout << "\t\tContacts\n";
		if (this->contacts == nullptr)
		{
			cout << "There is not any Contact In Base Yet";
			return;
		}
		for (size_t i = 0; i < this->contacts_size; i++)
		{
			cout << i + 1 << ")";
			this->contacts[i]->show();
			cout << endl;
		}
	}

	// cout

	friend ostream& operator<<(ostream& os, const Data_Base& data_base);

	// Destructor

	~Data_Base()
	{
		if (this->contacts != nullptr)
		{
			for (size_t i = 0; i < this->contacts_size; i++)
				delete this->contacts[i];
			delete[] this->contacts;
		}
	}
};

// cout

ostream& operator<<(ostream& os, const Data_Base& data_base)
{
	data_base.show();

	return os;
}