
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
// #include <../../include/TH1.h>
// #include <../../include/TCanvas.h>
#include <map>
void DrawSingleGraph(std::string path);

auto c1 = new TCanvas("c1", "Distribiution across somethjsad ", 10, 10, 720, 720);
void wolfram_rng()
{

    for (int i = 3; i < 255; i += 1)
    {
        std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\Benchmarks\\wand\\rule_" + std::to_string(i) + ".txt";

        // std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\WNG\\rule_159.txt";

        std::cout << "====RULE " << i << "====\n";
        DrawSingleGraph(path);

        c1->Draw();

        auto imgdump = new TImageDump(std::string("C:\\Users\\piotr\\Documents\\Praca\\rule_" + std::to_string(i) + "_graph.png").c_str());
        c1->Paint();

        // c1->BuildLegend();
        imgdump->Close();

        //     char war;
        //     std::cin >> war;
    }
}

void DrawSingleGraph(std::string path)
{

    std::ifstream file;
    file.open(path);

    int rule;
    std::vector<double> data;
    std::map<double, int> data2;
    file >> rule;

    double max = -1, min = 2;
    for (int i = 0; i < 100'000; i++)
    {
        double value;
        file >> value;

        if (data2.find(value) == data2.end())
        {
            data2.emplace(value, 1);
        }
        else
            data2[value]++;

        if (value > max)
            max = value;
        if (value < min)
            min = value;

        data.push_back(value);
    }
    // std::cout << "size: " << data2.size();
    unsigned bin_count = 101;

    // double avg = 0;

    // for (auto i : data2)
    // {
    //     avg += i.second;

    //     /* code */
    // }
    // avg = avg / (double)data2.size();
    // double shift = 0.5 - avg;

    // for (auto &i : data2)
    // {
    //     i += shift;

    //     /* code */
    // }

    auto graph = new TH1F(std::to_string(rule).c_str(), std::to_string(rule).c_str(), bin_count, min - 0.1, max + 0.1);
    graph->SetFillColor(38);
    graph->SetStats(0);
    graph->GetXaxis()->SetTitle("Randomly generated value");
    graph->GetYaxis()->SetTitle("Total number of occurrences");
    file.close();

    for (auto i : data)
        graph->Fill(i);

    auto f1 = new TF1("f1", "gaus");

    // f1->SetParameters(1, 1, 1);
    graph->Fit(f1);

    auto fit = graph->GetFunction("f1");

    std::cout << "hi^2: " << fit->GetChisquare() << "\n";

    std::map<double, int> bins;
    double bin_delta = (double)(max - min) / (double)bin_count;
    for (int i = 1; i < bin_count; i++)
    {
        bins.emplace(i * bin_delta, 0);
    }

    // for (auto &i : data2)
    // {
    //     for (int j = 1; j < bins.size(); j++)
    //         if (i.first > bins[j - 1] && i.first < bins[j])
    //         bins[j] = i.second;
    // }

    // double my_hi2 = 0;
    // for ()
    //     double n1

    auto legend = new TLegend(0.1, 0.7, 0.4, 0.5);
    legend->SetHeader("Test hi^2", "C"); // option "C" allows to center the header
    legend->AddEntry("gr", std::string("hi^2: " + std::to_string(fit->GetChisquare())).c_str());
    legend->AddEntry("gr", std::string("no bins " + std::to_string(bin_count)).c_str());
    legend->AddEntry("gr", std::string("no unique values " + std::to_string(data2.size())).c_str());

    graph->Draw();
    legend->Draw();
}
