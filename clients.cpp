#include<fstream>
#include<iomanip>
#include"clients.h"// appele le fichier header clients.h qui contient la declaration de la classe clients
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------Fonction memeber AFFICHER pour afficher des  livres --------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clients::Afficher(){
	//Objet pour accee au fichier liste_clients.txt qui situe a cote de notre source .cpp, et pour lire les donne de ce fichier.
	ifstream iclient;
	//Acce au fichier
    iclient.open("liste_clients.txt");
    //Test pour afficher le message 'erreur' si il ta un probleme lors de l'ouverture de fichier.    
    if(iclient.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
	//pour decoration	
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(55)<< " Liste des clients" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
	/* notre fichier est bien organiser, telque avant chaque nom du client il ya '$', donc il faut cree un boucle qui chercher la lettre
		 '$' et lire la phrase qui situe immediatement apres ce symbole, et qu'est le nom de client */		
	string line,comp="$" ;
	//la sortie de la boucle c'est jusqu'a la fin de fichier	
	while(!iclient.eof()){
	// getline c'est pour lire la phrase au lieu d'une seul mot. mais ice par foi on utilise getline just pour sauter la ling		
	getline(iclient,line);
	// si le mot que nous lisons est $ alors le programme va lire la phrase qui situe immediatement apres $ et qu'est le nome de client	
	if(comp==line){
		getline(iclient,line);
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
	iclient.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------Fonction memeber AJOUTER pour AJOUTER des information sur le livres --------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clients::Ajouter(){
	/*Objet pour accee au fichier liste_clients.txt qui situe a cote de notre source .cpp, et pour ecrire les donnees  dans ce fichier,
 ios::app c'est pour commencer a ecrir à la fin de fichier*/
	ofstream oclient("liste_clients.txt",ios::app);
	// test simple
    if(oclient.fail()){
    	cout<<"erreur";
    	exit(1);
	}
		else{
	// cin.ignore c'est d'oublier cin et permettre d'utiliser getline(cin,variable) pour lire la phrase pas un seul mot	
	cin.ignore();
	//Tapage des informations par utilisateur pour les ajouter dans le fichier . txt	
    cout<<"\nIdentification (IDC): ";
    getline(cin,IDC);
    cout<<"\nNom: ";
    getline(cin,Nom);
    cout<<"\nAdresse: ";
    getline(cin,Adresse);
    cout<<"\nNumero du telephone:(+212)";
    getline(cin,Tel);
    cout<<"\nDate d'inscription: ";
  // ajouter les information au fichier 
    getline(cin,Anciente);
    oclient<<endl<<Nom<<endl;
    oclient<<IDC<<endl;
    oclient<<Adresse<<endl;
    oclient<<Tel<<endl;
    oclient<<Anciente<<endl<<"$";
}
// fermer le fichier
    oclient.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Suprimer---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clients::Suprimer(){
/*le principe c'est de copier tous les donne qui ne depend pas du client, et de et les mettre dans le fichier temp
 et de suprimer le fichier liste_client,apres changer le nom de fichier a liste_client*/	
	
/*Objet pour accee au fichier liste_clients.txt qui situe a cote de notre source .cpp, et pour ecrire les donnees  dans le fichier temp,
 et lire les donne d'apres le fichier liste_livre*/
	ifstream iclient("liste_clients.txt");
	ofstream oclient("tempp.txt");
	// test simple	
    if(iclient.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
		string cmp,line;
		int i;
		cout<<"Le client a suprimer"<<endl;
		cin.ignore();
        getline(cin,cmp);
        // on a utiliser la fonction memebere seek pour commencez  a lire dès le premier du fichier        
        iclient.seekg(0);
        // appelle getline pour lire la premiere phrase, on na pas l'afficher , pzrceque ici c'est just pour sauter la premier ling qu'est '$'        
        getline(iclient,line);
          //boucle pour chercher le client qu'on souhaite a suprimer      
        while(!iclient.eof()){
        	if(cmp!=line){
        	oclient << line <<endl;
        	getline(iclient,line);
		}
			else{
	//une fois notre programme trouver le nome du client, il va sauter les 6 ling de fichier, qui contient les information de client.				
		for(i=0;i<=5;i++) {
		getline(iclient,line);
		}	
	}
}   oclient<<"$";
	oclient.close();
	iclient.close();
// suprimer le fichier	
remove("liste_clients.txt");
//changer le nome de fichier a liste_clients
rename("tempp.txt","liste_clients.txt");
cout<<"\n Fait!"<<endl;
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Modifier ---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clients::Modefier(){
	/* le principe c'est la meme que la fonction  suprimme, just la différence c'est que ici lorsque le programme trouver le client qu'on
qu'on souhait a modifier il va copier les informations ce qui  l'utilisateur a ecrit*/
	ifstream iclient("liste_clients.txt");
	ofstream oclient("temp.txt");
	// test simple
    if(iclient.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else {
		system("cls"); 
			// Decoration		 
		for (int l = 0; l < 80; l++) cout << char(205);
cout << "" << setw(55)<< " Nome de client a modifier:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		string cmp,line;
		int k,i;
		cin.ignore();
		getline(cin,cmp);
         system("cls"); 
         //Tapage les informations qu'on souhaite à remplacer.		  
    cout<<"\nIdentification: ";
    getline(cin,IDC);
    cout<<"\nNom: ";
    getline(cin,Nom);
    cout<<"\nAdresse :";
    getline(cin,Adresse);
    cout<<"\nTel (+212): ";
    getline(cin,Tel);
    cout<<"\nAnciente : ";
    getline(cin,Anciente);
    //ici on a utilier les memes instructions que de la fonction suprimer 
        iclient.seekg(0);
        getline(iclient,line);
        while(!iclient.eof()){
        	if(cmp!=line){
        	oclient << line <<endl;
        	getline(iclient,line);
		}
		else{
		//seul differance ici c'est de copier les information et les mettre dans notre fichier temp			
		oclient<<Nom<<endl;
		getline(iclient,line);
		oclient<<IDC<<endl;
		getline(iclient,line);
		oclient<<Adresse<<endl;
		getline(iclient,line);
		oclient<<Tel<<endl;
		getline(iclient,line);
		oclient<<Anciente<<endl;
		getline(iclient,line);
	}
	}
	oclient<<"$";
	}
	oclient.close();
	iclient.close();
remove("liste_clients.txt");
rename("temp.txt","liste_clients.txt");
cout<<"\n Fait!"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------Fonction memeber Recherche ---------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clients::Rechercher(){
		string line,cmp;
		ifstream iclient;
    iclient.open("liste_clients.txt");
    if(iclient.fail()){
    	cout<<"erreur";
    	exit(1);
	}
	else{
			//decoration	
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(50)<< " Client a recharcher:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		cin.ignore();
		getline(cin,cmp);
		/*le principe de cette boucle de chercher le nome du client et lire le nome du client et aussi c'est 4 autres informations qui situee
		 bas du titre du client*/
	  while(!iclient.eof()){
		if(cmp==line){
			system("cls");  
		for (int l = 0; l < 80; l++) cout << char(205);
        cout << "" << setw(48)<< " Resultat:" <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
		cout<<endl<<endl;
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Identifiant du client: "<<setw(27)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(iclient,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Nom ou raiso sociale: "<<setw(28)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(iclient,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Adresse du client: "<<setw(31)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(iclient,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Numero de Telephone: "<<setw(29)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout <<"_";
		getline(iclient,line);
		for (int l = 0; l < 80; l++) cout << "_";
         cout <<"Date d'inscripion du client: "<<setw(21)<<char(219)<<char(219)<<" "<<setw(5)<<line<<endl;
		for (int star = 0; star < 80; star++) cout << "_";
		getline(iclient,line);
		}
	else{
//si la condition est  fausse, sauter la ling.		
		getline(iclient,line);
	}
	}
	}
	iclient.close();
}
