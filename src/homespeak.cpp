#include <string>
#include <locale>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cctype>
#include <locale>
#include <map>

typedef std::map<std::string, std::function<std::string(std::string)> > mod_map;
typedef mod_map::iterator it_mod_map;

typedef std::map<std::string, std::string> mod_aliases;
typedef std::map<std::string, std::string> rep_map;
typedef rep_map::iterator it_rep_map;

std::string multi_replace(std::string str, rep_map e_rep_map) {
    for ( it_rep_map it = e_rep_map.begin(); it != e_rep_map.end(); it++) {
        for( size_t pos = 0; ; pos += it->second.length() )  {
            pos = str.find( it->first, pos );
            if( pos == std::string::npos ) break;
            str.erase(pos, it->first.length() );
            str.insert(pos, it->second);
        }
    }
    return str;
}

rep_map cols = {
    {"nop", "\033[00m"},
    {"bg", "\033[107m"},
    {"AA", "\033[38;5;124m"},
    {"AT", "\033[38;5;130m"},
    {"TA", "\033[38;5;142m"},
    {"CG", "\033[38;5;241m"},
    {"AC", "\033[38;5;58m"},
    {"GA", "\033[38;5;29m"},
    {"GC", "\033[38;5;30m"},
    {"AG", "\033[38;5;24m"},
    {"CT", "\033[38;5;17m"},
    {"TC", "\033[38;5;53m"},
    {"CA", "\033[38;5;91m"},
    {"CC", "\033[38;5;89m"}
};

mod_aliases mod_a = {
    { "", "" }
};

mod_map mods = {
    {"AA", [](std::string str){
                rep_map replace_list = {
                    {",", ""},
                    {"!", ""},
                    {"?", ""},
                    {".", ""},
                    {"o", "0"},
                    {"'", ""} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list);
            } },
    {"AT", [](std::string str){
                rep_map replace_list = {
                    {".", ","},
                    {"!", ","},
                    {"?", ","} };
                str = multi_replace(str, replace_list);
                for (auto & c: str) c = toupper(c);
                str[0] = tolower(str[0]);
                bool l = false;
                for (unsigned int j = 0; j < str.length(); j++) {
                    if (str[j] == ',') l = true;
                    if (str[j] == ' ' && l) {
                        str[j+1] = tolower(str[j+1]);
                        l = false;
                    }
                }
                return str;
            } },
    {"TA", [](std::string str){
                rep_map replace_list = {
                    {"s", "2"},
                    {"i", "ii"} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list);
            } },
    {"CG", [](std::string str){
                for (auto & c: str) c = toupper(c);
                return str;
            } },
    {"AC", [](std::string str){
                for (auto & c: str) c = tolower(c);
                rep_map replace_list = {
                    {"!", "!!"},
                    {":3", ":33"} };
                return multi_replace(str, replace_list).insert(0, ":33 < ");
            } },
    {"GA", [](std::string str){
                rep_map replace_list = {
                    {",", ""},
                    {"!", ""},
                    {"?", ""},
                    {".", ""} };
                str[0] = toupper(str[0]);
                for (unsigned int j = 0; j < str.length(); j++)
                    if (str[j] == ' ')
                        str[j+1] = toupper(str[j+1]);
                return multi_replace(str, replace_list);
            } },
    {"GC", [](std::string str){
                rep_map replace_list = {
                    {"A", "4"},
                    {"E", "3"},
                    {"I", "1"},
                    {"8", "B"} };
                for (auto & c: str) c = toupper(c);
                return multi_replace(str, replace_list);
            } },
    {"AG", [](std::string str){
                rep_map replace_list = {
                    {"b", "8"},
                    {"B", "8"},
                    {"ate", "8"} };
                return multi_replace(str, replace_list);
            } },
    {"CT", [](std::string str){
                rep_map replace_list = {
                    {"x", "%"} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list).insert(0, "D --> ");
            } },
    {"TC", [](std::string str){
                for (auto & c: str) c = toupper(c);
                for(unsigned int i; i < str.length(); i++)
                    if (i%2)
                        str[i] = tolower(str[i]);
                return str;
            } },
    {"CA", [](std::string str){
                rep_map replace_list = {
                    {"w", "ww"},
                    {",", ""},
                    {"!", ""},
                    {",", ""},
                    {"?", ""},
                    {"\"", ""},
                    {"'", ""} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list);
            } },
    {"CC", [](std::string str){
                rep_map replace_list = {
                    {"H", ")("},
                    {"h", ")("} };
                return multi_replace(str, replace_list);
            } }
};

void usage() {
    std::cout <<"\
usage: homespeak [--color] [--bg] [--help] <identifier>" << std::endl << std::endl <<
"    --help      Display this usage message" << std::endl <<
"    --color     Colors the text" << std::endl <<
"    --bg        Adds a white background" << std::endl << std::endl <<
"The identifier allows you to select which quirk you want to apply on the text." << std::endl << 
std::endl <<
"The possible identifiers are the following:" << std::endl << std::endl <<
"    AA  Aradia Megido" << std::endl <<
"    AT  Tavros Nitram" << std::endl <<
"    TA  Sollux Captor" << std::endl <<
"    CG  Karkat Vantas" << std::endl <<
"    AC  Nepeta Leijon" << std::endl <<
"    GA  Kanaya Maryam" << std::endl <<
"    GC  Terezi Pyrope" << std::endl <<
"    AG  Vriska Serket" << std::endl <<
"    CT  Equius Zahhak" << std::endl <<
"    TC  Gamzee Makara" << std::endl <<
"    CA  Eridan Ampora" << std::endl <<
"    CC  Feferi Peixes" << std::endl << 
std::endl;
}

int main(int argc, const char *argv[])
{
    std::string name = "",
                str = "";
    bool    color = false,
            bg = false;
    
    for( int i = 1; i < argc; i++ ) {
        std::string s = std::string(argv[i]);
        if (s.substr(0,2).compare("--")==0) {
            s = s.substr(2, s.length());
            if (s.compare("color")==0) {
                color = true;
            } else if (s.compare("bg")==0) {
                bg = true;
            } else if (s.compare("help")==0) {
                usage();
                exit(EXIT_SUCCESS);
            }
        } else {
            if (name.compare("")==0) { 
                name = argv[i]; 
                for (auto & c : name) c = toupper(c);
                continue; 
            }
            str += argv[i];
            str += " ";
        }
    }

    if (str.size() ==0)
        exit(EXIT_SUCCESS);

    for( it_mod_map it = mods.begin(); it != mods.end(); it++ ) {
        if (!name.compare(it->first)) {
            if (color) std::cout << cols[name];
            if (bg) std::cout << cols["bg"];
            std::cout << it->second(str);
            if (color || bg) std::cout << cols["nop"];
            std::cout << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
