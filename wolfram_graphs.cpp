#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

void DrawGraph(const std::string &data_path);

int wolfram_graphs()
{
    std::ifstream f("C:\\Users\\piotr\\Documents\\Wolfram_Automata\\data1.txt", std::ios::in);

    int rows;
    f >> rows;

    int columns;
    f >> columns;

    std::vector<std::vector<int>> frame;
    std::vector<int> average;
    // frame.reserve(rows);
    for (int i = 0; i < rows; i++)
    {
        std::vector<int> slice;

        int average_sum = 0;
        for (int j = 0; j < columns; j++)
        {
            int value;
            f >> value;
            if (value == 1)
                average_sum++;
            slice.push_back(value);
            average.push_back(average_sum);
        }
        frame.push_back(slice);
    }

    auto graph = new TGraph(rows);
    graph->SetName("average");
    graph->SetTitle("average");
    graph->SetMarkerStyle(21);
    graph->SetDrawOption("LP");
    graph->SetLineColor(4);
    graph->SetLineWidth(4);
    graph->SetFillStyle(0);

    for (int i = 0; i < average.size(); i++)
    {
        graph->SetPoint(i, average[i], i);
    }

    auto c = new TCanvas("average", "average", rows, columns, 1080, 720);
    graph->Draw();
    c->BuildLegend();
    // DrawGraph("C:\\Users\\piotr\\Documents\\Wolfram_Automata\\data1.txt");
    return 0;
}

// void DrawGraph(const std::string &data_path)
// {
//     std::ifstream f(data_path, std::ios::in);

//     int rows;
//     f >> rows;

//     int columns;
//     f >> columns;

//     std::vector<std::vector<int>> frame;
//     std::vector<int> average;
//     frame.reserve(rows);
//     for (size_t i = 0; i < rows; i++)
//     {
//         std::vector<int> slice;

//         int average_sum = 0;
//         for (size_t j = 0; j < columns; j++)
//         {
//             int value;
//             f >> value;
//             if (value == 1)
//                 average_sum++;
//             slice.push_back(value);
//             average.push_back(average_sum);
//         }
//         frame.push_back(slice);
//     }

//     auto graph = new TGraph(rows);
//     graph->SetName("average");
//     graph->SetTitle("average");
//     graph->SetMarkerStyle(22);
//     graph->SetDrawOption("LP");
//     graph->SetLineColor(4);
//     graph->SetLineWidth(4);
//     graph->SetFillStyle(0);

//     for (int i = 0; i < average.size(); i++)
//     {
//         graph->SetPoint(i, average[i], i);
//     }

//     auto c = new TCanvas("average", "average", rows, columns, 1080, 720);
//     graph->Draw();
//     c->BuildLegend();
// }
