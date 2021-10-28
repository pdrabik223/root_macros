
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

void DrawSumgraph(const std::vector<std::pair<std::string, long long int>> &data_debug, const std::vector<std::pair<std::string, long long int>> &data_release);
void DrawSigleGrapgh(const std::string &path, const std::string &name);
void root_timings_loader()
{

  auto c1 = new TCanvas("c1", "timings_canvas", 10, 10, 900, 500);

  c1->Divide(2, 1);
  c1->cd(1);
  DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\CoA\\testing\\timings_release.txt", "Release");

  c1->cd(2);
  DrawSigleGrapgh("C:\\Users\\piotr\\Documents\\CoA\\testing\\timings_debug.txt", "Debug");

  c1->Draw();
  c1->BuildLegend();
}

void DrawSumgraph(const std::vector<std::pair<std::string, long long int>> &data_debug, const std::vector<std::pair<std::string, long long int>> &data_release)
{

  auto graph = new TH1I("hi1", "Timings Sum", 2, 0, 2);
  graph->SetFillColor(2);
  long long int sum_debug = 0;

  for (int i = 0; i < data_debug.size(); i++)
  {
    sum_debug += data_debug[i].second;
  }

  long long int sum_release = 0;

  for (int i = 0; i < data_release.size(); i++)
  {
    sum_release += data_release[i].second;
  }
  graph->AddBinContent(1, sum_debug);
  graph->AddBinContent(2, sum_release);
  graph->SetStats(0);
  graph->GetXaxis()->SetBinLabel(1, "sum debug");
  graph->GetXaxis()->SetBinLabel(2, "sum release");

  graph->Draw();
}

void DrawSigleGrapgh(const std::string &path, const std::string &name)
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

  auto graph = new TH1I("Single_Debug", name.c_str(), data.size(), 0, data.size());
  // graph->GetYaxis()->SeTLabel("Function");
  // graph->GetXaxis()->SeTLabel("Time spended inside [ns]");

  graph->SetFillColor(38);

  for (int i = 0; i < data.size(); i++)
  {
    graph->AddBinContent(i + 1, data[i].second);
  }
  graph->SetStats(0);

  for (int i = 0; i < data.size(); i++)
  {
    graph->GetXaxis()->SetBinLabel(i + 1, data[i].first.c_str());
  }

  graph->Draw();
}