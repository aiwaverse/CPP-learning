#include "Mystringglobal.hpp"
#include <iostream>
#include <cstring>

Mystring::Mystring() : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}
Mystring::Mystring(const char *s)
{
    if(s==nullptr)
    {
        str=new char [1];
        *str = '\0';
    }
    else
    {
        str = new char [strlen(s)+1];
        strcpy(str,s);
    }
    
}
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
}
Mystring::Mystring(const Mystring& source) : str{nullptr}
{
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}
Mystring::~Mystring()
{
    delete [] str;
}
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}
int Mystring::get_length() const
{
    return std::strlen(str);
}
const char *Mystring::get_str() const
{
    return str;
}
//assigment operator overload
Mystring &Mystring::operator=(const Mystring& rhs)
{   
    if(this!=&rhs)  //if this==&rhs that means the two sides are equal, so just return this value (*this)
    {
        delete [] str;      //if not, since we're overwriting the left side, we delete it
        str = new char [std::strlen(rhs.str)+1];    // then we allocate memory, the size needs to be the size of the rhs + 1 for the null character
        std::strcpy(str,rhs.str); //then we finally do the copy

    }
    return *this;   //either way we return the value of this, which is the string on the left side, that we just changed (or not)
}
Mystring &Mystring::operator=(Mystring&& rhs) //overloaded move assigment 
{
    if(this!=&rhs)
    {
        delete [] str;      //delete the contents of the left object
        str = rhs.str;      //steal the contents of rhs
        rhs.str = nullptr;      //nullify rhs.str
    }
    return *this;
}
Mystring operator-(const Mystring& obj)
{
    char *buff = new char [strlen(obj.str)+1];
    strcpy(buff,obj.str);
    for(unsigned i{0};i<strlen(obj.str);i++)
    {
        buff[i]=tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
    char *buff = new char[strlen(lhs.str)+strlen(rhs.str)+1];
    strcpy(buff,lhs.str);
    strcat(buff,rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
Mystring operator*(const Mystring& lhs, const unsigned int rhs)
{
    size_t better_larger_size= strlen(lhs.str)*rhs + 1;
    char *better_larger = new char[better_larger_size] {};
    for(unsigned i{1};i<=rhs;i++)
    {
        strcat(better_larger,lhs.str);
    }
    Mystring new_string {better_larger};
    delete better_larger;
    return new_string;
}
void operator*=(Mystring& lhs, const unsigned int rhs)
{
    lhs = lhs*rhs; //like, duh, that's the operator definition
}
void operator+=(Mystring& lhs, const Mystring& rhs)
{
    lhs = lhs+rhs;
}

bool operator==(const Mystring& lhs, const Mystring& rhs)
{
    return (strcmp(lhs.str,rhs.str)==0);
}
bool operator!=(const Mystring& lhs, const Mystring& rhs)
{
    return (strcmp(lhs.str,rhs.str)!=0);
}

std::ostream &operator<<(std::ostream &os, const Mystring& rhs)
{
    os << rhs.str;
    return os;
}
bool operator<(const Mystring& lhs, const Mystring& rhs)
{
    if(strcmp(lhs.str,rhs.str)<0)
        return true;
    else return false;
}
bool operator>(const Mystring& lhs, const Mystring& rhs)
{
    return !(lhs < rhs);
}

std::istream &operator>>(std::istream &in, Mystring& rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring {buff};
    delete [] buff;
    return in;
}
Mystring &operator++(Mystring &obj)
{
    for(unsigned i{0};i<strlen(obj.str);i++)
    {
        obj.str[i]=toupper(obj.str[i]);
    }
    return obj;
}
Mystring operator++(Mystring &obj, int)  //postfix
{
    Mystring temp {obj};
    ++obj;
    return obj;
}
Mystring &operator--(Mystring &obj)
{
    obj=-obj;
    return obj;
}
Mystring operator--(Mystring &obj, int)
{
    Mystring temp {obj};
    --obj;
    return obj;
}