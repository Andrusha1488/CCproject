#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
	int accountNumber;
	double balance;
	double interestRate;
public:
	BankAccount(int accNum, double initialBalance) {
		this->accountNumber = accNum;
		if (initialBalance < 0)
		{
			throw invalid_argument("Начальный баланс не может быть меньше нуля.");
		}
		this->balance = initialBalance;
		this->interestRate = 0;
	}

	bool Deposit(double amount) {
		if (amount <= 0)
		{
			throw invalid_argument("Неккоректная сумма введения.");
		}
		balance += amount;
		cout << "Средства успешно внесены. Остаток на счете: " << balance << endl;
	}

	bool withdraw(double amount)
	{
		if (amount <= 0)
		{
			throw invalid_argument("Некорректная сумма снятия.");
		}
		if (amount > balance)
		{
			throw invalid_argument("Недостаточно средств для снятия.");
		}
		balance -= amount;
		cout << "Средства успешно сняты. Остаток на счете: " << balance << endl;
	}

	double getBalance()
	{
		return balance;

	}

	double getInterest()
	{
		return balance * interestRate * (1.0 / 12);
	}

	bool setinterestRate(double rate)
	{
		return interestRate = rate;
	}

	int getAccountNumber() {
		return this->accountNumber;
	}

	bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
		try{
			fromAccount.withdraw(amount);
			toAccount.Deposit(amount);
			return true;
		}
		catch (const invalid_argument& e) {
			cout << "Ошибка перевода." << endl;
			return false;
		}
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	BankAccount acc1(12345, 1000);	
	BankAccount acc2(67890, 500);

	int choice, accountChoice;
	double amount, rate;
	bool success;

	do {
		cout << "\nМеню выбора:\n";
		cout << "1. Внести средства\n";
		cout << "2. Снять средства\n";
		cout << "3. Перевести средства между счетами\n";
		cout << "4. Установить процентную ставку\n";
		cout << "5. Посмотреть счет\n";
		cout << "6. Посмотреть номер счета\n";
		cout << "7. Посмотреть процентную ставку\n";
		cout << "8. Выйти\n";
		cout << "Выберите действие: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Выберите счет (1 или 2): ";
			cin >> accountChoice;
			if (accountChoice == 1) {
				cout << "Введите сумму для внесения на счет 1: ";
				cin >> amount;
				try {
					success = acc1.Deposit(amount);
				}
				catch (const invalid_argument& e) {
					cerr << "Ошибка: " << e.what() << endl;
				}
			}
			else if (accountChoice == 2) {
				cout << "Введите сумму для внесения на счет 2: ";
				cin >> amount;
				try {
					success = acc2.Deposit(amount);
				}
				catch (const invalid_argument& e) {
					cerr << "Ошибка: " << e.what() << endl;
				}
			}
			else {
				cout << "Некорректный выбор счета.\n";
			}
			break;
		case 2:
			cout << "Выберите счет (1 или 2): ";
			cin >> accountChoice;
			if (accountChoice == 1) {
				cout << "Введите сумму для снятия со счета 1: ";
				cin >> amount;
				try {
					success = acc1.withdraw(amount);
				}
				catch (const invalid_argument& e) {
					cerr << "Ошибка: " << e.what() << endl;
				}
			}
			else if (accountChoice == 2) {
				cout << "Введите сумму для снятия со счета 2: ";
				cin >> amount;
				try {
					success = acc2.withdraw(amount);
				}
				catch (const invalid_argument& e) {
					cerr << "Ошибка: " << e.what() << endl;
				}
			}
			else {
				cout << "Некорректный выбор счета.\n";
			}
			break;
		case 3:
			cout << "Выберите счет, с которого нужно перевести (1 или 2): ";
			cin >> accountChoice;
			if (accountChoice == 1)
			{

				cout << "Введите сумму для перевода: ";
				cin >> amount;
				try {
					success = acc1.transfer(acc1, acc2, amount);
				}
				catch (const invalid_argument& e) {
					cerr << "Ошибка: " << e.what() << endl;
				}
			}
			else if (accountChoice == 2)
			{

				cout << "Введите сумму для перевода: ";
				cin >> amount;
				try {
					success = acc2.transfer(acc2, acc1, amount);
				}
				catch (const invalid_argument& e) {
					cerr << "Ошибка: " << e.what() << endl;
				}
			}
			break;
		case 4:
			cout << "Выберите счет (1 или 2): ";
			cin >> accountChoice;
			if (accountChoice == 1) {
				cout << "Введите новую процентную ставку для счета 1: ";
				cin >> rate;
				acc1.setinterestRate(rate);
			}
			else if (accountChoice == 2) {
				cout << "Введите новую процентную ставку для счета 2: ";
				cin >> rate;
				acc2.setinterestRate(rate);
			}
			else {
				cout << "Некорректный выбор счета.\n";
			}
			break;
		case 5:
			cout << "Выберите счет (1 или 2): ";
			cin >> accountChoice;
			if (accountChoice == 1) {
				cout << "Баланс счета 1: " << acc1.getBalance() << endl;
			}
			else if (accountChoice == 2) {
				cout << "Баланс счета 2: " << acc2.getBalance() << endl;
			}
			else {
				cout << "Некорректный выбор счета.\n";
			}
			break;
		case 6:
			cout << "Выберите счет (1 или 2): ";
			cin >> accountChoice;
			if (accountChoice == 1) {
				cout << "Номер счета 1: " << acc1.getAccountNumber() << endl;
			}
			else if (accountChoice == 2) {
				cout << "Номер счета 2: " << acc2.getAccountNumber() << endl;
			}
			else {
				cout << "Некорректный выбор счета.\n";
			}
			break;
		case 7:
			cout << "Выберите счет (1 или 2): ";
			cin >> accountChoice;
			if (accountChoice == 1) {
				cout << "Процентная ставка для счета 1: " << acc1.getInterest() << "%" << endl;
			}
			else if (accountChoice == 2) {
				cout << "Процентная ставка для счета 2: " << acc2.getInterest() << "%" << endl;
			}
			else {
				cout << "Некорректный выбор счета.\n";
			}
			break;
		case 8:
			cout << "Выход из программы.\n";
			break;
		default:
			cout << "Некорректный выбор. Попробуйте еще раз.\n";
			break;
		}
	} while (choice != 8);

	return 0;
}