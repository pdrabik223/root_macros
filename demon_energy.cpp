#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
void demon_energy()
{

    auto c1 = new TCanvas("c1", "Demon", 10, 10, 1000, 600);

    auto deamon_graph = new TGraph();
    deamon_graph->SetName("Demon's Energy");
    deamon_graph->SetTitle("Demon;Iterations [i];Energy count [j]");
    deamon_graph->SetMarkerStyle(1);
    deamon_graph->SetMarkerSize(1);
    deamon_graph->SetMarkerColor(4);
    deamon_graph->SetDrawOption("LP");
    deamon_graph->SetLineColor(4);
    deamon_graph->SetLineWidth(0);
    deamon_graph->SetFillStyle(0);

    std::ifstream d;
    d.open("C:\\Users\\piotr\\Documents\\lemon-demon\\demon.txt");

    for (int i = 0; i < 100'000; i++)
    {
        int energy;
        d >> energy;
        deamon_graph->SetPoint(i, i, energy);
    }
    d.close();

    deamon_graph->Draw();
    c1->BuildLegend();
    c1->Draw();
}