#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
void demon_energy()
{

    auto c1 = new TCanvas("c1", "Demon", 10, 10, 1000, 600);
    c1->Divide(2, 1);

    auto deamon_graph = new TGraph();
    deamon_graph->SetName("Demon's Energy");
    deamon_graph->SetTitle("Demon;Iterations [i];Energy count [j]");
    deamon_graph->SetMarkerStyle(1);
    deamon_graph->SetMarkerSize(1);
    deamon_graph->SetMarkerColor(4);
    deamon_graph->SetDrawOption("LP");
    deamon_graph->SetLineColor(4);
    deamon_graph->SetLineWidth(2);
    deamon_graph->SetFillStyle(0);

    auto magnetism_graph = new TGraph();
    magnetism_graph->SetName("Magnetism");
    magnetism_graph->SetTitle("Magnetism;Iterations [i];Magnetism count [j]");
    magnetism_graph->SetMarkerStyle(1);
    magnetism_graph->SetMarkerSize(1);
    magnetism_graph->SetMarkerColor(6);
    magnetism_graph->SetDrawOption("LP");
    magnetism_graph->SetLineColor(4);
    magnetism_graph->SetLineWidth(2);
    magnetism_graph->SetFillStyle(0);

    std::ifstream d;
    d.open("C:\\Users\\piotr\\Documents\\lemon-demon\\demon.txt");

    int i = 0;
    while (!d.eof())
    {
        int energy;

        d >> energy;
        printf("demon: %d\t", energy);
        deamon_graph->SetPoint(i, i, energy);
        d >> energy;
        printf("magnetism: %d\n", energy);
        magnetism_graph->SetPoint(i, i, energy);
        i++;
    }
    d.close();
    c1->cd(1);
    deamon_graph->Draw();
    c1->cd(2);
    magnetism_graph->Draw();
    c1->BuildLegend();
    c1->Draw();
}