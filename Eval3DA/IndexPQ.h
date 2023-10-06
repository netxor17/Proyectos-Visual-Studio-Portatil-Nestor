/**
 * Implementaci�n de colas con prioridad mediante mont�culos.
 * Los elementos son enteros de 0 a N-1 que tienen asociada una prioridad
 * dentro de la cola. La prioridad de un elemento puede ser modificada
 * con coste en O(log N).
 *
 * Copyright (c) 2020 Alberto Verdejo
 * Modificado por 2023 Ignacio F�bregas
 */

#ifndef INDEXPQ_H_
#define INDEXPQ_H_

#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>

using namespace std;

// T es el tipo de las prioridades
// Comparator dice cu�ndo un valor de tipo T es m�s prioritario que otro
template <typename H, typename T = int, typename Comparator = std::less<T>>
class IndexPQ {

public:
    // Registro para las parejas < elem, prioridad >
    struct Par {
        H elem;
        T prioridad;
    };

private:
    // vector que contiene los datos (pares < elem, prioridad >)
    std::vector<Par> array;      // El primer elemento est� en la posici�n 1

    // vector que contiene las posiciones en array de los elementos
    unordered_map<H, int> posiciones;   // un 0 indica que el elemento no est�

    /* Objeto funci�n que sabe comparar elementos.
     * antes(a,b) es cierto si a es m�s prioritario que b (a debe salir antes que b)
     */
    Comparator antes;

public:
    IndexPQ(Comparator c = Comparator()) : array(1), antes(c) {}

    IndexPQ(IndexPQ<H, T, Comparator> const&) = default;

    IndexPQ<H, T, Comparator>& operator=(IndexPQ<H, T, Comparator> const&) = default;

    ~IndexPQ() = default;

    // e debe ser uno de los posibles elementos
    void push(H e, T const& p) {
        if (posiciones.count(e) != 0)
            throw std::invalid_argument("No se pueden insertar elementos repetidos.");
        else {
            array.push_back({ e, p });

            posiciones[e] = size();
            flotar(size());
        }
    }

    // Actualizar la prioridad del elemento e
    void update(int e, T const& p) {
        int i = posiciones.at(e); //CUAIDO
        if (i == 0) // el elemento e se inserta por primera vez
            push(e, p);
        else {
            array[i].prioridad = p;
            if (i != 1 && antes(array[i].prioridad, array[i / 2].prioridad))
                flotar(i);
            else // puede hacer falta hundir a e
                hundir(i);
        }
    }

    //UPDATE 2 
    void update2(H e, T const& p) {
        if (posiciones.count(e) == 0) // el elemento e se inserta por primera vez
            push(e, p);
        else {
            int i = posiciones.at(e); //

            array[i].prioridad.first += p.first; //actualizo la prioridad
            array[i].prioridad.second = p.second;
            if (i != 1 && antes(array[i].prioridad, array[i / 2].prioridad))
                flotar(i);
            else // puede hacer falta hundir a e
                hundir(i);
        }
    }


    int size() const {
        return int(array.size()) - 1;
    }

    bool empty() const {
        return size() == 0;
    }

    Par const& top() const {
        if (size() == 0)
            throw std::domain_error("No se puede consultar el primero de una cola vacia");
        else return array[1];
    }

    void pop() {
        if (size() == 0) throw std::domain_error("No se puede eliminar el primero de una cola vacia.");
        else {
            posiciones.erase(array[1].elem);
            //posiciones[array[1].elem] = 0; // para indicar que no está
            if (size() > 1) {
                array[1] = std::move(array.back());
                posiciones[array[1].elem] = 1;
                //posiciones.insert(array[1].elem,1);
                array.pop_back();
                hundir(1);
            }
            else
                array.pop_back();
        }
    }

    /* Escritura del mont�culo. M�todo para depurar */
    void print() {
        std::cout << "[";
        for (int i = 1; i < array.size() - 1; i++)
            std::cout << array[i] << ", ";
        std::cout << array[array.size() - 1] << "]" << std::endl;
    }

private:

    void flotar(int i) {
        Par parmov = std::move(array[i]);
        int hueco = i;
        while (hueco != 1 && antes(parmov.prioridad, array[hueco / 2].prioridad)) {
            array[hueco] = std::move(array[hueco / 2]); posiciones[array[hueco].elem] = hueco;
            hueco /= 2;
        }
        array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
    }

    void hundir(int i) {
        Par parmov = std::move(array[i]);
        int hueco = i;
        int hijo = 2 * hueco; // hijo izquierdo, si existe
        while (hijo <= size()) {
            // cambiar al hijo derecho de i si existe y va antes que el izquierdo
            if (hijo < size() && antes(array[hijo + 1].prioridad, array[hijo].prioridad))
                ++hijo;
            // flotar el hijo si va antes que el elemento hundi�ndose
            if (antes(array[hijo].prioridad, parmov.prioridad)) {
                array[hueco] = std::move(array[hijo]); posiciones[array[hueco].elem] = hueco;
                hueco = hijo; hijo = 2 * hueco;
            }
            else break;
        }
        array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
    }

};

#endif /* INDEXPQ_H_ */