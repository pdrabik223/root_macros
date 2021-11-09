#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
void DrawSigleGrapgh(std::string path);
void cum_mistake()
{

    auto c1 = new TCanvas("c1", "All Generators", 10, 10, 600, 600);

    std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\mistakes.txt";

    DrawSigleGrapgh(path);

    c1->Draw();
    c1->BuildLegend();
}

void DrawSigleGrapgh(std::string path)
{

    std::ifstream file;
    file.open(path);

    int rule;
    double cum_mistake;

    auto graph = new TH1I("sum mistakes", "sum mistakes", 20, 0, 20);
    graph->SetFillColor(38);
    graph->SetStats(0);

    for (int i = 0; i < 20; i++)
    {
        file >> rule;
        file >> cum_mistake;
        graph->AddBinContent(i + 1, cum_mistake);
        graph->GetXaxis()->SetBinLabel(i + 1, std::to_string(rule).c_str());
    }
    file.close();

    graph->Draw();
}