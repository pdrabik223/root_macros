
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
int csv_log()
{

    Int_t n = 1000, i;
    std::vector<Float_t> first;
    std::vector<Float_t> first_x;
    ifstream d;
    d.open("C:\\Users\\piotr\\AppData\\Local\\AMD\\CN\\20211015-003120.CSV");

    int data_sets = 19;
    std::string labels[8];
    labels[0] = "GPU UTIL";
    labels[1] = "GPU SCLK";
    labels[2] = "GPU MCLK";
    labels[3] = "GPU TEMP";
    labels[4] = "GPU PWR";
    labels[5] = "GPU VRAM UTIL";
    labels[6] = "CPU UTIL";
    labels[7] = "RAM UTIL";

    Float_t x;
    for (i = 6; i < data_sets; i++)
    {
        d >> x;
        first.push_back(x);
        first_x.push_back(i);
        std::cout << x << "\n";
        for (int j = 0; j < 7; j++)
            d >> x;
    }
    d.close();

    TGraph *hi1 = new TGraph(first_x.size(), first_x.data(), first.data());

    TCanvas *test = new TCanvas(labels[0].c_str(), labels[0].c_str(), 200, 10, 600, 400);
    // test->SetFillColor(0);

    // hi1->SetFillColor(2);
    // hi1->SetFillStyle(3002);

    hi1->Draw("AC*");
    return 1;
}