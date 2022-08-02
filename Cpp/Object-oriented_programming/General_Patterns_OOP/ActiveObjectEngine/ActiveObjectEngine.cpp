#include "ActiveObjectEngine.h"

#ifdef __PRINT_DEBUG_MASSENG__
#include <iostream>
#endif // __PRINT_DEBUG_MASSENG__

void ActiveObjectEngine::addCommand(Command* c)
{
#ifdef __PRINT_DEBUG_MASSENG__
	std::cout << "ActiveObjectEngine::addCommand(Command* c) itsSize = " << itsCommands.size() << " + 1\n";
#endif // __PRINT_DEBUG_MASSENG__

	itsCommands.push_back(c);
}

void ActiveObjectEngine::run()
{
	while (!itsCommands.empty())
	{
		Command* c = itsCommands.front();

#ifdef __PRINT_DEBUG_MASSENG__
		std::cout << "ActiveObjectEngine::run() itsSize = " << itsCommands.size() << "\n"
			<< "*c is: " << typeid(*c).name() << '\n';
#endif // __PRINT_DEBUG_MASSENG__
		
		if (c)
		{
			c->execute();
		}
		itsCommands.pop_front();
	}
}

void Command::execute() throw(std::exception)
{
#ifdef __PRINT_DEBUG_MASSENG__
	std::cout << "Command\n";
#endif // __PRINT_DEBUG_MASSENG__
}
