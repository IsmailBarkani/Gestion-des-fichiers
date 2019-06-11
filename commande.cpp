#include<fstream>
#include<iomanip>
#include"commande.h"// appele le fichier header livres.h qui contient la declaration de la classe commande
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------Fonction memeber AFFICHER pour afficher des  livres --------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void commande::Afficher(){
	ifstream icommande;
    icommande.open("liste_commande.txt");
    if(icommande.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
		for (int l = 0; l < 80; l++) cout << char(205);
cout << "" << setw(55)<< " Liste des commandes" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		string line,comp="$";
	while(!icommande.eof()){
	getline(icommande,line);
	if(comp==line){
		getline(icommande,line);
		if(comp!=line){
	for (int l = 0; l < 80; l++) cout << "_";
	cout<<char(219)<<char(219)<<" "<<line<<endl;
	for (int l = 0; l < 80; l++) cout << "_";
	}
}
}
}
	icommande.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------Fonction memeber AJOUTER pour AJOUTER des information sur le livres --------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void commande::Ajouter(){
	ofstream ocommande("liste_commande.txt",ios::app);
    if(ocommande.fail()){
    	cout<<"erreur";
    	exit(1);
	}
		else{
			cin.ignore();
    cout<<"\n Identification de la commande (IDCM): ";
    getline(cin,IDCM);
    cout<<"\nIdentification du client ayant passe la commande: ";
    getline(cin,IDCCM);
    cout<<"\nDate de la commande: ";
    getline(cin,Date);
    cout<<"\nPrix Total de la commane (en DH): ";
    cin>>Total;
    ocommande<<endl<<IDCM<<endl;
    ocommande<<IDCCM<<endl;
    ocommande<<Date<<endl;
    ocommande<<Total<<endl<<"$";
}
    ocommande.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Suprimer---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void commande::Suprimer(){
	ifstream icommande("liste_commande.txt");
	ofstream ocommande("tempt.txt");
    if(icommande.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
		string cmp,line;
		int i;
		cout<<"Taper le nombre de merite de livre"<<endl;
		cin.ignore();
        getline(cin,cmp);
        icommande.seekg(0);
        getline(icommande,line);
        while(!icommande.eof()){
        	if(cmp!=line){
        	ocommande << line <<endl;
        	getline(icommande,line);
		}
			else{
		for(i=0;i<=6;i++) {
		getline(icommande,line);
		}	
	}
}   ocommande<<"$";
	ocommande.close();
	icommande.close();
remove("liste_commande.txt");
rename("tempt.txt","liste_commande.txt");
cout<<"\n Fait!"<<endl;
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Modifier ---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void commande::Modefier(){
		ifstream icommande("liste_commande.txt");
	ofstream ocommande("tempt.txt");
    if(icommande.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
		system("cls");  
		for (int l = 0; l < 80; l++) cout << char(205);
cout << "" << setw(55)<< " Le commande a modifier:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		string cmp,line;
		int k,i;
		cin.ignore();
		getline(cin,cmp);
         system("cls");  
    cout<<"\nIdentifiant de la commande (IDCM): ";
    getline(cin,IDCM);
    cout<<"\nIdentifiant du client ayant passé la commande: ";
    getline(cin,IDCCM);
    cout<<"\nDate de la commande: ";
    getline(cin,Date);
    cout<<"\nPrix Total de la commande (en DH): ";
    cin>>Total;
        icommande.seekg(0);
        getline(icommande,line);
        while(!icommande.eof()){
        	if(cmp!=line){
        	ocommande << line <<endl;
        	getline(icommande,line);
		}
		else{
		ocommande<<IDCM<<endl;
		getline(icommande,line);
		ocommande<<IDCCM<<endl;
		getline(icommande,line);
		ocommande<<Date<<endl;
		getline(icommande,line);
		ocommande<<Total<<endl;
		getline(icommande,line);
	}
	}
	ocommande<<"$";
	}
	ocommande.close();
	icommande.close();
remove("liste_commande.txt");
rename("tempt.txt","liste_commande.txt");
cout<<"\n Fait!"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Recherche ---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void commande::Rechercher(){
		string line,cmp;
		ifstream icommande;
    icommande.open("liste_commande.txt");
    if(icommande.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else{
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(50)<< " Commande a recharcher:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		cin.ignore();
		getline(cin,cmp);
	while(!icommande.eof()){
		if(cmp==line){
			system("cls");  
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(48)<< " Resultat:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		cout<<endl<<endl;
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Identifiant de commande:"<<setw(37)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(icommande,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Identifiant du client ayant passe le commande: "<<setw(14)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(icommande,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Date de commande"<<setw(45)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(icommande,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Prix total de la commande: "<<setw(34)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout <<"_";
		getline(icommande,line);
		for (int l = 0; l < 80; l++) cout << "_";
		}
	else{
		getline(icommande,line);
	}
	}
	}
	icommande.close();
}
