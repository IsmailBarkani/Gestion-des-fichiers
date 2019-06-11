#include<iostream>
#include<string>
using namespace std;
class commande{
	private:// declaration des atributs qui son des caracteridtique de cette categorie
    string IDCM;
    string IDCCM;
    string Date;
    float Total;
	public:
    void Afficher();//pour afficher les donne
	void Ajouter();//pour ajouter des donner
	void Modefier();//pour modifier des donner
	void Suprimer();//pour suprimer des donner
	void Rechercher();// pour chercher des donner
};
