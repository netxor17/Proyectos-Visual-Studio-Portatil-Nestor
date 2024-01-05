/*
 * Implementaci�n de estructuras de partici�n (o conjuntos disjuntos)
 * con uni�n por tama�o y compresi�n de caminos
 * Copyright (c) 2020  Alberto Verdejo
 * Modificado por 2023 Ignacio F�bregas
 */

#ifndef CONJUNTOSDISJUNTOS_H_
#define CONJUNTOSDISJUNTOS_H_

#include <vector>
#include <unordered_map>
#include <iostream>

class ConjuntosDisjuntos {
protected:
    int ncjtos;  // n�mero de conjuntos disjuntos
    mutable std::vector<int> p;  // enlace al padre. El atributo es mutable incluso en m�todos constantes
    std::vector<int> tam;  // tama�o de los �rboles
public:

    // crea una estructura de partici�n con los elementos 0..N-1,
    // cada uno en un conjunto, partici�n unitaria
    ConjuntosDisjuntos(int N) : ncjtos(N), p(N), tam(N, 1) {
        for (int i = 0; i < N; ++i)
            p[i] = i;
    }

    //  devuelve el representante del conjunto que contiene a a
    int buscar(int a) const {
        if (p.at(a) == a) // es una ra�z
            return a;
        else
            return p[a] = buscar(p[a]);
    }

    // unir los conjuntos que contengan a y b
    void unir(int a, int b) {
        int i = buscar(a);
        int j = buscar(b);
        if (i == j) return;
        if (tam[i] > tam[j]) { // i es la ra�z del �rbol m�s grande
            tam[i] += tam[j]; p[j] = i;
        }
        else {
            tam[j] += tam[i]; p[i] = j;
        }
        --ncjtos;
    }

    // devuelve si a y b est�n en el mismo conjunto
    bool unidos(int a, int b) const {
        return buscar(a) == buscar(b);
    }

    // devuelve el n�mero de elementos en el conjunto de a
    int cardinal(int a) const {
        return tam[buscar(a)];
    }

    // devuelve el n�mero de conjuntos disjuntos
    int num_cjtos() const { return ncjtos; }

    // escritura para depurar
    void print() {
        std::unordered_map<int, std::vector<int>> aux;
        clases(aux);
        bool primero = true;
        for (auto& x : aux) {
            std::cout << (primero ? "" : ", ");
            primero = false;
            std::cout << "{";
            std::cout << x.first;
            for (auto& y : x.second)
                std::cout << ", " << y;
            std::cout << "}";
        }
        std::cout << "\n";
    }

private:
    // Para mostrar las clases de equivalencia
    // aux es un diccionario con representante -> elementos en su clase
    void clases(std::unordered_map<int, std::vector<int>>& aux) {
        for (int i = 0; i < p.size(); ++i) {
            int r = buscar(p[i]); // representante
            if (aux.count(r) == 0)
                aux[r] = {};
            if (r != i)
                aux[r].push_back(i);  //a�adimos la x a su grupo
        }
    }

};

#endif