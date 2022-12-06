#pragma once
#include<iostream>
#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* res = nullptr;                          
public:
    // konstruktor domyœlny
    
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
        return res -> get(); // wywo³anie metody get na obiekcie Resouce i zwrócenie wartoœci
     };

    // konstruktor kopiuj¹cy
    ResourceManager(const ResourceManager& copy) 
    {
        res = new Resource(*copy.res); /* tworzy nowy obiekt typu Resouce na podstawie obiektu
                                          res zawartego w zmiennej copy, gwiazdka przy copy.res
                                          oznacza odwo³anie siê do obiektu do którego mamy wskaŸnik,
                                          bo copy.res jest wskaŸnikiem na obiekt typu Resource*/
        
    };

    // operator = kopiuj¹cy - zwraca referencje do obiektu 
    ResourceManager& operator=(const ResourceManager& copy)
    {               
        delete res; // usuwamy stary obiekt zapisany w res ¿eby nie by³o wycieków pamiêci.
        res = new Resource(*copy.res); // tworzymy nowy obiekt res na podstawie kopiowane
        return *this; // zwraca referencje do samego siebie. 
    }

    // konstruktor przenosz¹cy
    ResourceManager(ResourceManager&& move) //&& - przekazujemy jako argument referencja r-value
                                              
    {
        res = move.res; 
        move.res = nullptr; 
    }

    // operator przenosz¹cy - zwraca referencje do obiektu=
    ResourceManager& operator=(ResourceManager&& move) /*r-value tak jak wy¿ej*/
    {
        delete res;        // usuwama star¹ zwartoœæ res
        res = move.res; //  do wskaŸnika res przypusuje zawartoœæ wskaŸnika z obiektu który
                           
        move.res = nullptr; 
                               
        return *this; // zwraca referencje do samego siebie. 
    }
};