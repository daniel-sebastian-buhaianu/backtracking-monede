#include <fstream>
#define NR_MAXIM_SACI 20
using namespace std;
// fisiere citire/scriere
ifstream fin("suma.in");
ofstream fout("suma.out");
// variabile globale
int sumaDeAchitat, sumaCurenta, nrSaci, nrSolutii;
int nrMonedeFolositeDinSacul[NR_MAXIM_SACI];
struct { int nrMonede, valoareMoneda; } sac[NR_MAXIM_SACI];
// functii ajutatoare
void citesteDateIntrare();
void achitaSuma(int);
// functia principala
int main()
{
	citesteDateIntrare();
	achitaSuma(0);
	fout.close();
	return 0;
}
void afiseazaSolutie()
{
	fout << '\n' << "Solutia " << nrSolutii << '\n';
	for (int i = 0; i < nrSaci; i++)
		if (nrMonedeFolositeDinSacul[i] > 0)
			fout << nrMonedeFolositeDinSacul[i] << " monede cu valoarea " << sac[i].valoareMoneda << '\n';
}
void achitaSuma(int nrSac)
{
	if (nrSac == nrSaci)
	{
		if (sumaCurenta == sumaDeAchitat)
		{
			nrSolutii++;
			afiseazaSolutie();
		}
	}
	else
	{
		int nrMonede= sac[nrSac].nrMonede;
		int valoareMoneda = sac[nrSac].valoareMoneda;
		for (int nr = 0;
		     nr <= nrMonede
	             && sumaCurenta + nr*valoareMoneda <= sumaDeAchitat;
		     nr++)
		{
			nrMonedeFolositeDinSacul[nrSac] = nr;
			sumaCurenta += nr*valoareMoneda;
			achitaSuma(nrSac+1);
			sumaCurenta -= nr*valoareMoneda;
		}
	}
}
void citesteDateIntrare()
{
	fin >> sumaDeAchitat;
	fin >> nrSaci;
	for (int i = 0; i < nrSaci; i++)
	{
		fin >> sac[i].nrMonede;
		fin >> sac[i].valoareMoneda;
	}
	fin.close();
}
