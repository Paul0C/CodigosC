using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Trabalho1
{
    public class Grafo
    {
        public Dictionary<string, List<string>> arestas { get; set; }

        public Grafo()
        {
            arestas = new Dictionary<string, List<string>>();
        }

        public void AddVertice(string Key)
        {
            arestas[Key] = new List<string>();
        }
        public void AddDoArquivo(string Key, string Value)
        {
            arestas[Key].Add(Value);
        }

        public string RemoveVertice(string vertice)
        {
            if (!arestas.ContainsKey(vertice)) return "Não existe esse vértice no grafo.";
            arestas.Remove(vertice);
            return "Vértice removido com sucesso!";
        }

        public string AddAresta(string Key, string Value)
        {
            if (arestas[Key].Contains(Value)) return "Essa aresta já existe";

            arestas[Key].Add(Value);
            return "Aresta adicionada com sucesso!";
        }

        public string RemoveAresta(string Key, string Value)
        {
            if (arestas[Key].Contains(Value))
            {
                arestas[Key].Remove(Value);
                return "Aresta removida com sucesso";
            }
            else
            {
                return "Essa aresta não existe.";
            }
        }

        public void MostraGrafo()
        {
            foreach (var x in arestas)
                foreach (var y in x.Value)
                    Console.WriteLine(y);
        }

        public string[,] RetornaMatriz()
        {
            string[,] Matriz = new string[arestas.Count, arestas.Count];
            return Matriz;
        }

        public string verificaAresta(string Key, string Value)
        {
            return arestas[Key].Contains(Value)
                  ? "A aresta pertence ao grafo,"
                  : "A aresta não pertence ao grafo.";
        }

        public string[] VerticesAdjacentes(string Key)
        {
            if (!arestas.ContainsKey(Key)) return null;
            string[] adjacentes = arestas[Key].ToArray();
            return adjacentes;
        }

        public string VerticesIncidentes(string Value)
        {
            string incidentes = " ";
            foreach (var x in arestas)
            {
                if (arestas[x.Key].Contains(Value))
                {
                    incidentes.Concat(Value);
                }
            }

            return incidentes;
        }


    }
}