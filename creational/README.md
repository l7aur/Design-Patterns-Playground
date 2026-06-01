# Creational Design Patterns Notes

## Notes

Creational design patterns abstract the instantiation process. They help in making a system independent of how its objects are created, composed, and represented. Creational **class** patterns use inheritance to vary the object that is instantiated, while **object** creational patterns delegate the responsibility to another object.

Creational patterns become important as systems shift from inheritance to object composition. As this happens, the emphasis moves from hardcoding behaviors toward defining a small set of fundamental and reusable behaviors that can be composed to form more complex ones.

There are two recurring themes:
1. they all encapsulate knowledge about what are the concrete classes the client uses.
2. they all hide how concrete classes are instantiated.

All the client knows are product interfaces, hence there is a lot of flexibility in **what** gets created, **who** creates it, **how** it is created, and **when**. Product configuration can be static or dynamic.

## Overview

| Pattern Name     | Scope  | Brief Description                                                                                                                |
| ---------------- | ------ | -------------------------------------------------------------------------------------------------------------------------------- |
| Abstract Factory | Object | provides an interface for creating families of related/dependent objects without specifying concrete classes                     |
| Builder          | Object | separate construction of a complex object from its representation, so that the same process can create different representations |
| Factory Method   | Class  | define an interface for creating an object, but let subclasses decide which class to instantiate (defer responsibility)          |
| Prototype        | Object | specify the kinds of objects to create by means of copying the provided prototype                                                |
| Singleton        | Object | ensure a class has only one instance                                                                                             |