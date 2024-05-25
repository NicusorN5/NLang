#include "pch.hpp"

using ArgsList = const Vector<String>&;

static i32 Main(ArgsList args);

int main(int numArgs, char **args)
{
	//put args** inside a std::vector for easier manipulation
	std::vector<std::string> cmdArgs; 
	for (auto&& n : iota(1, numArgs))
	{
		cmdArgs.push_back(std::string(args[n]));
	}

	return Main(cmdArgs);
}

static void ShowHelp()
{
	std::println("NLang : NLang compiler.");
	std::println("Usage: NLang [files...] [-o OUTPUT] [-target:TARGET]");
}

static i32 Main(ArgsList args)
{
	Dictionary<String, int> options =
	{
		{"--help", 1},
		{"-h", 1},
		{"/?", 1},
	};

	for (auto&& argument : args)
	{
		switch (options[argument])
		{
		case 1:
			ShowHelp();
			return 0;
		default:
			return 0;
		}
	}
}

