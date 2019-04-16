#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller{
public:
  Controller(view_control s=view_control::Bin) : stat=s {};
  void createView(view_control c);//c è la view che si vuole richiedere
  void handleInput(view_control c, /*input da utente/gui*/);// c dice che view sto utilizzando per l'input
  void handleOutput(view_control c, output o);//c dice che view utilizzare per l'output
private:
  enum class view_control{Bin, Hex, Oct, Col, Err};
  view_control stat;
  QString input;
};
#endif // CONTROLLER_H

/*
model()->tutto nullo::
model(const QString a, const QString b)->a::Obbligatoria, 1^operando; b::2^operando
  model(const int a, const int b);

setoperation(char x)->x::setta l'operazione da fare;
execute()->esegue l'operazione;


*/
