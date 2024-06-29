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
Crie uma classe Empresa_Solar para calcular a quantidade de painéis solares necessários para uma 
residência em função do consumo mensal em kWh do imóvel. Além do número de painéis deverá ser determinado 
também a área mínima que esses painéis ocupam e a economia anual gerada pela adoção do sistema com base 
no valor mensal gasto pelo imóvel, fornecido pelo usuário em reais.
*/

class Empresa_Solar{
  // Atributos da Classe Empresa_Solar.
    float potencia_imovel, gasto_mensal, economia_anual, area_placa_inst;
    float area_mod_placa, potencia_solar, quant_painel;
    void calc_area_inst(),calc_economia(),calc_quant_painel();	// Funçao para calculo das variaveis.

  public:
  // Funções para acessar as variaveis dos atributos.
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
	// Função para verificar se as variáveis não possuem valores negativos.
    potencia_imovel = (pi>0) ? pi : 0;
    gasto_mensal = (ge>0) ? ge : 0;
}

void Empresa_Solar :: setArea_Placa(float area){
	// Função para inserir o valor na variavel privada.
	area_mod_placa = area;
}

void Empresa_Solar :: setPotencia_Painel(float potI){
	// Função para inserir o valor na variavel privada.
	potencia_solar = potI;
}

float Empresa_Solar :: getPotencia_Imovel(){
	// Funação para retornar a Potência do Imovel, caso precise.
	return potencia_imovel;
}

float Empresa_Solar :: getGasto_Mensal(){
	// Funação para retornar a Potência do Imovel, caso precise.
	return gasto_mensal;
}

float Empresa_Solar :: getArea_Placa(){
	// Funação para retornar a Potência do Imovel, caso precise.
	return area_mod_placa;
}

float Empresa_Solar :: getPotencia_Painel(){
	// Funação para retornar a Potência do Imovel, caso precise.
	return potencia_solar;
}

float Empresa_Solar :: getQuant_Painel(){
    // Função para receber a quantidade de painéis.
    calc_quant_painel();
    return quant_painel;
}

void Empresa_Solar :: calc_quant_painel(){ // Função Private.
	// Função para calcular a quantidade de painéis, resultado da potência do imóvel pela potência do painel solar.
	quant_painel = potencia_imovel/potencia_solar;
	quant_painel = ceil(quant_painel);
}

float Empresa_Solar :: getArea_Placa_Inst(){
    // Função para receber a área mínima para instalação dos módulos solares.
	calc_area_inst();
    return area_placa_inst;
}

void Empresa_Solar :: calc_area_inst(){
	// Função para calcular a área mínima para instalação dos módulos solares é dada pelo produto entre o número de painéis necessários e a área do módulo solar.
    area_placa_inst = quant_painel * area_mod_placa;
}

float Empresa_Solar :: getEconomia_Anual(){
	//  Função para receber o cálculo da economia anual.
	calc_economia();
	return economia_anual;
}

void Empresa_Solar :: calc_economia(){
	//  Função para fazer o cálculo da economia anual que é dado por 90% do valor mensal em R$ de energia, multiplicado pela quantidade de meses em um ano.
	economia_anual = (gasto_mensal*0.9*12);
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    Empresa_Solar painel;
    float pot_imovel,gasto_energia,area_modulo_placa,pot_painel_solar;

    cout << "\n      Empresa Solar.";
    // Recebendo as informações do imóvel.
    area_modulo_placa = 2.5; //m² Informado pela questão.
    pot_painel_solar = 32; // kW/h Informado pela questão.
    cout << "\n\n Informe o consumo mensal do imóvel em kWh: ";
    cin >> pot_imovel;
    cout << "Informe o gasto mensal do imóvel com energia em R$: ";
    cin >> gasto_energia;
    // Atribuindo valores a cada atributo correspondente.
    painel.setPotencia_Gasto(pot_imovel,gasto_energia);
    painel.setArea_Placa(area_modulo_placa);
    painel.setPotencia_Painel(pot_painel_solar);

    // Exibindo os valores calculados para o imóvel.
    cout << "\n Quantidade de painéis necessários para este imóvel é: " << painel.getQuant_Painel();
    cout << fixed << setprecision(2);  // Função para exibir resultados em duas casas decimais.
    cout << "\n\n A área mínima para instalação das placas solares é: " << painel.getArea_Placa_Inst() << " m²";
    cout << "\n\n A economia anual após a instalação é: R$ " << painel.getEconomia_Anual();
  
    cout << "\n\n       Obrigado! Saindo do Programa...\n";
    return 0;
}