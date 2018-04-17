#include "kernel.h"
#include "loggermanager.h"


// temp main to test stuff out (this will turn into a library in the future).
int main()
{
	WWindow* window = new WWindow("Test");
	window->Initialize(0, 0, false);
	while (1 == 1)
	{
	}
	return 0;
}