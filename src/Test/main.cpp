#include <GDE/Core.hpp>
#include <iostream> // Quitar

int main(int argc, char** argv)
{
	int anExitCode;

	GDE::App* anApp = GDE::App::instance();

	anExitCode = anApp->run();

	return anExitCode;
}