using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Trabalho1
{
    public abstract class Grafo
    {
        public Dictionary<string, List<string>> arestas { get; set; }

        public Grafo()
        {
            arestas = new Dictionary<string, List<string>>();
        }

        public void AddVertice(string Key)
        {
            if (!arestas.ContainsKey(Key)) { arestas[Key] = new List<string>(); }
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

        public int[,] RetornaMatriz() // O(N³)
        {
            var ordenado = arestas.OrderBy(x => x.Key);
            var ordenadoArray = ordenado.ToArray();

            int[,] Matriz = new int[arestas.Count, arestas.Count];

            for (int i = 0; i < arestas.Count; i++)
            {
                ordenadoArray[i].Value.ToArray();
                for (int j = 0; j < ordenadoArray[i].Value.Count; j++)
                {
                    if (ordenadoArray[i].Value[j].Any())
                    {
                        for (int k = 0; k < ordenadoArray.Length; k++)
                        {
                            if (ordenadoArray[k].Key == ordenadoArray[i].Value[j])
                            {
                                Matriz[i, k] = 1;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < arestas.Count; i++)
            {
                for (int j = 0; j < arestas.Count; j++)
                {
                    Console.Write(Matriz[i, j] + " ");
                }
                Console.WriteLine();
            }

            return Matriz;
        }

        public void CompletaVertice() // O(N²)
        {
            foreach (var x in arestas.ToList())
            {
                foreach (var y in x.Value)
                {
                    if (!arestas.ContainsKey(y))
                    {
                        arestas[y] = new List<string>();
                    }
                }
            }
        }


    }
}