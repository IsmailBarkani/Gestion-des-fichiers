#include<iostream>
#include<string>
using namespace std;
class clients{
	private:// declaration des atributs qui son des caracteridtique de cette categorie
	string IDC;
	string Nom;
	string Adresse;
	string Tel;
	string Anciente;
	public:
    void Afficher();//pour afficher les donne
	void Ajouter();//pour ajouter des donner
	void Modefier();//pour modifier des donner
	void Suprimer();//pour suprimer des donner
	void Rechercher();// pour chercher des donner
};
