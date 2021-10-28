

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

/// populates output with sub-directories for directory
/// only increment files will be recognized
/// the file name must be structured in following fasion: increment_v{x}
/// first iteration, first file must be named increment_v0
/// instead of {x}, number of iteration must be present :) gl hf bajjjjj
void ReadDirectory(const std::string &directory,
                   std::vector<std::string> &output)
{

    for (int i = 0; i < 100; ++i)
    {

        std::string full_path = directory + "i_v" + std::to_string(i) + ".txt";

        std::ifstream f;
        f.open(full_path);

        if (!f.good())
        {
            std::cout << "not existing file path: " << full_path << std::endl;
            f.close();
            return;
        }
        else
            output.push_back(full_path);

        f.close();
    }
}

std::vector<std::pair<std::string, long long int>> DrawSigleGrapgh(const std::string &path, const std::string &name, const std::vector<std::pair<std::string, long long int>> &prevoius);

void root_incrementer()
{

    std::vector<std::string> output;

    ReadDirectory("C:\\Users\\piotr\\Documents\\CoA\\testing\\", output);

    std::cout << "info:\n";
    for (auto o : output)
        std::cout << o << std::endl;

    auto c1 = new TCanvas("c1", "timings_canvas", 10, 10, 900, 1000);

    std::vector<std::pair<std::string, long long int>> previous = {};

    c1->Divide(1, output.size());
    int i = 1;
    for (auto &o : output)
    {
        c1->cd(i++);
        previous = DrawSigleGrapgh(o, "graph" + std::to_string(i - 1), previous);
    }
    c1->Draw();
    c1->BuildLegend();
}

std::vector<std::pair<std::string, long long int>> DrawSigleGrapgh(const std::string &path, const std::string &name, const std::vector<std::pair<std::string, long long int>> &prevoius)
{

    std::ifstream r;
    r.open(path);
    std::vector<std::pair<std::string, long long int>> data;
    while (!r.eof())
    {
        std::string name;
        long long int x;
        r >> name;
        r >> x;
        data.push_back({name, x});
        // std::cout << name << " " << x << "\n";
    }

    r.close();
    auto mg = new THStack("hs", "");
    auto graph = new TH1I("current", name.c_str(), data.size(), 0, data.size());

    graph->SetFillColor(38);

    for (int i = 0; i < data.size(); i++)
    {
        graph->AddBinContent(i + 1, data[i].second);
    }

    for (int i = 0; i < data.size(); i++)
    {
        graph->GetXaxis()->SetBinLabel(i + 1, data[i].first.c_str());
    }

    if (!prevoius.empty() && prevoius.size() == data.size())
    {
        auto prevoius_graph = new TH1I("prevoius", name.c_str(), prevoius.size(), 0, prevoius.size());

        prevoius_graph->SetFillColor(3);

        for (int i = 0; i < prevoius.size(); i++)
        {
            prevoius_graph->AddBinContent(i + 1, prevoius[i].second);
        }

        for (int i = 0; i < prevoius.size(); i++)
        {
            prevoius_graph->GetXaxis()->SetBinLabel(i + 1, data[i].first.c_str());
        }

        // auto prevoius_graph = new TH1I("prevoius", name.c_str(), prevoius.size(), 0, prevoius.size());
        // prevoius_graph->SetFillColor(3);
        // for (int i = 0; i < prevoius.size(); i++)
        // {
        //     prevoius_graph->AddBinContent(i + 1, prevoius[i].second);
        // }

        // for (int i = 0; i < prevoius.size(); i++)
        // {
        //     prevoius_graph->GetXaxis()->SetBinLabel(i + 1, data[i].first.c_str());
        // }

        mg->Add(prevoius_graph);
        // graph->GetColor()->SetAlpha(0.01);
        mg->Add(graph);

        auto t = new TPaveText(.05, .3, .95, .6);
        t->AddText("This line is blue");
        t->AddText("This line is red");
        t->Draw();
    }
    else
        mg->Add(graph);

    mg->Draw("lego1");

    return data;
}
