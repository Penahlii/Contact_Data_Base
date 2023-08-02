#pragma once

class StartUp
{
public:


	static void start()
	{
		int size = 2;
		Contact** contacts = new Contact * [size];

		contacts[0] = new Contact("Ibrahim", "Penahli", "552165985", "Baku Lokbatan", "penahliibrahim58@gmail.com");
		contacts[1] = new Contact("Orxan", "Memmedli", "776000007", "Baku Ecemi", "memmedliorxan55@gmail.com");

		Data_Base data_base(contacts, size);

		while (true)
		{
			system("cls");
			cout << "Add Contact => 1" << endl;
			cout << "Delete Contact By Name => 2" << endl;
			cout << "Search Contact By Name => 3" << endl;
			cout << "Search Contact By Phone Number => 4" << endl;
			cout << "Show All Users => 5" << endl;
			cout << "Exit => 6" << endl;
			cout << endl;

			int choice;
			cout << "Enter Choice: ";
			cin >> choice;

			if (choice == 1)
			{
				system("cls");
				string name;
				string surname;
				string phone_number;
				string adress;
				string email;

				cout << "Enter Name: ";
				cin >> name;

				cout << "Enter Surname: ";
				cin >> surname;

				cout << "Enter Phone Number: ";
				cin >> phone_number;

				cout << "Enter Adress: ";
				cin >> adress;

				cout << "Enter Email: ";
				cin >> email;

				Contact* new_contact = new Contact(name, surname, phone_number, adress, email);

				try
				{
					system("cls");
					data_base.Add_Contact(new_contact);
					cout << "Contact Added Succesfully";
					Sleep(2000);
				}
				catch (exception& ex)
				{
					cout << ex.what() << endl;
					Sleep(3000);
				}
			}
			else if (choice == 2)
			{
				system("cls");
				string name;
				cout << "Enter Name: ";
				cin >> name;

				try
				{
					system("cls");
					data_base.Delete_By_Name(name);
					cout << "Contact was Deleted SuccesFully";
					Sleep(2000);
				}
				catch (exception& ex)
				{
					cout << ex.what() << endl;
					Sleep(3000);
				}
			}
			else if (choice == 3)
			{
				system("cls");
				string name;
				cout << "Enter Name: ";
				cin >> name;

				try
				{
					system("cls");
					Contact* searched_contact = data_base.Search_By_Name(name);
					searched_contact->show();
					Sleep(3000);
				}
				catch (exception& ex)
				{
					cout << ex.what() << endl;
					Sleep(3000);
				}
			}
			else if (choice == 4)
			{
				system("cls");
				string phone;
				cout << "Enter Phone Number: ";
				cin >> phone;

				try
				{
					system("cls");
					Contact* searched_contact = data_base.Search_By_Phone_Number(phone);
					searched_contact->show();
					Sleep(3000);
				}
				catch (exception& ex)
				{
					cout << ex.what() << endl;
				}
			}
			else if (choice == 5)
			{
				system("cls");
				data_base.show();
				Sleep(5000);
			}
			else if (choice == 6)
			{
				cout << "Good-Bye !!";
				break;
			}
			else
			{
				try
				{
					throw InvalidArugmentException("Choice Not Correct !!", __DATE__, __TIME__, __FILE__, __LINE__);
				}
				catch (exception& ex)
				{
					cout << ex.what() << endl;
				}
			}
		}
	}
};