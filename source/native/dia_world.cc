// This is the main function for the NATIVE version of this project.

#include <iostream>

#include "emp/base/vector.hpp"
#include "emp/config/command_line.hpp"
#include "emp/config/ArgManager.hpp"

#include "../config.h"
#include "../world.h"
#include "../org.h"

// Hello world

int main(int argc, char* argv[])
{
  DiaConfig config;
  config.Read("Dia.cfg", false);
  auto args = emp::cl::ArgManager(argc, argv);
  if (args.ProcessConfigOptions(config, std::cout, "Dia.cfg", "Dia-macros.h") == false) exit(0);
  if (args.TestUnknown() == false) exit(0);  // If there are leftover args, throw an error.

  std::cout << "==============================" << std::endl;
  std::cout << "|    How am I configured?    |" << std::endl;
  std::cout << "==============================" << std::endl;
  config.Write(std::cout);
  std::cout << "==============================\n"
            << std::endl;


  DiagWorld world(config);

  while (world.GetUpdate() <= config.MAX_GENS())
  {
    world.Update();
  }
}