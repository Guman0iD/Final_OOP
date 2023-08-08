#include"Includes.h"
//#include"User.h"
#include<conio.h>

class Regestration
{
private:
    static std::string hash_password(const std::string& password)
    {
        SHA256 sha256;
        sha256.update(password);
        std::unique_ptr<uint8_t[]>hash(sha256.digest());
        std::string hashed_password = SHA256::toString(hash.get());
        return hashed_password;
    }

    static bool check_to_return_main(const std::string& input)
    {
        return input == "0";
    }   

    static bool is_digit(const std::string& str)
    {
        for (char c : str)
        {
            if (!std::isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

    static void registration_user(Reader<std::string>& reader, Writer<std::string>& writer, std::vector<User>& users)
    {
        std::string login;
        std::string password1;
        std::string password2;
        std::string full_name;
        std::string phone;
        writer.write("To complete the registration, enter 0!\n");

        bool is_unique_login = false;

        do {
            writer.write("Enter your login: ");
            login = reader.read();

            if (check_to_return_main(login)) //////////////сделать минимальный пароль/ сдлеать проверку на 0 чтобы заканчивалась регистрация.
            {
                writer.write("Returning to the main menu.\n");
                return;
            }

            is_unique_login = true;
            for (const User& user : users)
            {
                if (user == login)
                {
                    writer.write("A user with this login already exists. Please enter a different login.\n");
                    is_unique_login = false;
                    break;
                }
            }
        } while (!is_unique_login);


        do {
            writer.write("Enter your password: ");
            password1 = reader.read();
            writer.write("Repeat the password: ");
            password2 = reader.read();

            if (password1 != password2)
            {
                writer.write("The passwords don't match. Try again..\n");
            }
        } while (password1 != password2);

        writer.write("Enter first name, last name, and middle name: ");
        std::string first_name = reader.read();
        std::string last_name = reader.read();
        std::string middle_name = reader.read();
        full_name = first_name + " " + last_name + " " + middle_name;

        bool is_coreect_phone = false;
        do
        {
            writer.write("Enter phone number: ");
            phone = reader.read();
            size_t phone_size = phone.size();

            if (!is_digit(phone) || phone_size != 10)
            {
                writer.write("Incorrect phone number. Try again \n");
            }
            else
            {
                is_coreect_phone = true;
            }
        } while (!is_coreect_phone);

        std::string hashed_password = hash_password(password1);

        User new_user = User(login, hashed_password, full_name, phone);
        users.push_back(new_user);

        writer.write("New user registration successfully completed! \n");
        Sleep(2000);
        system("cls");
    }
public:
    static void load_from_base(Reader<std::string>& reader, Writer<std::string>& writer, std::vector<User>& users, const std::string& filename)
    {
        std::ifstream file(filename);

        if (file.is_open())
        {
            std::string full_name, login, hashed_password, phone;

            while (file >> full_name >> login >> phone >> hashed_password)
            {
                User user(login, hashed_password, full_name, phone);
                users.push_back(user);
            }
            file.close();
        }
       /* else
        {
            writer.write("Data base is not found\n");
        }*/
    }


    static void save_to_base(Reader<std::string>& reader, Writer<std::string>& writer, const std::vector<User>& users, const std::string& filename)
    {
        std::ofstream file(filename);

        if (file.is_open())
        {
            for (const User& user : users)
            {
                file << user.get_login() << " " << user.get_name() << " " << user.get_hashed_pass() << '\n';
            }
            file.close();
        }
        else
        {
            writer.write("Unable to open the file for saving.");
        }
    }

    /*static void run(Reader<std::string>& reader, Writer<std::string>& writer, std::vector<User>& users, const std::string& filename)
    {
        load_from_base(reader, writer, users, filename);

        int choice;
        do
        {
            writer.write("\t\t\tRegistration menu.\n");
            writer.write("1.Registration.\n");
            writer.write("0.Back to main menu.\n");
            std::string choice_str = reader.read();

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
                registration_user(reader, writer, users);
                save_to_base(reader, writer, users, filename);
                break;
            case 0:
                writer.write("Return to the main menu.");
                break;
            default:
                writer.write("Incorrect choice.");
                break;
            }

        } while (choice != 0);
    }*/

    static void run(Reader<std::string>& reader, Writer<std::string>& writer, std::vector<User>& users, const std::string& filename)
    {
        load_from_base(reader, writer, users, filename);
      
        writer.write("\t\t\tRegistration menu.\n");      
        
        registration_user(reader, writer, users);
        save_to_base(reader, writer, users, filename);        
       
    }

};
