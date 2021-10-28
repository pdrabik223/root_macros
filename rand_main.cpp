
void DrawSigleGrapgh(const std::string &path, const std::string &name);
void rand_main()
{

    auto c1 = new TCanvas("c1", "los", 10, 10, 900, 500);

    c1->Divide(1, 2);
    c1->cd(1);
    DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\LCG\\rand\\output.txt", "los");

    c1->cd(2);
    DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\LCG\\rand\\output2.txt", "los2");

    c1->Draw();
}

void DrawSigleGrapgh(const std::string &path, const std::string &name)
{

    std::ifstream r;
    r.open(path);
    std::vector<double> data;
    while (!r.eof())
    {
        double x;
        // r >> name;
        r >> x;
        data.push_back(x);
        // std::cout << name << " " << x << "\n";
    }
    r.close();

    auto graph = new TH1F("Single_Debug", name.c_str(), 25, 0, 25);
    // graph->GetYaxis()->SeTLabel("Function");
    // graph->GetXaxis()->SeTLabel("Time spended inside [ns]");

    graph->SetFillColor(38);

    for (int i = 0; i < data.size(); i++)
    {
        graph->Fill(data[i]);
    }
    graph->SetStats(0);

    // for (int i = 0; i < data.size(); i++)
    // {
    //     graph->GetXaxis()->SetBinLabel(i + 1, data[i].first.c_str());
    // }

    graph->Draw("lego1");
}