#include <string>
#include <locale>
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>

typedef std::map<std::string, std::function<std::string(std::string)> > mod_map;
typedef mod_map::iterator it_mod_map;

typedef std::map<std::string, std::string> rep_map;
typedef rep_map::iterator it_rep_map;

std::locale loc;

std::string multi_replace(std::string str, rep_map e_rep_map) {
    for ( it_rep_map it = e_rep_map.begin(); it != e_rep_map.end(); it++) {
        for( size_t pos = 0; ; pos += it->second.length() )  {
            pos = str.find( it->first, pos );
            if( pos == std::string::npos ) break;
                str.erase( pos, it->first.length() );
                str.insert( pos, it->second);
        }
    }
    return str;
}

mod_map mods = {
    {"", [](std::string str){return str;} },
    {"aA", [](std::string str){
                rep_map replace_list = {
                    {"o", "0"},
                    {"'", ""} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list);
            } },
    {"aT", [](std::string str){
                rep_map replace_list = {
                    {".", ","},
                    {"!", ","},
                    {"?", ","} };
                return str;
            } },
    {"tA", [](std::string str){
                rep_map replace_list = {
                    {"s", "2"},
                    {"i", "ii"} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list);
            } },
    {"cG", [](std::string str){
                for (auto & c: str) c = toupper(c);
                return str;
            } },
    {"aC", [](std::string str){
                for (auto & c: str) c = tolower(c);
                rep_map replace_list = {
                    {":3", ":33"} };
                return multi_replace(str, replace_list).insert(0, ":33 < ");
            } },
    {"gA", [](std::string str){return str;} },
    {"gC", [](std::string str){
                rep_map replace_list = {
                    {"A", "4"},
                    {"E", "3"},
                    {"I", "1"},
                    {"8", "B"} };
                for (auto & c: str) c = toupper(c);
                return multi_replace(str, replace_list);
            } },
    {"aG", [](std::string str){
                rep_map replace_list = {
                    {"ate", "8"} };
                return multi_replace(str, replace_list);
            } },
    {"cT", [](std::string str){
                rep_map replace_list = {
                    {"x", "%"} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list).insert(0, "D --> ");
            } },
    {"tC", [](std::string str){
                for (auto & c: str) c = toupper(c);
                for(unsigned int i; i < str.length(); i++)
                    if (i%2)
                        str[i] = tolower(str[i]);
                return str;
            } },
    {"cA", [](std::string str){
                rep_map replace_list = {
                    {",", ""},
                    {"!", ""},
                    {",", ""},
                    {"?", ""},
                    {"\"", ""},
                    {"'", ""} };
                for (auto & c: str) c = tolower(c);
                return multi_replace(str, replace_list);
            } },
    {"cC", [](std::string str){
                rep_map replace_list = {
                    {"H", ")("},
                    {"h", ")("} };
                return multi_replace(str, replace_list);
            } }
};

rep_map cols = {
    {"nop", "\033[00m"},
    {"bg", "\033[107m"},
    {"aA", "\033[38;5;124m"},
    {"aT", "\033[38;5;130m"},
    {"tA", "\033[38;5;142m"},
    {"cG", "\033[38;5;241m"},
    {"aC", "\033[38;5;58m"},
    {"gA", "\033[38;5;29m"},
    {"gC", "\033[38;5;30m"},
    {"aG", "\033[38;5;24m"},
    {"cT", "\033[38;5;17m"},
    {"tC", "\033[38;5;53m"},
    {"cA", "\033[38;5;91m"},
    {"cC", "\033[38;5;89m"}
};

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
            }
        } else {
            if (name.compare("")==0) { 
                name = argv[i]; 
                continue; 
            }
            str += argv[i];
            str += " ";
        }
    }

    for( it_mod_map it = mods.begin(); it != mods.end(); it++ ) {
        if (!name.compare(it->first)) {
            if (color) std::cout << cols[name];
            if (bg) std::cout << cols["bg"];
            std::cout << it->second(str) << cols["nop"] << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
