
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

int root_data_loader()
{

  std::string filename = "test.txt";

  auto mg = new TMultiGraph("Random maze test", "Random maze test");

  mg->SetTitle("Circular Maze;Size of plane; time [ #mus ]");

  auto dijkstra_gr = new TGraph();
  dijkstra_gr->SetName("Dijkstra");
  dijkstra_gr->SetTitle("Dijkstra");
  dijkstra_gr->SetMarkerStyle(22);
  dijkstra_gr->SetDrawOption("LP");
  dijkstra_gr->SetLineColor(4);
  dijkstra_gr->SetLineWidth(4);
  dijkstra_gr->SetFillStyle(0);

  auto a_star_gr = new TGraph();
  a_star_gr->SetName("A*");
  a_star_gr->SetTitle("A*");
  a_star_gr->SetMarkerStyle(22);
  a_star_gr->SetDrawOption("LP");
  a_star_gr->SetLineColor(5);
  a_star_gr->SetLineWidth(4);
  a_star_gr->SetFillStyle(0);

  auto random_gr = new TGraph();
  random_gr->SetName("RHR");
  random_gr->SetTitle("RHR");
  random_gr->SetMarkerStyle(22);
  random_gr->SetDrawOption("LP");
  random_gr->SetLineColor(3);
  random_gr->SetLineWidth(4);
  random_gr->SetFillStyle(0);

  std::ifstream d;
  d.open("C:\\Users\\piotr\\Documents\\CoA\\testing\\path_lengths.txt");

  int i = 0;
  while (!d.eof())
  {
    int x;
    double t1, t2, t3;
    d >> x;
    d >> t1;
    d >> t2;
    d >> t3;
    dijkstra_gr->SetPoint(i, (double)x, t1);
    a_star_gr->SetPoint(i, (double)x, t2);
    random_gr->SetPoint(i, (double)x, t3);
    i++;
  }
  d.close();

  mg->Add(dijkstra_gr, "PL");
  mg->Add(a_star_gr, "PL");
  mg->Add(random_gr, "PL");

  auto c = new TCanvas("c", "c", 200, 10, 600, 400);
  mg->Draw("A pmc plc");
  c->BuildLegend();

  auto histo = new TH1I("histo", "test 1", 10, 600, 400);
  c->Print("C:\\Users\\piotr\\Documents\\CoA\\testing\\plots.pdf", "Title:test");

  auto out_file = new TFile("C:\\Users\\piotr\\Documents\\CoA\\testing\\my_rootfile.root", "RECREATE");

  // Write the histogram in the file
  c->Write();

  // Close the file
  out_file->Close();

  return 1;
}

void LoadMultiGraph()
{
}