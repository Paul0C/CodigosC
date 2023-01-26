// See https://aka.ms/new-console-template for more information
using System.IO;
using Trabalho1;

string arquivo = "grafo2.TXT";



using (StreamReader sr = File.OpenText(arquivo))
{
    string linha = sr.ReadLine();

    if (linha == "undirected")
    {
        GrafoDesorientado grafo = new GrafoDesorientado();

        while (!sr.EndOfStream)
        {
            linha = sr.ReadLine();
            grafo.AddVertice(linha.Substring(0, 1));
            grafo.AddDoArquivo(linha.Substring(0, 1), linha.Substring(2, 1));
        }

        grafo.CompletaVertice();
    }
    else
    {
        GrafoOrientado grafo = new GrafoOrientado();

        while (!sr.EndOfStream)
        {
            linha = sr.ReadLine();
            grafo.AddVertice(linha.Substring(0, 1));
            grafo.AddDoArquivo(linha.Substring(0, 1), linha.Substring(2, 1));
        }

        grafo.CompletaVertice();
    }
}






