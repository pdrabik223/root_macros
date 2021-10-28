
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

#define DIRECTORY_PATH "C:\\Users\\piotr\\Documents\\CoA\\testing\\pr_directory\\"

struct PRFileFormat
{
    PRFileFormat() = delete;
    PRFileFormat(std::string file_path) { Load(std::move(file_path)); };

    PRFileFormat(const PRFileFormat &other) = delete;
    PRFileFormat &operator=(const PRFileFormat &other) = delete;
    void Load(std::string path);

    static int file_id;
    static std::string directory_path;
    std::vector<int> arguments;
    std::vector<std::vector<double>> values;
    std::vector<std::string> datasets_labels;
    std::string x_axis_name;
    std::string y_axis_name;
    std::string graph_label;
};
std::string PRFileFormat::directory_path = DIRECTORY_PATH;
/// populates output with sub-directories for directory
/// only increment files will be recognized
/// the file name must be structured in following fasion: increment_v{x}
/// first iteration, first file must be named increment_v0
/// instead of {x}, number of iteration must be present :) gl hf bajjjjj
void ReadDirectory(const std::string &directory,
                   std::vector<std::string> &output);

void DrawGraph(const PRFileFormat &data);

void pr_loader()
{
    // auto out_file = new TFile(std::string("C:\\Users\\piotr\\Documents\\CoA\\testing\\pr_directory\\resoults.root").c_str(), "RECREATE");

    std::vector<std::string> output;

    ReadDirectory(DIRECTORY_PATH, output);

    for (auto o : output)
        DrawGraph(PRFileFormat(o));
}

void ReadDirectory(const std::string &directory,
                   std::vector<std::string> &output)
{

    for (int i = 0; i < 100; ++i)
    {

        std::string full_path = directory + "pr_id" + std::to_string(i) + ".txt";

        std::ifstream f;
        f.open(full_path);

        if (!f.good())
        {
            std::cout << "not existing file path: " << full_path << std::endl;
            f.close();
            return;
        }
        else
            output.push_back(full_path);

        f.close();
    }
}

int color_id = 3;

void DrawGraph(const PRFileFormat &data)
{

    auto mg = new TMultiGraph(data.graph_label.c_str(), data.graph_label.c_str());
    mg->SetTitle(std::string(data.graph_label + ';' + data.x_axis_name + ';' + data.y_axis_name).c_str());

    for (int label_id = 0; label_id < data.datasets_labels.size(); label_id++)
    {
        auto graph = (new TGraph());
        graph->SetName(data.datasets_labels[label_id].c_str());
        graph->SetTitle(data.datasets_labels[label_id].c_str());
        graph->SetMarkerStyle(22);
        graph->SetDrawOption("LP");
        graph->SetLineColor(color_id++);
        graph->SetLineWidth(4);
        graph->SetFillStyle(0);

        for (int i = 0; i < data.arguments.size(); i++)
        {
            graph->SetPoint(i, (double)data.arguments[i], data.values[i][label_id]);
        }
        mg->Add(graph, "PL");
    }

    auto c = new TCanvas(data.graph_label.c_str(), data.graph_label.c_str(), 200, 10, 1080, 720);
    mg->Draw("A pmc plc");
    c->BuildLegend();

    auto out_file = new TFile(std::string("C:\\Users\\piotr\\Documents\\CoA\\testing\\pr_directory\\" + data.graph_label + ".root").c_str(), "RECREATE");

    // Write the histogram in the file
    mg->Write();
}

void AddSpace(std::string &text)
{
    for (auto &t : text)
        if (t == '-')
            t = ' ';
}

#define LOG_VAR(x) std::cout << #x << "=>" << x << std::endl;

void PRFileFormat::Load(std::string path)
{
    std::ifstream f(path, std::ios::in);

    if (f.bad())
    {
        f.close();
        throw "bad file path";
    }
    std::getline(f, graph_label);

    AddSpace(graph_label);
    std::getline(f, x_axis_name);
    AddSpace(x_axis_name);
    std::getline(f, y_axis_name);
    AddSpace(y_axis_name);

    int datasets_count;
    f >> datasets_count;

    int values_count;
    f >> values_count;
    std::string label;
    std::getline(f, label, '\t');

    for (int i = 0; i < datasets_count; i++)
    {
        std::getline(f, label, '\t');
        AddSpace(label);
        datasets_labels.push_back(label);
    }

    for (int i = 0; i < values_count; ++i)
    {
        int arg;
        f >> arg;
        arguments.push_back(arg);
        std::vector<double> buffer;

        for (int v = 0; v < datasets_count; v++)
        {
            double val;
            f >> val;
            buffer.push_back(val);
        }
        values.push_back(buffer);
    }

    f.close();
}
