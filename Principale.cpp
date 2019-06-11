#include<fstream>
#include<string.h>
#include<iomanip>// bibliotique nous permer  d'utiliser la fonction setw()
#include"livres.h"// appele le fichier header livres.h qui contient la declaration de la classe livres
#include"clients.h"// appele le fichier header clients.h qui contient la declaration de la classe clients
#include"commande.h"// appele le fichier header livres.h qui contient la declaration de la classe commande
using namespace std;
int main(){
	//decoration , colore de background 1 de text 6
	system("COLOR 16");
    Menu:// menu principale
	int choix; // on ddeclare choix pour lui affecter des choix
	// evidament utilisons boucle while pour  afficher le menu tendis que le choix n'est pas fait
		while(choix!=4 && choix!=3 && choix!=2  && choix!=1){
		// decoration
		for (int l = 0; l < 80; l++) cout << char(205);
	cout << "" << setw(30)<<char(219)<<char(219)<< " Menu Principale " <<char(219)<<char(219)<<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
	cout<<"\n";
	cout<<setw(25)<<char(178);
	for (int l = 0; l < 30; l++) cout<< char(178);
	cout<<"\n"<<setw(25)<<char(178)<< setw(30)<<char(178)<<"\n";
	cout<<"" << setw(25)<<char(178)<<" (1) Gestion des livres."<< setw(6)<<char(178)<<endl;
	cout<<"" << setw(25)<<char(178)<<" (2) Gestion des clients."<< setw(5)<<char(178)<<endl;
	cout<<"" << setw(25)<<char(178)<<" (3) Gestion des commandes."<< setw(3)<<char(178)<<endl;
	cout<<"" << setw(25)<<char(178)<<" (4) Quitter."<< setw(17)<<char(178)<<endl;
	cout<<setw(25)<<char(178)<< setw(30)<<char(178)<<"\n";
	cout<<setw(25)<<char(178);
	for (int l = 0; l < 30; l++) cout<< char(178);
	cout<<"\n";
		cout<<"\n Votre Choix:"<<endl;
		cout<<"\n"<<char(219)<<" ";
        cin>> choix;
       //affecter le choix 
         system("cls");
         //utilison switch() pour discuter le choix d'utilisateur
		switch(choix){
			case 1: { goto livre;
			break;
			}
			case 2: { goto client;
			break;
			}
			case 3: { goto commande;
			break;
			}
			case 4: { goto Fin;
			break;
			}
			default: goto Menu;
			break;
			}
		}
livre:
	// meme decoration se fait avec le menu gestion des livres
	for (int l = 0; l < 80; l++) cout << char(205);
	cout << "" << setw(50)<< " Gestion des livres. " <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
	cout<<"\n";
	cout<<setw(20)<<char(178);
	for (int l = 0; l < 37; l++) cout<< char(178);
	cout<<"\n"<<setw(20)<<char(178)<< setw(37)<<char(178)<<"\n";
	cout<<"" << setw(20)<<char(178)<<" (1) Afficher la liste des livres."<< setw(3)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (2) Ajouter un livre."<< setw(15)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (3) Supprimer un livre"<< setw(14)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (4) Modifier un livre."<< setw(14)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (5) Rechercher un livre."<< setw(12)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (6) Revenir au menu precedent."<< setw(6)<<char(178)<<endl;
	cout<<setw(20)<<char(178)<< setw(37)<<char(178)<<"\n";
	cout<<setw(20)<<char(178);
	for (int l = 0; l < 37; l++) cout<< char(178);
	cout<<"\n";
		cout<<"\n Votre Choix:"<<endl;
		cout<<"\n"<<char(219)<<" ";
        cin>> choix;
        system("cls");
       switch(choix){
       	case 1:{ livres objet1;//declaration d'objet de type livres pour faire appele a des fonctions memebre de classe livres
       	         objet1.Afficher();//faire appel a la fonction Affiche()
       	         string Re;
                cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re;
       	         system("cls");
       	         if(Re=="1") goto livre;
       	         system("cls");
			break;
		   }
		   case 2:{ livres objet2;
           objet2.Ajouter();//faire appel a la fonction Ajouter()
           string Re;
             cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;     
			   	cin>>Re;
       	         system("cls");
       	         if(Re=="1") goto livre;
       	         system("cls");
                     break;
		   }
		   case 3:{ livres objet3;
		   objet3.Afficher();//faire appel a la fonction Affiche()
           objet3.Suprimer();//faire appel a la fonction suprimmer()
           string Re;
             system("cls");  
           cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl; 
		         	   cin>>Re;
       	         if(Re=="1") goto livre;
       	         system("cls");
                     break;
		   }
		   case 4:{ livres objet4;
		    string Re;
           objet4.Modefier();//faire appel a la fonction Modifier()
            cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
        	   cin>>Re;
       	         system("cls");
       	         if(Re=="1") goto livre;
       	         system("cls");
                     break;
		   }
		   case 5:{ livres objet5;
		    string Re;
           objet5.Rechercher();//faire appel a la fonction Rechercher()
           cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	   cin>>Re;
       	         system("cls");
       	         if(Re=="1") goto livre;
       	         system("cls");
                     break;
		   }
		   case 6:{ 
       	         goto Menu;
       	         system("cls");
                     break;
		   }
default:{
	goto Menu;
		break;
}
	   }
	client:
		for (int l = 0; l < 80; l++) cout << char(205);
	cout << "" << setw(50)<< " Gestion des livres. " <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
	cout<<"\n";
	cout<<setw(20)<<char(178);
	for (int l = 0; l < 37; l++) cout<< char(178);
	cout<<"\n"<<setw(20)<<char(178)<< setw(37)<<char(178)<<"\n";
	cout<<"" << setw(20)<<char(178)<<" (1) Afficher la liste des clients."<< setw(2)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (2) Ajouter un client."<< setw(14)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (3) Supprimer un client"<< setw(13)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (4) Modifier un client."<< setw(13)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (5) Rechercher un client."<< setw(11)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (6) Revenir au menu precedent."<< setw(6)<<char(178)<<endl;
	cout<<setw(20)<<char(178)<< setw(37)<<char(178)<<"\n";
	cout<<setw(20)<<char(178);
	for (int l = 0; l < 37; l++) cout<< char(178);
	cout<<"\n";
		cout<<"\n Votre Choix:"<<endl;
		cout<<"\n"<<char(219)<<" ";
        cin>> choix;
         system("cls");
        switch(choix){
       	case 1:{ clients objet1;
       	         objet1.Afficher();
       	         string Re1;
                cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
				       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto client;
       	         system("cls");
			break;
		   }
		   case 2:{ clients objet2;
           objet2.Ajouter();
           string Re1;
               cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto client;
       	         system("cls");
                     break;
		   }
		   case 3:{ clients objet3;
		   objet3.Afficher();
           objet3.Suprimer();
           string Re1;
             system("cls");  
              cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto client;
       	         system("cls");
                     break;
		   }
		   case 4:{ clients objet3;
		              string Re1;
           objet3.Modefier();
            cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto client;
       	         system("cls");
                     break;
		   }
		   case 5:{ clients objet3;
		              string Re1;
           objet3.Rechercher();
               cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto client;
       	         system("cls");
                     break;
		   }
		   case 6:{ 
       	         goto Menu;
       	         system("cls");
                     break;
		   }
default:{
	goto client;
	break;
}
	commande:
		for (int l = 0; l < 80; l++) cout << char(205);
	cout << "" << setw(50)<< " Gestion des livres. " <<endl;
		for (int star = 0; star < 80; star++) cout << char(205);
	cout<<"\n";
	cout<<setw(20)<<char(178);
	for (int l = 0; l < 38; l++) cout<< char(178);
	cout<<"\n"<<setw(20)<<char(178)<< setw(38)<<char(178)<<"\n";
	cout<<"" << setw(20)<<char(178)<<" (1) Afficher la liste des commandes"<<setw(2)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (2) Ajouter une commande"<< setw(13)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (3) Supprimer une commande"<< setw(11)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (4) Modifier une commande"<< setw(12)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (5) Rechercher une commande"<< setw(10)<<char(178)<<endl;
	cout<<"" << setw(20)<<char(178)<<" (6) Revenir au menu precedent"<< setw(8)<<char(178)<<endl;
	cout<<setw(20)<<char(178)<< setw(38)<<char(178)<<"\n";
	cout<<setw(20)<<char(178);
	for (int l = 0; l < 38; l++) cout<< char(178);
	cout<<"\n";
		cout<<"\n Votre Choix:"<<endl;
		cout<<"\n"<<char(219)<<" ";
        cin>> choix;
         system("cls");
        switch(choix){
       	case 1:{ commande objet1;
       	         objet1.Afficher();
       	         string Re1;
                cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto commande;
       	         system("cls");
			break;
		   }
		   case 2:{ commande objet2;
           objet2.Ajouter();
           string Re1;
                cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto commande;
       	         system("cls");
                     break;
		   }
		   case 3:{ commande objet3;
		   objet3.Afficher();
           objet3.Suprimer();
           string Re1;
             system("cls");  
              cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto commande;
       	         system("cls");
                     break;
		   }
		   case 4:{ commande objet3;
		              string Re1;
           objet3.Modefier();
              cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto commande;
       	         system("cls");
                     break;
		   }
		   case 5:{ commande objet3;
		              string Re1;
           objet3.Rechercher();
             cout<<char(219)<<" Pour revenir a la liste precedante tapez sur (1): "<<endl<<endl;
       	         cin>>Re1;
       	         system("cls");
       	         if(Re1=="1") goto commande;
       	         system("cls");
                     break;
		   }
		   case 6:{ 
       	         goto Menu;
       	         system("cls");
                     break;
		   }
default:{
	goto commande;
	break;
}
Fin:
system("cls");
cout<<"" << setw(40)<<char(178)<<char(178)<<" Merci! "<<char(178)<<char(178);	
cout<<endl<<endl<<endl;;
system("PAUSE");
return 0;		
}
}
}
