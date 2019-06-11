#include<iostream>
#include<string>
using namespace std;
class livres{
	private:// declaration des atributs qui son des caracteridtique de cette categorie
	string ISBN;
	string Titre;
	string Auteur;
	string Editeur;
	string Anne;
	float Prix;
	public:
    void Afficher();//pour afficher les donne
	void Ajouter();//pour ajouter des donner
	void Modefier();//pour modifier des donner
	void Suprimer();//pour suprimer des donner
	void Rechercher();// pour chercher des donner
};
