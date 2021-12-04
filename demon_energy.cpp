#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <map>

void demon_energy()
{

    auto c1 = new TCanvas("c1", "Demon", 10, 10, 1000, 600);
    c1->Divide(2, 2);

    auto demon_graph = new TGraph();
    demon_graph->SetName("Demon's Energy");
    demon_graph->SetTitle("Demon;Iterations [i];Energy count [j]");
    demon_graph->SetMarkerStyle(1);
    demon_graph->SetMarkerSize(1);
    demon_graph->SetMarkerColor(4);
    demon_graph->SetDrawOption("LP");
    demon_graph->SetLineColor(4);
    demon_graph->SetLineWidth(2);
    demon_graph->SetFillStyle(0);

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

    std::vector<int> demon_data;

    std::vector<int> magnetism_data;
    int i = 0;
    while (!d.eof())
    {
        int energy;

        d >> energy;
        printf("demon: %d\t", energy);
        demon_graph->SetPoint(i, i, energy);

        demon_data.push_back(energy);

        d >> energy;
        printf("magnetism: %d\n", energy);
        magnetism_graph->SetPoint(i, i, energy);
        magnetism_data.push_back(energy);
        i++;
    }
    d.close();

    int max = 0, min = 1000000000;
    for (auto &d : demon_data)
    {
        if (d > max)
            max = d;
        else if (d < min)
            min = d;
    }
    auto demon_histogram = new TH1I("Single_Debug", "Demon;Energy level [i];Energy level level total occurrences [j]", 100, min, max);

    for (auto &d : demon_data)
    {

        demon_histogram->Fill(d);
    }
    max = 0, min = 1000000000;
    for (auto &d : magnetism_data)
    {
        if (d > max)
            max = d;
        else if (d < min)
            min = d;
    }

    auto magnetism_histogram = new TH1I("Single_Debug", "Magnetism;Magnetism level [i];Magnetism level total occurrences [j]", 100, min, max);

    for (auto &d : magnetism_data)
    {

        magnetism_histogram->Fill(d);
    }

    magnetism_histogram->SetFillColor(38);
    demon_histogram->SetFillColor(38);

    magnetism_histogram->SetStats(0);
    demon_histogram->SetStats(0);

    c1->cd(1);
    demon_graph->Draw();
    c1->cd(2);
    magnetism_graph->Draw();
    c1->cd(3);
    demon_histogram->Draw("B");
    c1->cd(4);
    magnetism_histogram->Draw("B");

    c1->BuildLegend();
    c1->Draw();
}