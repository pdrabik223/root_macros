
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
void DrawSigleGrapgh(const std::string &path, const std::string &name);
void bernulli()
{
    auto c1 = new TCanvas("c1", "timings_canvas", 10, 10, 900, 500);

    c1->Divide(2, 1);
    c1->cd(1);
    DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\LCG\\Bernulli\\output.txt", "Bernulli, Bernulli generator");

    c1->cd(2);
    DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\LCG\\Bernulli\\output2.txt", "Bernulli, Rand generator");

    // c1->BuildLegend();
    c1->Draw();

    auto imgdump = new TImageDump(std::string("C:\\Users\\piotr\\Documents\\LCG\\Bernulli\\Bernulli.png").c_str());
    c1->Paint();

    imgdump->Close();
}

void DrawSigleGrapgh(const std::string &path, const std::string &name)
{

    std::ifstream r;
    r.open(path);
    std::vector<int> data;
    while (!r.eof())
    {
        int x;
        r >> x;
        data.push_back(x);
        // std::cout << name << " " << x << "\n";
    }
    r.close();

    auto graph = new TH1I("Single_Debug", name.c_str(), 20, 0, 10);
    // graph->GetYaxis()->SeTLabel("Function");
    // graph->GetXaxis()->SeTLabel("Time spended inside [ns]");

    graph->SetFillColor(38);

    for (int i = 0; i < data.size(); i++)
    {
        graph->Fill(data[i]);
    }
    graph->SetStats(0);

    graph->Draw();
}