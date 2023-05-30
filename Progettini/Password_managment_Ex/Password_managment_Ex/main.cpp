#include "console.h"
#include "admin.h"

#include <iostream>

using amaris::Console;

using amaris::ConsoleColor;

int main()
{	
	auto console = Console(ConsoleColor::BLUE);

	console.print("Per favore inserire il nome utente \n");
	
	std::string nome ;

	std::string parola ;

	std::cin >> nome;

	console.print("Ora inserisci la password del suo account \n");

	std::cin >> parola;

	admin::Admin::ImmettiCredenziali(nome, parola);

	return 0;
		
};

