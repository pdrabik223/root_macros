#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
void DrawSingleGraph(std::string path);

void dist()
{
    auto c1 = new TCanvas("c1", "All Generators", 10, 10, 600, 500);

    // // c1->Divide(4, 5);
    // for (int i = 0; i < 20; i++)
    // {
    // c1->cd(i + 1);
    // std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\dist\\rule_" + std::to_string(i * 13 + 3) + ".txt";

    std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\cycle\\rule_120.txt";

    DrawSingleGraph(path);
    // }
    c1->Draw();
}

void DrawSingleGraph(std::string path)
{
    std::ifstream file;
    file.open(path);

    int rule;
    unsigned bin_count;
    std::vector<int> data;

    data.reserve(bin_count);

    file >> rule;
    file >> bin_count;

    auto graph = new TH1I(std::to_string(rule).c_str(), std::to_string(rule).c_str(), 100, -51, 51);
    graph->SetFillColor(38);
    graph->SetStats(0);

    graph->GetXaxis()->SetTitle("Koncowa wartosc");
    graph->GetYaxis()->SetTitle("Ilosc symulacji zakonczonych dana wartoscia");

    for (int i = 0; i < bin_count; i++)
    {
        int value;
        file >> value;
        graph->Fill(value);
    }

    file.close();

    graph->Draw();
}