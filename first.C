/* po uruchomieniu roota w oknie dialogowym mozemy uruchomić makropoleceniem
 .x sciezka_domacro/nazwamakra

wyjscie z programu
.q
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void first()
{
    Int_t n=1000,i;
    Float_t x1[2000];
    ifstream d;
    d.open("C:\\Users\\piotr\\Documents\\dane.txt");
  // pod windows pelna sciezka z podwojnymi \\
  //   d.open("D:\\Users\\moje\\dane.txt");
    for(i=0;i<2000;i=i+1)
     {
       d>>x1[i];
     }
    d.close();
 // deklarowanie histogramu "jednowymiarowego"  .... liczba klas, przedział
   TH1F *hi1 = new TH1F("hi1","nazwa histogramu",10,0,1);
 // wypelnianie histogramu jednowymiarowego
    for(i=0;i<2000;i=i+1)
		{ 
			hi1->Fill(x1[i]);
		}

    /*
    // deklarowanie histogramu "dwuwymiarowego"  .... liczba klas, przedział najpierw po zmiennej x, potem po zmiennej y
   TH2F *imd2 = new TH2F("imd2","jestem histogramem-2wym ",40,-5.,400.,20,-5,400.);

       // wypelnianie histogramu dwuwymiarowego
    for(i=0;i<3000;i=i+2)
		{ 
		  hi2->Fill(x1[i],x1[i+1]);
		}
    */


    // stworzenie canvy do rysunku
    TCanvas *test = new TCanvas("test","test");
	test->SetFillColor(0);

	//kolory i style histogramu (mozna bez	
	hi1->SetFillColor(2);
	hi1->SetFillStyle(3002);
	// rysowanie histogramu
    hi1->Draw();
    
    //definicja funkcji do modelowania
     // f4 wlasna funkcja, w nawisach kwadratowych nieznane parametry, ktorych szuka program po uruchomieniu fit jesli modelowanie jedna funkcja to jak w przypadku f4
TF1 *f4 = new TF1("f4","[0]*exp(-x*[1])",0,1);
  hi1->Fit(f4);
 /* 
     //f1,f2,f3 jesli modelowanie kawalkami ( ostatnie liczby to zakresy )   
TF1* f1 = new TF1("f1","expo",0,19);
hi1->Fit(f1,"R+");
TF1* f2 = new TF1("f2","expo",19,43.5);
hi1->Fit(f2,"R+");
TF1* f3 = new TF1("f3","pol9",43.5,400);
hi1->Fit(f3,"R+");
 */
}

