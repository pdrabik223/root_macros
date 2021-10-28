
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

void I_got_dared()
{
    std::string path = "C:\\Users\\piotr\\Documents\\Wolfram_Automata\\picture.txt";
    std::ifstream f(path, std::ios::in);

    if (f.bad())
    {
        f.close();
        throw "bad file path";
    }

    int frame_width;
    int frame_height;

    f >> frame_width;
    f >> frame_height;

    auto histo = new TH2F("h2",
                          "test",
                          frame_width, 0, frame_width, frame_height, 0, frame_height);

    histo->SetStats(0);

    histo->SetContour(100);
    gStyle->SetPalette(kDeepSea);

    for (auto x = 0; x < frame_width; x++)
        for (auto y = 0; y < frame_height; y++)
        {
            bool state;
            f >> state;
            if (state)
                histo->Fill(y, x, 0.8);
            else
                histo->Fill(y, x, 0.2);
        }

    f.close();

    auto c = new TCanvas("canvas", "View Wolfram Automata", 200, 10, 720, 720);

    // TColor::InvertPalette();
    histo->Draw("colz text");
}