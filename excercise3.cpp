#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

void DrawSigleGrapgh(const std::string &path, const std::string &name);

int excercise3()
{

    auto c1 = new TCanvas("c1", "timings_canvas", 10, 10, 900, 500);
    c1->Divide(2, 1);
    c1->cd(1);
    DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\LCG\\exercise_3\\output.txt", "1/dystrybuanta");
    c1->cd(2);
    DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\LCG\\exercise_3\\output2.txt", "Eliminacji");

    c1->Draw();
    c1->BuildLegend();
    return 0;
}

void DrawSigleGrapgh(const std::string &path, const std::string &name)
{

    std::ifstream r;
    r.open(path);
    std::vector<double> data;

    auto graph = new TH1F(name.c_str(), name.c_str(), 100, 0, 2);

    while (!r.eof())
    {
        double x;
        r >> x;
        graph->Fill(x);
    }

    r.close();

    graph->SetFillColor(38);

    graph->SetStats(0);

    graph->Draw("lego1");
}