

#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;

class Carta
 {
    public:
        Carta
        ();
        Carta
        (string valor, int tipo, string color, bool esconder);
        void setValor(string valor);
        void setTipo(int tipo);
        void setColor(string color);
        void setEsconder(bool esconder);
        string getValor();
        int getTipo();
        string getColor();
        bool esOculto();
        ~Carta
        ();
    
    private:
        string valor;
        int tipo;
        string color;
        bool esconder;
};
#endif /* CARD_HPP */

