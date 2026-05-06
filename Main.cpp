#include <iostream> 
#include <string>
#include <vector>
#include <cctype> 

enum class TokenType {
    number, 
    OPER, 
    IDENTIFIER, 
    KeyWORD, 
    End_File, 
};

struct Token {
    TokenType Code_type; 
    std::string Token_LenguajeName; 
    int Line; 
};

class bite_Center {
    public: 
    void TextConsole(std::string Text){

        Token t; 
        t.Token_LenguajeName = Text; 
        t.Code_type = TokenType::IDENTIFIER;
        t.Line = 0; 
        std::cout << t.Token_LenguajeName; 
    }

    void CodeProcesor(std::string linea){
        std::string comando = "TextConsole.Log_Shell"; 

        if (linea.find(comando) != std::string::npos){
            size_t inicio = linea.find("(" + 1); 
            size_t fin = linea.find(")", inicio); 
            if (inicio != std::string::npos && fin != std::string::npos) {
            std::string text_String = linea.substr(inicio, fin - inicio);
            TextConsole(text_String); 
            }else if (linea.find(comando) == std::string::npos){
                std::cout << "[001] Sintax error" <<std::endl; 
            }


        }
    }

};

int main(){
    std::cout << "aniaU Prototipe" << std::endl; 

    bite_Center Parsel; 
    std::string codeLine; 
    std::cout << " > "; 
    std::getline(std::cin, codeLine); 

    Parsel.CodeProcesor(codeLine); 

    return 0; 

}