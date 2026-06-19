# Singleton Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Ensure a class has one instance, and provide a global access point to it.

## Applicability

- there must be a unique, accessible instance of a class
- when a sole instance must be extensible by subclassing, and clients should be able to use an extended instance without modifying their code

## Consequences

- strict control over how and when clients access the singleton instance
- avoids polluting the global namespace
- allows reconfiguring the instance with any of its extension at runtime
- allows storing a variable number of instances if needed
- it is more flexible than defining static operations 

## Implementation Issues

- instantiation moment can be hidden behind a class operation by means of lazy initialization (`getInstance()`)
- some constraints we should enforce on clients:
  - guarantee no one tries to declare the same static object more than once
  - we may need more information than we have access to at initialization time
  - (`C++`) never create dependencies between singletons - there is no defined order of calling constructors across different translation units
- instantiating the unique instance with a subclass of the `Singleton`:
  - use a `Factory` and get the required type from there - link-time/compile-time solution
  - registry of singletons - define a list/map of available singletons identified by index/name; add a `Register(name, singleton)` static method in the `Singleton` class - singletons register themselves in the constructor (the `Singleton` class becomes responsible for granting access to the desired unique instance); instance creation must be triggered to be registered