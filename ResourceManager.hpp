#pragma once
#include<iostream>
#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* res = nullptr;                          
public:
    // konstruktor domy�lny
    
    ResourceManager()
    {
        res = new Resource(); //konstruktor
    };

    ~ResourceManager()
    {
        delete res; // destruktor
    };

    double get()
    {
        return res -> get(); // wywo�anie metody get na obiekcie Resouce i zwr�cenie warto�ci
     };

    // konstruktor kopiuj�cy
    ResourceManager(const ResourceManager& copy) 
    {
        res = new Resource(*copy.res); /* tworzy nowy obiekt typu Resouce na podstawie obiektu
                                          res zawartego w zmiennej copy, gwiazdka przy copy.res
                                          oznacza odwo�anie si� do obiektu do kt�rego mamy wska�nik,
                                          bo copy.res jest wska�nikiem na obiekt typu Resource*/
        
    };

    // operator = kopiuj�cy - zwraca referencje do obiektu 
    ResourceManager& operator=(const ResourceManager& copy)
    {               
        delete res; // usuwamy stary obiekt zapisany w res �eby nie by�o wyciek�w pami�ci.
        res = new Resource(*copy.res); // tworzymy nowy obiekt res na podstawie kopiowane
        return *this; // zwraca referencje do samego siebie. 
    }

    // konstruktor przenosz�cy
    ResourceManager(ResourceManager&& move) //&& - przekazujemy jako argument referencja r-value
                                              
    {
        res = move.res; 
        move.res = nullptr; 
    }

    // operator przenosz�cy - zwraca referencje do obiektu=
    ResourceManager& operator=(ResourceManager&& move) /*r-value tak jak wy�ej*/
    {
        delete res;        // usuwama star� zwarto�� res
        res = move.res; //  do wska�nika res przypusuje zawarto�� wska�nika z obiektu kt�ry
                           
        move.res = nullptr; 
                               
        return *this; // zwraca referencje do samego siebie. 
    }
};