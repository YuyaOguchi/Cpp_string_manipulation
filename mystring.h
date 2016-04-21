// FILE: mystrings.h
// CLASS PROVIDED: strings

#include <cstdlib>  // Provides size_t
#include <string>
class strings{
private:
    char *sequence;
    size_t allocated;
    size_t current_length;
public:
    // CONSTRUCTORS and DESTRUCTOR
    strings(const char &source);//part a
    //~strings( );
    // MODIFICATION MEMBER FUNCTIONS
    void insertion(const std::string& input, const int pos);//part b
    void deletion(const int from,const int to);//part c
    void swapchar(const char &input, const int pos);//part d
    void swapstring(const std::string& input, const int pos);//part e
    int searchchar(const char &input);//part f
    int occurence(const char &input);//part g
    int searchstr(const std::string& input); //part h

    void dump();
    // CONSTANT MEMBER FUNCTIONS
    size_t length( ) const { return current_length; }
    char operator [ ](size_t position) const;
};

// NON-MEMBER FUNCTIONS for the strings class
//strings operator +(const strings& s1, const strings& s2);
//istream& operator >>(istream& ins, strings& target);
// void getline(istream& ins, strings& target, char delimiter);
