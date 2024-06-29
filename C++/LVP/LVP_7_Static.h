#ifndef Conta_de_Poupanca_H
#define Conta_de_Poupanca_H

class Conta_de_Poupanca{
	
	private:
		static float taxa_juros_anual;
		float saldo_poupanca;
		void calc_rendimento_mensal();
		float rendimento_mensal;
		
	public:
		Conta_de_Poupanca(float = 0.0);
		~Conta_de_Poupanca();
		static void setTaxa_juros_anual(float);
		void setSaldo_poupanca(float);
		
		static float getTaxa_juros_anual();
		float getSaldo_poupanca() const;
		float getRendimento_mensal();
		
};

#endif
