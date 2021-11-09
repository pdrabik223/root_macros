#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
void DrawSigleGrapgh(std::string path);

void w_cycle()
{
    auto c1 = new TCanvas("c1", "All Generators", 10, 10, 4 * 200, 5 * 200);

    c1->Divide(4, 5);
    for (int i = 0; i < 20; i++)
    {
        c1->cd(i + 1);
        std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\cycle\\rule_" + std::to_string(i * 13 + 3) + ".txt";

        // std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\cycle\\rule_120.txt";

        DrawSigleGrapgh(path);
    }
    c1->Draw();
}

void DrawSigleGrapgh(std::string path)
{
    std::ifstream file;
    file.open(path);

    int rule;
    unsigned bin_count;

    file >> rule;
    file >> bin_count;

    auto graph = new TH1F(std::to_string(rule).c_str(), std::to_string(rule).c_str(), 300, 0, 1);
    graph->SetFillColor(38);
    graph->SetStats(0);

    for (int i = 0; i < bin_count; i++)
    {

        double value;
        file >> value;
        graph->Fill(value);
    }

    file.close();

    graph->Draw();
}