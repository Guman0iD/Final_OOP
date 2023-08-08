#include"Includes.h"
//#include"SHA256.h"

class User
{
private:
    std::string m_login;
    std::string m_hashed_password;
    std::string m_full_name;
    std::string m_phone;

public:
    User() = default;

    User(const std::string& login, const std::string& pass, const std::string& full_name, const std::string& phone)
        : m_login(login),m_hashed_password(pass), m_full_name(full_name), m_phone(phone) {}

    bool operator==(const std::string& other_login) const
    {
        return m_login == other_login;
    }

    bool authenticate(const std::string& hashed_pass) const
    {
        return m_hashed_password == hashed_pass;
    }

    std::string get_login() const
    {
        return m_login;
    }

    std::string get_name() const
    {
        return m_full_name;
    }

    std::string get_hashed_pass() const
    {
        return m_hashed_password;
    }

};
