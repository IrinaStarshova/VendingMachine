#include "machine.h"
#include <chrono>


int main()
{
	srand(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));

	Machine vendingMachine;
	vendingMachine.Run();
	
	return 0;
}