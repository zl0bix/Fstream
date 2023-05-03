#include<iostream>
#include<fstream>
#include<string>

// Вывод содержимого файла по переданному пути в консоль
bool print_file(std::string file_path) {
	static std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
		return true;
	}
	return false;
}

bool insert_file(std::string file_path, int pasition, std::string str);

int main() {
	setlocale(LC_ALL, "rus");
	int n;

	std::string path = "file.txt";
	// Класс fstream
	/*std::fstream file;
	file.open(path, std::ios::in | std::ios::app); // В режимах открытия по умолчанию будет ошибка если файла не существует

	if (file.is_open()) {
		std::cout << "Файл открыт\n";

		// Запись в файл
		std::string str;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		file << str << '\n';
		std::cout << "Запись добавлена в файл\n";
		file.seekg(0, std::ios::beg); // Перемещение курсора в начало файла для дальнейшего считывания


		// Чтение из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
		std::cout << std::endl;

	}
	else
		std::cout << "Ошибка открытия файла\n";
	
	file.close();
	*/

	//Ex1 "Добавление в середину файла"
	/*
	std::cout << "Исходный файл:\n";
	print_file(path);
	std::cout << "Введите позицию -> ";
	std::cin >> n;
	std::cin.ignore();
	std::cout << "Введите строку-> ";
	std::string str;
	std::getline(std::cin, str);

	if (insert_file(path, n, str)) {
		std::cout << "Вставка выполнена успешно\n\n";
		std::cout << "Содержимое файла:\n";
		print_file(path);
		std::cout << std::endl;
	}
	else
		std::cout << "Error!!!\n";
*/

	// Ex2 Чтение даты из файла
	std::cout << "Ex2\nDate: ";
	print_file("date.txt");
	std::string date;
	std::ifstream read;
	read.open("date.txt");
	if (read.is_open()) {
		read >> date;
		read.close();
	}
	int day = std::stoi(date);
	int month = std::stoi(date.substr(date.find('.')+1));
	int year = std::stoi(date.substr(date.rfind('.')+1));
	std::cout << "Day " << day << std::endl;
	std::cout << "Month " << month << std::endl;
	std::cout << "Year " << year << std::endl;


	system("pause");
	return 0;
}

bool insert_file(std::string file_path, int position, std::string str) {
	std::fstream file;
	std::string file_text;

	//Шаг 1. Копирование содержимого файла в строку
	file.open(file_path, std::ios::in);
	if (file.is_open()) {
		char sym;
		while (file.get(sym))
			file_text += sym;
		file.close();
	}
	else
		return false;

	//Шаг 2. Изменение строки
	file_text.insert(position, str);

	//Шаг 3. Щбновление содержимого файла
	file.open(file_path, std::ios::out);
	if (file.is_open()) {
		file << file_text;
		file.close();
		return true;
	}
	return false;
}