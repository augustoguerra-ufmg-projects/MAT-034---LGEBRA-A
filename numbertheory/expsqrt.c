// arquivo :	expsqrt.c
// descricao :	implementacao de uma exponenciacao por quadrados rapida recursiva
// autor :	Augusto Guerra de Lima - augustoguerra@dcc.ufmg.br
// historico :	20241024 arquivo criado

// O algoritmo de exponenciacao por quadradados tem uma cota superior de complexidade inferior a versao ingenua
// ele se baseia na seguinte recorrencia 

// x^n := 1, n=0 
// x^n := x^{n/2}x^{n/2} , n par = (x^2)^{n/2}
// x^n := x^{n-1}x , n impar = x(x^2)^{(n-1)/2}

// existe a exponenciao modular que e usada frequentemente quando o valor do inteiro ultrapassa o dominio comum do computador

// Entrada :	Um grupo (G,*) onde x, n \in G
// Saida :	x^n* \in G

// Complexidade :	O(log(n)) no numero de iteracoes

#include<stdio.h>

long long expsqrt(int x, int n)
{
	if(n==0)return(1);
	long long u = expsqrt(x*x, n/2);
	
	if(n%2==1)u*=x;

	return(u);
}
