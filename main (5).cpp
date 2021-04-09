#include <iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
class bateau
{
private:
    int nb;
    string nom;
public:

    bateau(int a , string n){nb=a;
    nom=n;}
    bateau(){};
    int getnb(){return nb;}
    string getnom()
    {
        return nom;
    }
};

int verifier(int a,char b,char c,char l[11][11],bateau bt)
{
    int r;
    r=1;
    if ((c=='H')||(c=='h'))
    {
        if ((75-b)>= bt.getnb())
        {
            for(int i=0;i<bt.getnb();i++)
            {
                if (l[a][b-64+i]!='~')
                {
                    r=0;
                }
            }

        }
        else {r=2;}
    }
    else
        {
            if ((11-a)>= bt.getnb())
        {
            for(int i=0;i<bt.getnb();i++)
            {
                if (l[a+i][b-64]!='~')
                {
                    r=0;
                }
            }

        }
        else {r=2;}
        }
    return r ;
}
class joueur
{
private:
    int nbc_rest;
    char plateau_bataille[11][11];
    char plateau_info[11][11];
    string nick_name;
public:
    joueur(string ch)
    {
        nick_name=ch;
        nbc_rest=0;
        plateau_bataille[1][0]='1';
        plateau_bataille[2][0]='2';
        plateau_bataille[3][0]='3';
        plateau_bataille[4][0]='4';
        plateau_bataille[5][0]='5';
        plateau_bataille[6][0]='6';
        plateau_bataille[7][0]='7';
        plateau_bataille[8][0]='8';
        plateau_bataille[9][0]='9';
        plateau_bataille[10][0]='10';
        plateau_bataille[0][1]='A';
        plateau_bataille[0][2]='B';
        plateau_bataille[0][3]='C';
        plateau_bataille[0][4]='D';
        plateau_bataille[0][5]='E';
        plateau_bataille[0][6]='F';
        plateau_bataille[0][7]='G';
        plateau_bataille[0][8]='H';
        plateau_bataille[0][9]='I';
        plateau_bataille[0][10]='J';
        plateau_bataille[0][0]='X';
        plateau_info[1][0]='1';
        plateau_info[2][0]='2';
        plateau_info[3][0]='3';
        plateau_info[4][0]='4';
        plateau_info[5][0]='5';
        plateau_info[6][0]='6';
        plateau_info[7][0]='7';
        plateau_info[8][0]='8';
        plateau_info[9][0]='9';
        plateau_info[10][0]='10';
        plateau_info[0][1]='A';
        plateau_info[0][2]='B';
        plateau_info[0][3]='C';
        plateau_info[0][4]='D';
        plateau_info[0][5]='E';
        plateau_info[0][6]='F';
        plateau_info[0][7]='G';
        plateau_info[0][8]='H';
        plateau_info[0][9]='I';
        plateau_info[0][10]='J';
        plateau_info[0][0]='X';
        for(int i=1;i<11;i++)
        {for(int j=1;j<11;j++)
            {
             plateau_bataille[i][j]='~';
             plateau_info[i][j]='~';
            }
        }
    }
    int get_nbc_rest(){return nbc_rest;};
    string get_nick_name(){return nick_name;};
    void affiche1()
    {
      cout <<endl;
      for(int i=0;i<11;i++)
      {
          cout <<endl;
          for(int j=0;j<11;j++)
            cout<<plateau_bataille[i][j]<<"     ";
          cout<<endl;
      }
    }
    void affiche2()
    {
      cout <<endl;
      for(int i=0;i<11;i++)
      {
          cout <<endl;
          for(int j=0;j<11;j++)
           cout<<plateau_info[i][j]<<"     ";
          cout<<endl;
      }
    }
    void remplir(bateau l1[5],bateau l2[10],int k)
    {
        int a,r;
        r=5;
        char b,c;
        cout<< nick_name << " commencer a remplir  ton plateau"<<endl;
        affiche1();
        if (k==1)
        {
            for(int i=0;i<5;i++)
            {

              do
              {
              cout<<endl;
              cout<<"donner la premier case et la direction du bateau "<<endl<< l1[i].getnom()<< " de "<<l1[i].getnb()<<" case(s)"<<endl;
              do
              {
                 cout<<" les lignes sont entre 1 et 10"<<endl;
                 cout<<"ligne:";
                 cin>>a;
              }
              while((a<1)&&(10<a));
              cout<<endl;
              do
              {
                 cout<<" les colonnes sont entre A et J"<<endl;
                 cout<< "colonne:";
                 cin>>b;
              }
              while((b<'A')&&('G'<b));
              cout<< "direction:"<<endl<<". V pour verticale de haut vers le bas"<<endl<<". H pour horizontale du gauche vers la droite"<<endl<<"Tapez:";
              do
              {
                 cout<<" TAPEZ H OR V:"<<endl;
                 cin>>c;
              }
              while((c!='h')&&(c!='H')&&(c!='v')&&(c!='V'));
              r=verifier(a,b,c,plateau_bataille,l1[i]);
              if ((r==2)&&((c=='h')||(c=='H')))
                 cout <<"il n'y a pas assez de sapce sur la ligne"<<endl;
              else if ((r==2)&&((c=='v')||(c=='V')))
                 cout <<"il n'y a pas assez de sapce sur la colonne"<<endl;
              else if(r==0)
                 cout<<"il y a un autre bateau sur le chemin"<<endl;
              else if((r==1)&&((c=='v')||(c=='V')))
                {
                    for(int j=0;j<l1[i].getnb();j++)
                       plateau_bataille[a+j][b-64]='#';
                    nbc_rest+=l1[i].getnb();
                    affiche1();
                }
              else if((r==1)&&((c=='h')||(c=='H')))
                {
                    for(int j=0;j<l1[i].getnb();j++)
                       plateau_bataille[a][b-64+j]='#';
                    nbc_rest+=l1[i].getnb();
                    affiche1();
                }
              }
              while(r!=1);
            }
        }
        else if (k==2)
        {
          for(int i=0;i<10;i++)
            {
              do
              {
              cout<<"donner la premier case et la direction du bateau "<<endl<< l2[i].getnom()<< "de"<<l2[i].getnb()<<" case(s)"<<endl;
              do
              {
                 cout<<" les lignes sont entre 1 et 10"<<endl;
                 cout<<"ligne:";
                 cin>>a;
              }
              while((a<1)&&(10<a));
              cout<<endl;
              do
              {
                 cout<<" les colonnes sont entre A et J"<<endl;
                 cout<< "colonne:";
                 cin>>b;
              }
              while((b<'A')&&('G'<b));
              cout<< "direction:"<<endl<<". V pour verticale de haut vers le bas"<<endl<<". H pour horizontale du gauche vers la droite"<<endl<<"Tapez:";
              do
              {
                 cout<<" TAPEZ H OR V:"<<endl;
                 cin>>c;
              }
              while((c!='h')&&(c!='H')&&(c!='v')&&(c!='V'));
              r=verifier(a,b,c,plateau_bataille,l2[i]);
              if ((r==2)&&((c=='h')||(c=='H')))
                 cout <<"il n'y a pas assez de sapce sur la ligne"<<endl;
              else if ((r==2)&&((c=='v')||(c=='V')))
                 cout <<"il n'y a pas assez de sapce sur la colonne"<<endl;
              else if(r==0)
                 cout<<"il y a un autre bateau sur le chemin"<<endl;
              else if((r==1)&&((c=='v')||(c=='V')))
                {
                    for(int j=0;j<l2[i].getnb();j++)
                       plateau_bataille[a+j][b-64]='#';

                    nbc_rest+=l2[i].getnb();
                    affiche1();
                }
              else if((r==1)&&((c=='h')||(c=='H')))
                {
                    for(int j=0;j<l2[i].getnb();j++)
                       plateau_bataille[a][b-64+j]='#';

                    nbc_rest+=l2[i].getnb();
                    affiche1();
                }
            }
            while(r!=1);
        }
        }

    }
 void attack(joueur& j)
 {
     int a,x;
     x=0;
     char b;
     do
     {
     cout<<"tu as "<< nbc_rest<<" case(s) restante(s)"<<endl;
     affiche1();
     affiche2();
     cout<< nick_name <<" choisir une case de plateau pour l'attacker"<<endl;
     do
     {
        cout<<" les lignes sont entre 1 et 10"<<endl;
        cout<<"ligne:";
        cin>>a;
     }
     while((a<1)&&(10<a));
     cout<<endl;
     do
     {
        cout<<" les colonnes sont entre A et J"<<endl;
        cout<< "colonne:";
        cin>>b;
     }
     while((b<'A')&&('G'<b));
     if((j.plateau_bataille[a][b-64]=='X')||(j.plateau_bataille[a][b-64]=='Ø'))
        cout<<"tu as deja attackee cette case"<<endl;
     }
     while((j.plateau_bataille[a][b-64]=='X')||(j.plateau_bataille[a][b-64]=='Ø'));

     if(j.plateau_bataille[a][b-64]=='#')
     {
         cout<<"bon attack"<<endl;
         j.plateau_bataille[a][b-64]='X';
         plateau_info[a][b-64]='X';
         j.nbc_rest=j.nbc_rest-1;
     }
     else if(j.plateau_bataille[a][b-64]=='~')
     {
        cout<<" tu as raté"<<endl;
        j.plateau_bataille[a][b-64]='Ø';
        plateau_info[a][b-64]='Ø';
     }


 }
 void robot_remplir(bateau l1[5],bateau l2[10],int k)
 {
     int a,b,r,c;
     char c1;
        if (k==1)
        {
            for(int i=0;i<5;i++)
            {
              r=0;
              srand(time(0));
              while(r!=1)
               {
                  a=(rand()%10)+1;
                  b=(rand()%10)+1;
                  c=rand()%2;
                  if(c==0)
                  {
                      c1='h';
                      r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      if(r!=1)
                      {
                          c1='v';
                          r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      }

                  }
                  else if((c==1)&&(r!=1))
                  {
                      c1='v';
                      r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      if(r!=1)
                      {
                          c1='h';
                          r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      }
                  }
               }
              if(c1=='v')
                {
                    for(int j=0;j<l1[i].getnb();j++)
                       plateau_bataille[a+j][b]='#';
                    nbc_rest+=l1[i].getnb();
                }
              else if(c1=='h')
                {
                    for(int j=0;j<l1[i].getnb();j++)
                       plateau_bataille[a][b+j]='#';
                    nbc_rest+=l1[i].getnb();
                }
            }
        }
        else if (k==2)
        {
          for(int i=0;i<10;i++)
            {
              r=0;
              srand(time(0));
              while(r!=1)
               {
                  a=(rand()%10)+1;
                  b=(rand()%10)+1;
                  c=rand()%2;
                  if(c==0)
                  {
                      c1='h';
                      r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      if(r!=1)
                      {
                          c1='v';
                          r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      }

                  }
                  else if((c==1)&&(r!=1))
                  {
                      c1='v';
                      r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      if(r!=1)
                      {
                          c1='h';
                          r=verifier(a,b,c1,plateau_bataille,l1[i]);
                      }
                  }
               }
              if(c1=='v')
                {
                    for(int j=0;j<l2[i].getnb();j++)
                       plateau_bataille[a+j][b]='#';
                    nbc_rest+=l2[i].getnb();
                }
              else if(c1=='h')
                {
                    for(int j=0;j<l2[i].getnb();j++)
                       plateau_bataille[a][b+j]='#';
                    nbc_rest+=l2[i].getnb();
                }

            }
            }
        }
void robot_attack(joueur& j,int& k1,int& a1,int& b1 , int& a2,int& b2,int& co,int& k2 ,int& x2,int& x3)
{
    int a,b,r1;
    srand(time(0));
    if (k1==0)
    {
      r1=0;
      while (r1!=1)
      {
      a=(rand()%10)+1;
      b=(rand()%10)+1;
      if ((j.plateau_bataille[a][b]=='#')||(j.plateau_bataille[a][b]=='~'))
            r1=1;
      }
      if (j.plateau_bataille[a][b]=='#')
      {
          plateau_info[a][b]='X';
          j.plateau_bataille[a][b]='X';
          k1=1;
          a1=a;
          b1=b;
          cout<<"le robot a detruit une piece d'un bateau"<<endl;
          j.affiche1();
          j.nbc_rest-=1;
      }
      else if (j.plateau_bataille[a][b]=='~')
      {
          plateau_info[a][b]='Ø';
          j.plateau_bataille[a][b]='Ø';
          cout<<"le Robot a raté"<<endl;
          j.affiche1();
      }

    }

    else if(k1==1)
    {
        k2=2;

        if ((k2==2)&&(k1==1))
        {
            a2=a1;
            b2=b1;
            if (co!=0)
                co+=1;
            else
                co=1;
            if(co==4)
            {
                k1=0;
                co=0;
            }
            if(b1==10)
            {
                k2=4;
            }
            a2=a1;
            b2=a2;
            if ((j.plateau_bataille[a1][b1+1]=='~')&&(b1!=10))
            {
                cout<<"le Robot a raté"<<endl;
                plateau_info[a1][b1+1]='Ø';
                j.plateau_bataille[a1][b1+1]='Ø';
                j.affiche1();
                a1=a2;
                b1=b2;
                k2=4;
                if(x2==1)
                {
                  co=3;
                }
            }
            else if((j.plateau_bataille[a1][b1+1]=='Ø')&&(b1!=10))
            {
              a1=a2;
              b1=b2;
              k2=4;
              if(x2==1)
              {
                 co=3;
              }
            }
            else if((j.plateau_bataille[a1][b1+1]=='#')&&(b1!=10))
            {
                b1=b1+1;
                k2=2;
                co=co-1;
                plateau_info[a][b]='X';
                j.plateau_bataille[a][b]='X';
                cout<<"le robot a detruit une piece d'un bateau"<<endl;
                j.affiche1();
                j.nbc_rest-=1;
                x2=1;
            }

        }
        if ((k2==4)&&(k1==1))
        {
            a2=a1;
            b2=b1;
            if (co!=0)
                co+=1;
            else
                co=1;
            if(co==4)
            {
                k1=0;
                co=0;
            }
            if(b1==1)
            {
                k2=3;
            }
            a2=a1;
            b2=a2;
            if ((j.plateau_bataille[a1][b1-1]=='~')&&(b1!=1))
            {
                cout<<"le Robot a raté"<<endl;
                plateau_info[a1][b1-1]='Ø';
                j.plateau_bataille[a1][b1-1]='Ø';
                j.affiche1();
                a1=a2;
                b1=b2;
                k2=3;
            }
            else if((plateau_bataille[a1][b1-1]=='Ø')&&(b1!=1))
            {
              a1=a2;
              b1=b2;
              k2=3;
            }
            else if((j.plateau_bataille[a1][b1-1]=='#')&&(b1!=1))
            {
                a1=a1-1;
                co=co-1;
                k2=4;
                plateau_info[a1][b1]='X';
                j.plateau_bataille[a1][b1]='X';
                cout<<"le robot a detruit une piece d'un bateau"<<endl;
                j.affiche1();
                j.nbc_rest-=1;
            }

        }
        if ((k2==3)&&(k1==1))
        {
            a2=a1;
            b2=b1;
            if (co!=0)
                co+=1;
            else
                co=1;
            if(co==4)
            {
                k1=0;
                co=0;
            }
            if(a1==1)
            {
                k2=5;
            }
            a2=a1;
            b2=a2;
            if ((j.plateau_bataille[a1-1][b1]=='~')&&(a1!=1))
            {
                cout<<"le Robot a raté"<<endl;
                plateau_info[a1][b1+1]='Ø';
                j.plateau_bataille[a1-1][b1]='Ø';
                j.affiche1();
                a1=a2;
                b1=b2;
                k2=5;
                if(x3==1)
                {
                  co=3;
                }
            }
            else if((j.plateau_bataille[a1-1][b1]=='Ø')&&(a1!=1))
            {
              a1=a2;
              b1=b2;
              k2=5;
              if(x3==1)
              {
                 co=3;
              }
            }
            else if((j.plateau_bataille[a1-1][b1]=='#')&&(a1!=1))
            {
                a1=a1-1;
                co=co-1;
                k2=3;
                plateau_info[a1][b1]='X';
                j.plateau_bataille[a1][b1]='X';
                cout<<"le robot a detruit une piece d'un bateau"<<endl;
                j.affiche1();
                j.nbc_rest-=1;
                x3=1;
            }

        }
        if ((k2==5)&&(k1==1))
        {
            a2=a1;
            b2=b1;
            if (co!=0)
                co+=1;
            else
                co=1;
            if(co==4)
            {
                k1=0;
                co=0;
            }
            if(a1==10)
            {
                k2=2;
            }
            a2=a1;
            b2=a2;
            if ((j.plateau_bataille[a1+1][b1]=='~')&&(a1!=10))
            {
                cout<<"le Robot a raté"<<endl;
                plateau_info[a1+1][b1]='Ø';
                j.plateau_bataille[a1+1][b1]='Ø';
                j.affiche1();
                a1=a2;
                b1=b2;
                k2=2;
            }
            else if((j.plateau_bataille[a1+1][b1]=='Ø')&&(a1!=10))
            {
              a1=a2;
              b1=b2;
              k2=2;
            }
            else if((j.plateau_bataille[a1+1][b1]=='#')&&(a1!=10))
            {
                a1=a1-1;
                co=co-1;
                k2=5;
                plateau_info[a1][b1]='X';
                j.plateau_bataille[a1][b1]='X';
                cout<<"le robot a detruit une piece d'un bateau"<<endl;
                j.affiche1();
                j.nbc_rest-=1;
            }

        }

    }
}

};

int main()
{
    bateau Porte_Avions(5,"Porte_Avions"),croiseur(4,"croiseur"),contre_torpilleur1(3,"contre_torpilleur1"),contre_torpilleur2(3,"contre_torpilleur2"),torpilleur(2,"torpilleur");
bateau l1[5];
l1[0]=Porte_Avions;
l1[1]=croiseur;
l1[2]=contre_torpilleur1;
l1[3]=contre_torpilleur2;
l1[4]=torpilleur;
bateau CUIRASSE(4,"CUIRASSE"),CROISEUR1(3,"CROISEUR1"),CROISEUR2(3,"CROISEUR2"),TORPILLEUR1(2,"TORPILLEUR1"),TORPILLEUR2(2,"TORPILLEUR2"),TORPILLEUR3(2,"TORPILLEUR3"),SOUS_MARIN1(1,"SOUS_MARIN1"),SOUS_MARIN2(1,"SOUS_MARIN2"),SOUS_MARIN3(1,"SOUS_MARIN3"),SOUS_MARIN4(1,"SOUS_MARIN4");
bateau l2[10];
l2[0]=CUIRASSE;
l2[1]=CROISEUR1;
l2[2]=CROISEUR2;
l2[3]=TORPILLEUR1;
l2[4]=TORPILLEUR2;
l2[5]=TORPILLEUR3;
l2[6]=SOUS_MARIN1;
l2[7]=SOUS_MARIN2;
l2[8]=SOUS_MARIN3;
l2[9]=SOUS_MARIN4;
int p;
cout<<"1) 1 VS 1"<<endl<<"2)Contre un Robot"<<endl<<"Tapez 1 ou 2 :"<<endl;
cin>> p;
if (p==1)
{
    string ch1 , ch2;
    cout <<"donner le nom du premier joueur "<<endl;
    cin>> ch1;
    joueur j1(ch1);
    cout <<"donner le nom du deuxieme joueur "<<endl;
    cin>> ch2;
    joueur j2(ch2);
    cout << "choisir la disposition:" <<endl;
    cout<<"1-premier disposition:"<<endl;
    cout<<". 1 PORTE_AVIONS:5 cases"<<endl;
    cout<<". 1 CROISEUR:4 cases"<<endl;
    cout<<". 2 CONTRE_TORPILLEUR:3 cases"<<endl;
    cout<<". 1 TORPILLEUR:2 cases"<<endl;
    cout<<"2-deuxieme disposition en belgique:"<<endl;
    cout<<". 1 CUIRASSE:4 cases"<<endl;
    cout<<". 2 CROISEUR:3 cases"<<endl;
    cout<<". 3 TORPILLEUR:2 cases"<<endl;
    cout<<". 4 SOUS_MARIN:1 case"<<endl;
    cout<<" TAPEZ 1 OU 2 "<<endl;
    int k;
    cin>> k;
    j1.remplir(l1,l2,k);
    system("cls");
    j2.remplir(l1,l2,k);
    system("cls");
    do
    {
        j1.attack(j2);
        system("cls");
        j2.attack(j1);
        system("cls");
    }
    while ((j1.get_nbc_rest()!=0)&&(j2.get_nbc_rest()!=0));
    if (j1.get_nbc_rest()==0)
        cout<<j2.get_nick_name() <<" est la gagnant"<<endl;
    else if (j2.get_nbc_rest()==0)
        cout<<j1.get_nick_name() <<" est la gagnant"<<endl;
}
else if(p==2)
{
    string ch1 ;
    int k1, a1, b1 , a2, b2, co,k2 , x2,x3;
    k1=a2=b2=x2=x3=co=a1=b1=0;
    k2=2;
    cout <<"donner le nom du premier joueur "<<endl;
    cin>> ch1;
    joueur j1(ch1);
    joueur j2("Robot");
    cout << "choisir la disposition:" <<endl;
    cout<<"1-premier disposition:"<<endl;
    cout<<". 1 PORTE_AVIONS:5 cases"<<endl;
    cout<<". 1 CROISEUR:4 cases"<<endl;
    cout<<". 2 CONTRE_TORPILLEUR:3 cases"<<endl;
    cout<<". 1 TORPILLEUR:2 cases"<<endl;
    cout<<"2-deuxieme disposition en belgique:"<<endl;
    cout<<". 1 CUIRASSE:4 cases"<<endl;
    cout<<". 2 CROISEUR:3 cases"<<endl;
    cout<<". 3 TORPILLEUR:2 cases"<<endl;
    cout<<". 4 SOUS_MARIN:1 case"<<endl;
    cout<<" TAPEZ 1 OU 2 "<<endl;
    int k;
    cin>> k;
    j1.remplir(l1,l2,k);
    system("cls");
    j2.robot_remplir(l1,l2,k);
    system("cls");
    do
    {
        j1.attack(j2);
        system("cls");
        j2.robot_attack(j1,k1, a1, b1 , a2, b2, co,k2 , x2,x3);
    }
    while ((j1.get_nbc_rest()!=0)&&(j2.get_nbc_rest()!=0));
    if (j1.get_nbc_rest()==0)
        cout<<j2.get_nick_name() <<" est la gagnant"<<endl;
    else if (j2.get_nbc_rest()==0)
        cout<<j1.get_nick_name() <<" est la gagnant"<<endl;
}
    return 0;
}
