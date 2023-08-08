#pragma once
#include "Includes.h"
#include "Regestration.h"
#include"Authenticate.h"

class Menu
{
public:
    static void display(Reader<std::string>& reader, Writer<std::string>& writer, std::vector<User>& users, const std::string& filename)
    {
        while (true)
        {
            writer.write("\t\t\tMain Menu\n");
            writer.write("1. Register\n");
            writer.write("2. Authenticate\n");
            writer.write("0. Exit\n");
            std::string choice_str = reader.read();

            int choice;
            try
            {
                choice = std::stoi(choice_str);
            }
            catch (const std::exception&)
            {
                choice = -1;
            }

            switch (choice)
            {
            case 1:
                Regestration::run(reader, writer, users, filename);
                break;
            case 2:
                Authentication::run(reader, writer, users);
                break;
            case 0:
                writer.write("Exiting the program.\n");
                return;
            default:
                writer.write("Invalid choice.\n");
                break;
            }
        }
    }
};
