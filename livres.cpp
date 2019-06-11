#include<fstream>
#include<iomanip>
#include"livres.h"// appele le fichier header livres.h qui contient la declaration de la classe livres
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------Fonction memeber AFFICHER pour afficher des  livres --------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void livres::Afficher(){
	//Objet pour accee au fichier liste_livres.txt qui situe a cote de notre source .cpp, et pour lire les donne de fichier.
	ifstream ilivre;
	//Acce au fichier
    ilivre.open("liste_livres.txt");
    //Test pour afficher le message 'erreur' si il ta un probleme lors de l'ouverture de fichier.
    if(ilivre.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
	    //pour decoration
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(55)<< " Liste des livres disponsible" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
	/* notre fichier est bien organiser, telque avant chaque titre du livre il ya '$', donc il faut cree un boucle qui chercher la lettre
		 '$' et lire la phrase qui situe immediatement apres ce symbole, et qu'est le titre de livre*/
	string line,comp="$";
	//la sortie de la boucle c'est jusqu'a la fin de fichier
	while(!ilivre.eof()){
	// getline c'est pour lire la phrase au lieu d'une seul mot. mais ice par foi on utilise getline just pour sauter la ling
	getline(ilivre,line);
	// si le mot que nous lisons est $ alors le programme va lire la phrase qui situe immediatement apres $ et qu'est le titre du livre
	if(comp==line){
		getline(ilivre,line);
		if(comp!=line){
	//Decoration et affichage de titre apres que la condition comp!=line est vraie
	for (int l = 0; l < 80; l++) cout << "_";
	cout<<char(219)<<char(219)<<" "<<line<<endl;
	for (int l = 0; l < 80; l++) cout << "_";
	}
}
}
}
// ferme notre fichier
	ilivre.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------Fonction memeber AJOUTER pour Ajouter des information sur le livres --------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void livres::Ajouter(){
/*Objet pour accee au fichier liste_clients.txt qui situe a cote de notre source .cpp, et pour ecrire les donnees  dans ce fichier,
 ios::app c'est pour commencer a ecrir à la fin de fichier*/
	ofstream olivre("liste_livres.txt",ios::app);
// test simple
    if(olivre.fail()){
    	cout<<"erreur";
    	exit(1);
	}
		else{
	// cin.ignore c'est d'oublier cin et permettre d'utiliser getline(cin,variable) pour lire la phrase pas un seul mot	
	cin.ignore();
	//Tapage des informations par utilisateur pour les ajouter dans le fichier . txt
    cout<<"\nCode de livre (ISBN): ";
    getline(cin,ISBN);
    cout<<"\nTitre de livre: ";
    getline(cin,Titre);
    cout<<"\nAuteur de livre: ";
    getline(cin,Auteur);
    cout<<"\nEditeur de livre: ";
    getline(cin,Editeur);
    cout<<"\nAnne de livre : ";
    getline(cin,Anne);
    cout<<"\nPrix de livre (en DH): ";
    cin>>Prix;
    // ajouter les information au fichier
    olivre<<endl<<Titre<<endl;
    olivre<<ISBN<<endl;
    olivre<<Auteur<<endl;
    olivre<<Editeur<<endl;
    olivre<<Anne<<endl;
    olivre<<Prix<<endl<<"$";
}
// fermer le fichier
    olivre.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------Fonction memeber Suprimer pour suprimer les donne dans notre fichier---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void livres::Suprimer(){
/*le principe c'est de copier tous les donne qui ne depend pas du livre, et de et les mettre dans le fichier temp
 et de suprimer le fichier liste_livre,apres changer le nom de fichier a liste_livres*/	
	
/*Objet pour accee au fichier liste_livres.txt qui situe a cote de notre source .cpp, et pour ecrire les donnees  dans le fichier temp,
 et lire les donne d'apres le fichier liste_livre*/
	ifstream ilivre("liste_livres.txt");
	ofstream olivre("temp.txt");
	// test simple
    if(ilivre.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
		string cmp,line;
		int i;
		cout<<"Le livre a suprimer"<<endl;
		cin.ignore();
        getline(cin,cmp);
        // on a utiliser la fonction memebere seek pour commencez  a lire dès le premier du fichier
        ilivre.seekg(0);
        // appelle getline pour lire la premiere phrase, on na pas l'afficher , pzrceque ici c'est just pour sauter la premier ling qu'est '$'
        getline(ilivre,line);
        //boucle pour chercher le livre qu'on souhaite a suprimer
        while(!ilivre.eof()){
        	if(cmp!=line){
        	//tandis que les donne sont different de nome du livre, on va transformer ces donnees a le fichier temp
        	olivre << line <<endl;
        	getline(ilivre,line);
		}
			else{
	//une fois notre programme trouver le nome du livre, il va sauter les 6 ling de fichier, qui contient les information de livre.
		for(i=0;i<=6;i++) {
		getline(ilivre,line);
		}	
	}
}   olivre<<"$";
	olivre.close();
	ilivre.close();
// suprimer le fichier
remove("liste_livres.txt");
//changer le nome de fichier a liste_livres
rename("temp.txt","liste_livres.txt");
cout<<"\n Fait!"<<endl;
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Modifier ---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void livres::Modefier(){
/* le principe c'est la meme que la fonction  suprimme, just la différence c'est que ici lorsque le programme trouver le livre qu'on
qu'on souhait a modifier il va copier les informations ce qui  l'utilisateur a ecrit*/
	ifstream ilivre("liste_livres.txt");
	ofstream olivre("temp.txt");
	// test simple
    if(ilivre.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
		system("cls");
			// Decoration
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(55)<< " Nome de livre a modifier:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		string cmp,line;
		int k,i;
		cin.ignore();
		getline(cin,cmp);
         system("cls");  
         //Tapage les information qu'on souhaite à remplacer.
    cout<<"\nCode du livre (ISBN): ";
    getline(cin,ISBN);
    cout<<"\nTitre du livre: ";
    getline(cin,Titre);
    cout<<"\nPremier auteur de livre: ";
    getline(cin,Auteur);
    cout<<"\nEditeur du livre: ";
    getline(cin,Editeur);
    cout<<"\nAnne d'edition du Livre: ";
    getline(cin,Anne);
    cout<<"\nPrix du livre (en DH): ";
    cin>>Prix;
    //ici on a utilier les memes instructions que de la fonction suprimer
        ilivre.seekg(0);
        getline(ilivre,line);
        while(!ilivre.eof()){
        	if(cmp!=line){
        	olivre << line <<endl;
        	getline(ilivre,line);
		}
		else{
		//seul differance ici c'est de copier les information et les mettre dans notre fichier temp
		olivre<<Titre<<endl;
		getline(ilivre,line);
		olivre<<ISBN<<endl;
		getline(ilivre,line);
		olivre<<Auteur<<endl;
		getline(ilivre,line);
		olivre<<Editeur<<endl;
		getline(ilivre,line);
		olivre<<Anne<<endl;
		getline(ilivre,line);
		olivre<<Prix<<endl;
		getline(ilivre,line);
	}
	}
	olivre<<"$";
	}
	olivre.close();
	ilivre.close();
remove("liste_livres.txt");
rename("temp.txt","liste_livres.txt");
cout<<"\n Fait!"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Recherche ---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void livres::Rechercher(){
		string line,cmp;
		ifstream ilivre;
    ilivre.open("liste_livres.txt");
    if(ilivre.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else{
		//decoration
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(50)<< "Livre a recharcher:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		cin.ignore();
		getline(cin,cmp);
		/*le principe de cette boucle de chercher le nome de livre et lire le nome du livre et aussi c'est 5 autres information qui situee
		 bas du titre du livre*/
	while(!ilivre.eof()){
		if(cmp==line){
		system("cls");  
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(48)<< " Resultat:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		cout<<endl<<endl;
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Nom de livre: "<<setw(37)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(ilivre,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Code du livre (ISBN):"<<setw(30)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(ilivre,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Titre du livre:"<<setw(36)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(ilivre,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Premier auteur de livre:"<<setw(27)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout <<"_";
		getline(ilivre,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Anne d'edition du Livre:"<<setw(27)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(ilivre,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Prix du livre (en DH):"<<setw(29)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(ilivre,line);
		}
	else{
		//si la condition est  fausse, sauter la ling.
		getline(ilivre,line);
	}
	}
	}
	ilivre.close();
}
