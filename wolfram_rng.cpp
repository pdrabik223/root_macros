
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
void DrawSigleGrapgh(std::string path);
void wolfram_rng()
{

    auto c1 = new TCanvas("c1", "Distribiution across somethjsad ", 10, 10, 4 * 200, 5 * 200);

    c1->Divide(4, 5);

    for (int i = 0; i < 20; i++)
    {
        c1->cd(i + 1);
        std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\cycle\\rule_" + std::to_string(i * 13 + 3) + ".txt";

        // std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\rule_159.txt";

        DrawSigleGrapgh(path);
    }
    c1->Draw();
    // c1->BuildLegend();
}

void DrawSigleGrapgh(std::string path)
{

    std::ifstream file;
    file.open(path);

    int rule;
    unsigned rule_perioid;
    std::vector<uint64_t> data;
    std::vector<double> normalized_data;

    file >> rule;
    file >> rule_perioid;
    data.reserve(rule_perioid);
    for (int i = 0; i < rule_perioid; i++)
    {
        uint64_t value;
        file >> value;
        normalized_data.push_back((double)value / (UINT64_MAX >> 1));
    }
    file.close();

    auto graph = new TH1I(std::to_string(rule).c_str(), std::to_string(rule).c_str(), 100, 0, 1);
    graph->SetFillColor(38);

    graph->SetStats(0);
    for (const auto n : normalized_data)
    {
        graph->Fill(n);
    }
    graph->Draw();
}