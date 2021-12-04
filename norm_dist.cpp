
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

int norm_dist()
{
    auto c1 = new TCanvas("c1", "norm distr", 10, 10, 720, 720);
    c1->Divide(3, 1);
    c1->cd(1);
    std::ifstream iv;
    iv.open("C:\\Users\\piotr\\Documents\\LCG\\norm_dist\\method_vi.txt");
    int iv_size;
    iv >> iv_size;
    auto graph_iv = new TH1F("current", "method IV;x; probability of f(x)", 300, -3, 3);
    graph_iv->SetFillColor(38);

    for (int i = 0; i < iv_size; i++)
    {
        float buffor;
        iv >> buffor;
        graph_iv->Fill(buffor);
    }

    graph_iv->Draw();
    c1->cd(2);

    std::ifstream ii;
    ii.open("C:\\Users\\piotr\\Documents\\LCG\\norm_dist\\method_ii.txt");
    int ii_size;
    ii >> ii_size;
    auto graph_ii = new TH1F("current", "method II;x; probability of f(x)", 300, -3, 3);
    graph_ii->SetFillColor(38);

    for (int i = 0; i < ii_size; i++)
    {
        float buffor;
        ii >> buffor;
        graph_ii->Fill(buffor);
    }

    graph_ii->Draw();

    c1->cd(3);

    std::ifstream iii;
    iii.open("C:\\Users\\piotr\\Documents\\LCG\\norm_dist\\method_iii.txt");
    int iii_size;
    iii >> iii_size;
    auto graph_iii = new TH1F("current", "method III;x; probability of f(x)", 300, -3, 3);
    graph_iii->SetFillColor(38);

    for (int i = 0; i < iii_size; i++)
    {
        float buffor;
        iii >> buffor;
        graph_iii->Fill(buffor);
    }

    graph_iii->Draw();

    c1->Draw();
    return 0;
}