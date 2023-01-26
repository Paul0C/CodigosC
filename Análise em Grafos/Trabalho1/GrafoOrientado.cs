using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Trabalho1
{
    public class GrafoOrientado : Grafo
    {
        public string AddArestaOrientado(string Key, string Value)
        {
            if (arestas.ContainsKey(Key) && arestas[Key].Contains(Value)) return "Essa aresta já existe";

            arestas[Key].Add(Value);
            return "Aresta adicionada com sucesso!";
        }

        public string RemoveArestaOrientado(string Key, string Value)
        {
            if (arestas.ContainsKey(Key) && arestas[Key].Contains(Value))
            {
                arestas[Key].Remove(Value);
                return "Aresta removida com sucesso";
            }
            else
            {
                return "Essa aresta não existe.";
            }
        }

        public string verificaArestaOrientado(string Key, string Value)
        {
            return arestas[Key].Contains(Value)
                  ? "A aresta pertence ao grafo,"
                  : "A aresta não pertence ao grafo.";
        }

        public List<string> VerticesAdjacentesOrientado(string Key) // O(N)
        {
            if (!arestas.ContainsKey(Key)) return null;
            List<string> adjacentes = arestas[Key].ToList();
            return adjacentes;
        }

        public List<string> VerticesIncidentesOrientado(string Value) // O(N)
        {
            List<string> incidentes = new List<string>();
            foreach (var x in arestas)
            {
                if (x.Value.Contains(Value))
                {
                    incidentes.Add(x.Key);
                }
            }

            return incidentes;
        }

        public GrafoOrientado GrafoTransposto() // O(N²)
        {
            GrafoOrientado transposto = new GrafoOrientado();
            foreach (var x in arestas)
            {
                foreach (var y in x.Value)
                {
                    if (!transposto.arestas.ContainsKey(y))
                    {
                        transposto.arestas[y] = new List<string>();
                        transposto.arestas[y].Add(x.Key);
                    }
                    else
                    {
                        transposto.arestas[y].Add(x.Key);
                    }
                }
            }

            return transposto;

        }

        public GrafoOrientado GrafoComplemento() // O(N²)
        {
            GrafoOrientado complemento = new GrafoOrientado();

            foreach (var x in arestas)
            {
                complemento.arestas[x.Key] = new List<string>();
            }

            foreach (var x in arestas)
            {
                foreach (var y in arestas)
                {
                    if (!x.Value.Contains(y.Key) && x.Key != y.Key)
                    {
                        complemento.arestas[x.Key].Add(y.Key);
                    }
                }
            }

            return complemento;
        }

        public void MostraGrafoOrientado() // O(N²)
        {
            foreach (var x in arestas)
            {
                Console.WriteLine("Chave " + x.Key);
                foreach (var y in x.Value)
                    Console.WriteLine(x.Key + " => " + y);
            }
        }



    }
}