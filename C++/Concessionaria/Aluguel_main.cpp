# include <iostream>
# include <locale>
# include <iomanip>
# include <cstdlib>

# include "Aluga_veiculo.cpp"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	float diaria;
	std :: string marca;
	std :: string modelo;
	int ano_carro;
	int dia, mes, ano;
	int hora, minuto;
	Aluguel_veiculo loja;
	
	std :: cout << "------------------------------------------------------------------------------------------------" << std :: endl ;
	std :: cout << "------------------------------------------------------------------------------------------------" << std :: endl ;
	std :: cout << std :: endl << "					TP - CONCESSIONARIA											" << std :: endl ;
	std :: cout << "------------------------------------------------------------------------------------------------" << std :: endl ;
	std :: cout << "------------------------------------------------------------------------------------------------" << std :: endl ;
	std :: cout << std :: endl;
	
	std :: cout << "\t Informe os dados do veículo. ";
	std :: cout << std :: endl;
	std :: cout << std :: endl;
	std :: cout << "\t Informe a marca do veículo: ";
	std :: cin >> marca;
	std :: cout << "\t Informe o modelo do veículo: ";
	std :: cin >> modelo;
	std :: cout << "\t Informe o ano do veículo: ";
	std :: cin >> ano_carro;
	std :: cout << "\t Informe o valor da diaria do aluguel: ";
	std :: cin >> diaria;
	
	std :: cout << std :: endl;
	std :: cout << std :: endl;
	
	std :: cout << "\t Informe os dados do aluguel. ";
	std :: cout << std :: endl;
	std :: cout << std :: endl;
	std :: cout << "\t Informe a data da retirada: ";
	std :: cin >> dia >> mes >> ano;
	std :: cout << "\t Informe a hora da retirada: ";
	std :: cin >> hora >> minuto;
	loja.setHora_Retirada(hora,minuto);
	loja.setData_Retirada(dia,mes,ano);
	std :: cout << "\t Informe a data da devolução: ";
	std :: cin >> dia >> mes >> ano;
	std :: cout << "\t Informe a hora da devolução: ";
	std :: cin >> hora >> minuto;
	loja.setHora_Devolucao(hora,minuto);
	loja.setData_Devolucao(dia,mes,ano);
	loja.setMarca(marca);
	loja.setModelo(modelo);
	loja.setAno_Carro(ano_carro);
	loja.setDiaria(diaria);
	
	std :: cout << std :: endl;
	std :: cout << "------------------------------------------------------------------------------------------------" << std :: endl ;
	std :: cout << std :: endl << "					RESULTADOS DO ALUGUEL											" << std :: endl ;
	std :: cout << "------------------------------------------------------------------------------------------------" << std :: endl ;
	std :: cout << std :: endl;
	
	std :: cout << "\t Marca do veículo: " << loja.getMarca() << std :: endl;
	std :: cout << "\t Modelo: " << loja.getModelo() << std :: endl;
	std :: cout << "\t Ano: " << loja.getAno_Carro() << std :: endl;
	std :: cout << std :: fixed << std :: setprecision(2);
	std :: cout << "\t Valor total do aluguel: " << loja.getValor_aluguel() << std :: endl;
	std :: system("pause");
	
	return 0;
}
