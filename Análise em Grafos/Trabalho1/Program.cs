// See https://aka.ms/new-console-template for more information
using System.IO;
using Trabalho1;

string arquivo = "grafo1.TXT";

Grafo grafo = new Grafo();

using (StreamReader sr = File.OpenText(arquivo))
{
    string linha = sr.ReadLine();
    while (!sr.EndOfStream)
    {
        linha = sr.ReadLine();
        grafo.AddVertice(linha.Substring(0, 1));
    }
}

using (StreamReader sr = File.OpenText(arquivo))
{
    string linha = sr.ReadLine();
    while (!sr.EndOfStream)
    {
        linha = sr.ReadLine();
        grafo.AddDoArquivo(linha.Substring(0, 1), linha.Substring(2, 1));
    }
}


string[,] matriz = grafo.RetornaMatriz();

for (int i = 0; i < matriz.GetLength(0); i++)
{
    for (int j = 0; i < matriz.GetLength(1); i++)
    {
        Console.WriteLine(matriz[i, j]);
    }
}

Console.WriteLine("oi");


