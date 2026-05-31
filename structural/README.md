# Structural Design Patterns Notes

## Notes

Structural patterns are concerned with **how classes and objects are composed to form larger structures**.

Structural **class** patterns use **inheritance** to compose interfaces or implementations.

Structural **object** patterns describe ways to compose objects to realize new functionality. They leverage **composition** because it generates runtime flexibility.

## Overview

| Pattern Name | Scope        | Brief Description                                                                                     |
| ------------ | ------------ | ----------------------------------------------------------------------------------------------------- |
| Adapter      | Class/Object | converts the interface of a class into the interface a client expects                                 |
| Bridge       | Object       | abstraction-implementation decoupling so that they can vary independently                             |
| Composite    | Object       | tree structures to represent part-whole hierarchies; individuals and composites are treated the same  |
| Decorator    | Object       | dynamically attach additional responsibilities to objects                                             |
| Facade       | Object       | provide a unified interface to a set of interfaces in a subsystem                                     |
| Flyweight    | Object       | use sharing to support a large number of fine-grained objects efficiently                             |
| Proxy        | Object       | provide a placeholder for another object to control access to it                                      |