/*
  Discente: Marcos Eduardo
  Mat.: 121210541
  Curso: Engenharia Eletrica      Turma: 01
*/
# include <iostream>
# include <iomanip>
# include <locale>
# include <cmath>
using namespace std;

/*
Crie uma classe Empresa_Solar para calcular a quantidade de pain�is solares necess�rios para uma 
resid�ncia em fun��o do consumo mensal em kWh do im�vel. Al�m do n�mero de pain�is dever� ser determinado 
tamb�m a �rea m�nima que esses pain�is ocupam e a economia anual gerada pela ado��o do sistema com base 
no valor mensal gasto pelo im�vel, fornecido pelo usu�rio em reais.
*/

class Empresa_Solar{
  // Atributos da Classe Empresa_Solar.
    float potencia_imovel, gasto_mensal, economia_anual, area_placa_inst;
    float area_mod_placa, potencia_solar, quant_painel;
    void calc_area_inst(),calc_economia(),calc_quant_painel();	// Fun�ao para calculo das variaveis.

  public:
  // Fun��es para acessar as variaveis dos atributos.
    void setPotencia_Gasto(float,float);
    void setArea_Placa(float);
    void setPotencia_Painel(float);
    float getPotencia_Painel();
    float getArea_Placa_Inst();
    float getQuant_Painel();
    float getEconomia_Anual();
    float getPotencia_Imovel();
    float getGasto_Mensal();
    float getArea_Placa();
};

void Empresa_Solar :: setPotencia_Gasto(float pi, float ge){
	// Fun��o para verificar se as vari�veis n�o possuem valores negativos.
    potencia_imovel = (pi>0) ? pi : 0;
    gasto_mensal = (ge>0) ? ge : 0;
}

void Empresa_Solar :: setArea_Placa(float area){
	// Fun��o para inserir o valor na variavel privada.
	area_mod_placa = area;
}

void Empresa_Solar :: setPotencia_Painel(float potI){
	// Fun��o para inserir o valor na variavel privada.
	potencia_solar = potI;
}

float Empresa_Solar :: getPotencia_Imovel(){
	// Funa��o para retornar a Pot�ncia do Imovel, caso precise.
	return potencia_imovel;
}

float Empresa_Solar :: getGasto_Mensal(){
	// Funa��o para retornar a Pot�ncia do Imovel, caso precise.
	return gasto_mensal;
}

float Empresa_Solar :: getArea_Placa(){
	// Funa��o para retornar a Pot�ncia do Imovel, caso precise.
	return area_mod_placa;
}

float Empresa_Solar :: getPotencia_Painel(){
	// Funa��o para retornar a Pot�ncia do Imovel, caso precise.
	return potencia_solar;
}

float Empresa_Solar :: getQuant_Painel(){
    // Fun��o para receber a quantidade de pain�is.
    calc_quant_painel();
    return quant_painel;
}

void Empresa_Solar :: calc_quant_painel(){ // Fun��o Private.
	// Fun��o para calcular a quantidade de pain�is, resultado da pot�ncia do im�vel pela pot�ncia do painel solar.
	quant_painel = potencia_imovel/potencia_solar;
	quant_painel = ceil(quant_painel);
}

float Empresa_Solar :: getArea_Placa_Inst(){
    // Fun��o para receber a �rea m�nima para instala��o dos m�dulos solares.
	calc_area_inst();
    return area_placa_inst;
}

void Empresa_Solar :: calc_area_inst(){
	// Fun��o para calcular a �rea m�nima para instala��o dos m�dulos solares � dada pelo produto entre o n�mero de pain�is necess�rios e a �rea do m�dulo solar.
    area_placa_inst = quant_painel * area_mod_placa;
}

float Empresa_Solar :: getEconomia_Anual(){
	//  Fun��o para receber o c�lculo da economia anual.
	calc_economia();
	return economia_anual;
}

void Empresa_Solar :: calc_economia(){
	//  Fun��o para fazer o c�lculo da economia anual que � dado por 90% do valor mensal em R$ de energia, multiplicado pela quantidade de meses em um ano.
	economia_anual = (gasto_mensal*0.9*12);
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    Empresa_Solar painel;
    float pot_imovel,gasto_energia,area_modulo_placa,pot_painel_solar;

    cout << "\n      Empresa Solar.";
    // Recebendo as informa��es do im�vel.
    area_modulo_placa = 2.5; //m� Informado pela quest�o.
    pot_painel_solar = 32; // kW/h Informado pela quest�o.
    cout << "\n\n Informe o consumo mensal do im�vel em kWh: ";
    cin >> pot_imovel;
    cout << "Informe o gasto mensal do im�vel com energia em R$: ";
    cin >> gasto_energia;
    // Atribuindo valores a cada atributo correspondente.
    painel.setPotencia_Gasto(pot_imovel,gasto_energia);
    painel.setArea_Placa(area_modulo_placa);
    painel.setPotencia_Painel(pot_painel_solar);

    // Exibindo os valores calculados para o im�vel.
    cout << "\n Quantidade de pain�is necess�rios para este im�vel �: " << painel.getQuant_Painel();
    cout << fixed << setprecision(2);  // Fun��o para exibir resultados em duas casas decimais.
    cout << "\n\n A �rea m�nima para instala��o das placas solares �: " << painel.getArea_Placa_Inst() << " m�";
    cout << "\n\n A economia anual ap�s a instala��o �: R$ " << painel.getEconomia_Anual();
  
    cout << "\n\n       Obrigado! Saindo do Programa...\n";
    return 0;
}