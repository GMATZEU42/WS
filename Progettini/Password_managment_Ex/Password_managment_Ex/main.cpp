#include "console.h"
#include "admin.h"

#include <iostream>

using amaris::Console;

using amaris::ConsoleColor;

int main()
{	
	auto console = Console(ConsoleColor::BLUE);

	int i = 42;

	console.print(i);

	//console.print("Per favore inserire il nome utente \n");
	
	//std::string nome ;

	//std::string parola ;

	//console.print("Ora inserisci la password del suo account \n");

	//std::cin >> parola;
	
	//auto ad = admin::Admin();
	
	//ad = (nome, parola);

	//console.print(ad);

	return 0;
		
};

