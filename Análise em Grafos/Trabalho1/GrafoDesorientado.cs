using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Trabalho1
{
    public class GrafoDesorientado : Grafo
    {
        public string AddArestaDesorientado(string Key, string Value)
        {
            if (arestas.ContainsKey(Value) && arestas[Value].Contains(Key) ||
            arestas.ContainsKey(Key) && arestas[Key].Contains(Value)) return "Essa aresta já existe";

            arestas[Key].Add(Value);
            return "Aresta adicionada com sucesso!";
        }

        public string RemoveArestaDesorientado(string Key, string Value)
        {
            if (arestas.ContainsKey(Key) && arestas[Key].Contains(Value))
            {
                arestas[Key].Remove(Value);
                return "Aresta removida com sucesso";
            }
            else if (arestas.ContainsKey(Value) && arestas[Value].Contains(Key))
            {
                arestas[Value].Remove(Key);
                return "Aresta removida com sucesso";
            }
            else
            {
                return "Essa aresta não existe.";
            }
        }

        public string verificaArestaDesorientado(string Key, string Value)
        {
            return (arestas.ContainsKey(Key) && arestas[Key].Contains(Value)) ||
                   (arestas.ContainsKey(Value) && arestas[Value].Contains(Key))
                  ? "A aresta pertence ao grafo."
                  : "A aresta não pertence ao grafo.";
        }

        public List<string> VerticesAdjacentesDesorientado(string Value) // O(N) * O(M)
        {
            List<string> adjacentes = new List<string>();
            foreach (var x in arestas)
            {
                if (x.Value.Contains(Value))
                {
                    adjacentes.Add(x.Key);
                }
                if (x.Key == Value)
                {
                    foreach (var y in x.Value)
                    {
                        adjacentes.Add(y);
                    }
                }
            }

            return adjacentes;
        }

        public List<string> VerticesIncidentesDesorientado(string Value) // O(N) * O(M)
        {
            List<string> incidentes = new List<string>();
            foreach (var x in arestas)
            {
                if (x.Value.Contains(Value))
                {
                    incidentes.Add(x.Key);
                }
                if (x.Key == Value)
                {
                    foreach (var y in x.Value)
                    {
                        incidentes.Add(y);
                    }
                }
            }

            return incidentes;
        }

        public GrafoDesorientado GrafoTransposto() // O(N²)
        {
            GrafoDesorientado transposto = new GrafoDesorientado();
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

        public GrafoDesorientado GrafoComplemento() // O(N²)
        {
            GrafoDesorientado complemento = new GrafoDesorientado();

            foreach (var x in arestas)
            {
                complemento.arestas[x.Key] = new List<string>();
            }

            foreach (var x in arestas)
            {
                foreach (var y in arestas)
                {
                    if (!y.Value.Contains(x.Key) && x.Key != y.Key)
                    {
                        if (!arestas[x.Key].Contains(y.Key))
                        {
                            if (!complemento.arestas[y.Key].Contains(x.Key))
                            {
                                complemento.arestas[x.Key].Add(y.Key);
                            }
                        }
                    }
                }
            }

            return complemento;
        }

        public void MostraGrafoDesorientado() // O(N²)
        {
            foreach (var x in arestas)
            {
                Console.WriteLine("Chave " + x.Key);
                foreach (var y in x.Value)
                    Console.WriteLine(x.Key + " --- " + y);
            }
        }

    }
}