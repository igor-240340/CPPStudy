export module datamodel;         // Модуль datamodel.

export import datamodel.person;  // Импортируем и экспортируем подмодуль person.
export import datamodel.address; // Импортируем и экспортируем подмодуль address.

import std;

export namespace DataModel { using Persons = std::vector<Person>; }
