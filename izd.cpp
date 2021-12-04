#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <map>

void izd()
{

    auto c1 = new TCanvas("c1", "losowanie_zmiennej_dyskretnej", 10, 10, 1000, 600);
    c1->Divide(3, 1);

    std::ifstream d;
    std::ifstream d2;
    auto histogram1 = new TH1I("histogram1", "Odwrocona dystrybuanta;Count [i];Number [j]", 6, 0.5, 6.5);

    d.open("C:\\Users\\piotr\\Documents\\LCG\\losowanie_zmiennej_dyskretnej\\output.txt");

    while (!d.eof())
    {
        int energy;

        d >> energy;
        histogram1->Fill(energy);
    }
    d.close();

    histogram1->SetFillColor(38);

    histogram1->SetStats(0);

    auto histogram2 = new TH1I("histogram2", "Metoda eliminacji;Count [i];Number [j]", 6, 0.5, 6.5);

    d2.open("C:\\Users\\piotr\\Documents\\LCG\\losowanie_zmiennej_dyskretnej\\output2.txt");

    while (!d2.eof())
    {
        int energy;

        d2 >> energy;
        histogram2->Fill(energy);
    }
    d2.close();

    histogram2->SetFillColor(38);

    histogram2->SetStats(0);

    auto histogram3 = new TH1I("histogram3", "discrete_distribution ;Count [i];Number [j]", 6, 0.5, 6.5);

    d2.open("C:\\Users\\piotr\\Documents\\LCG\\losowanie_zmiennej_dyskretnej\\output3.txt");

    while (!d2.eof())
    {
        int energy;

        d2 >> energy;
        histogram3->Fill(energy);
    }
    d2.close();

    histogram3->SetFillColor(38);

    histogram3->SetStats(0);

    c1->cd(1);
    histogram1->Draw();
    c1->cd(2);
    histogram2->Draw();
    c1->cd(3);
    histogram3->Draw();
    c1->BuildLegend();
    c1->Draw();
}